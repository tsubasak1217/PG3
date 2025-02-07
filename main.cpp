#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>

std::mutex mtx;
std::atomic<bool> loadingFinished(false);

// ANSIエスケープコードを使って画面のカーソルを左上に移動（チラつきを防ぐ）
void MoveCursorTopLeft(){
    std::cout << "\x1b[H";  // ANSIエスケープシーケンスでカーソルを左上へ
}

int main(){
    std::vector<std::vector<int>> mapChip;

    // バックグラウンドでCSVファイルを読み込むスレッド
    std::thread th([&](){
        std::ifstream ifs("mapChip.csv");
        if(!ifs){
            std::cerr << "Failed to open map.csv\n";
            return;
        }

        std::string line;
        std::vector<std::vector<int>> tempMap; // 一時バッファ

        while(std::getline(ifs, line)){
            std::vector<int> chip;
            std::istringstream iss(line);
            std::string str;
            while(std::getline(iss, str, ',')){
                chip.push_back(std::stoi(str));
            }
            tempMap.push_back(chip);
        }

        // データの競合を防ぐためにロック
        {
            std::lock_guard<std::mutex> lock(mtx);
            mapChip.swap(tempMap); // 一時バッファと入れ替え
        }

        loadingFinished = true; // ロード完了フラグを設定
        });

    // ゲームループ
    while(true){
        MoveCursorTopLeft();  // カーソルを左上に移動（チラつきを防ぐ）

        std::ostringstream buffer;  // 描画バッファ

        if(loadingFinished){
            std::lock_guard<std::mutex> lock(mtx);

            for(const auto& row : mapChip){
                for(int cell : row){
                    buffer << (cell == 1 ? "□" : " ");
                }
                buffer << '\n';
            }
        }

        std::cout << buffer.str();  // バッファに溜めた描画内容を一気に出力

        // CPU負荷を下げるために少し待機
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    th.join(); // スレッドの終了を待つ
    return 0;
}
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int currentThread = 0; // 現在出力すべきスレッド番号

void threadFunction(int threadID, int numThreads){
    std::unique_lock<std::mutex> lock(mtx);

    // 自分のスレッド番号が現在のターンになるまで待機
    cv.wait(lock, [&]() { return threadID == currentThread; });

    // スレッド番号を出力
    printf("thread %d\n", threadID);

    // 次のスレッド番号を設定して通知
    currentThread++;
    cv.notify_all();
}

int main(){
    // スレッド数の設定
    const int numThread = 3;
    std::thread threads[numThread];

    // スレッドの生成
    for(int i = 0; i < numThread; ++i) {
        threads[i] = std::thread(threadFunction, i, numThread);
    }

    // スレッドの終了を待機
    for(int i = 0; i < numThread; ++i) {
        threads[i].join();
    }

    return 0;
}

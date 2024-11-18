#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// 余分な文字を削除する
void CleanUpString(std::string& str, const std::string& charsToRemove){
	for(char ch : charsToRemove) {
		str.erase(std::remove(str.begin(), str.end(), ch), str.end());
	}
}

// カンマ区切りで格納する
void LoadFile(std::vector<std::string>& mailAddress, std::string fileName){

	std::ifstream file;
	file.open(fileName);

	std::string line;
	while(std::getline(file, line, ',')) {
		CleanUpString(line, "[]\"");
		mailAddress.push_back(line);
	}

	file.close();

}

// メールアドレスから数値部分を抽出する関数
int ExtractNumber(const std::string& email){
	std::size_t gPos = email.find('g'); // 'g'の位置を探す
	if(gPos != std::string::npos && gPos + 4 < email.size()) {
		return std::stoi(email.substr(gPos + 1, 4)); // 'g'の次の4文字を数値に変換
	}
	return -1; // 数値が見つからない場合のデフォルト値
}


// 数値部分に基づいてソート
void Sort(std::vector<std::string>& mailAddress){
	std::sort(mailAddress.begin(), mailAddress.end(), [](const std::string& a, const std::string& b) {
		return ExtractNumber(a) < ExtractNumber(b);
	});
}


int main(){ //開く

	std::vector<std::string> mailAddress;

	// 読み込み・ソート
	LoadFile(mailAddress, "PG3_2024_03_02.txt");
	Sort(mailAddress);

	// 出力
	for(auto& address : mailAddress){
		printf("%s\n", address.c_str());
	}

	return 0;

} //閉じる
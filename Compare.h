#pragma once
#include <stdio.h>
#include <type_traits>
#include <format>
#include "Virtual.h"

template <typename T1, typename T2>

class Compare : public VirtualCompare{
public:
	Compare() = default;
	Compare(T1 num1, T2 num2) : num1_(num1), num2_(num2){}
	~Compare()override = default;

	auto Min();
	void PrintMin()override;

private:
	T1 num1_;
	T2 num2_;
};


/// <summary>
/// ¬‚³‚¢‚Ù‚¤‚ğ•Ô‚·ŠÖ”
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T1, typename T2>
inline auto Compare<T1, T2>::Min(){
	return num1_ <= num2_ ? num1_ : num2_;
}



/// <summary>
/// ¬‚³‚¢‚Ù‚¤‚ğo—Í‚·‚éŠÖ”
/// </summary>
/// <typeparam name="T1"></typeparam>
/// <typeparam name="T2"></typeparam>
template<typename T1, typename T2>
inline void Compare<T1, T2>::PrintMin(){
	std::string output = std::format("num1 {} : num2 {} // Min = {} \n", num1_, num2_, Min());
	printf(output.c_str());
}


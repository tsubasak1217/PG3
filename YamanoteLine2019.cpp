#include "YamanoteLine2019.h"

YamanoteLine2019::YamanoteLine2019() : YamanoteLine1970(){
	name = "----------------- 2019 -------------------";
	auto it = stations.begin();
	std::advance(it, 7);
	stations.insert(it, "Nishi-Nippori");
}
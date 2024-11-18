#include "YamanoteLine2022.h"

YamanoteLine2022::YamanoteLine2022() : YamanoteLine2019(){
	name = "----------------- 2022 -------------------";
	auto it = stations.begin();
	std::advance(it, 27);
	stations.insert(it, "Takanawa Gateway");
}

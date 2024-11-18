#include "BaseYamanoteLine.h"

BaseYamanoteLine::BaseYamanoteLine(){
	name = "Base Yamanote Line";
	stations.clear();
}

void BaseYamanoteLine::Output(){

	printf("%s\n", name);

	for(auto& station : stations){
		printf("%s\n", station);
	}

	printf("\n");
}

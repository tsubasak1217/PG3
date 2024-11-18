#include "YamanoteLine1970.h"

YamanoteLine1970::YamanoteLine1970(){

	name = "----------------- 1970 -------------------";

	const char* station[] = {
	"Tokyo",
	"Kanda",
	"Akihabara",
	"Okashimashi",
	"Ueno",
	"Uguisudani",
	"Nippori",
	"Tabata",
	"Komagome",
	"Sugamo",
	"Otsuka",
	"Ikebukuro",
	"Mejiro",
	"Takadanobaba",
	"Shin-Okubo",
	"Shinjuku",
	"Yoyogi",
	"Harajuku",
	"Shibuya",
	"Ebisu",
	"Meguro",
	"Gotanda",
	"Osaki",
	"Shinagawa",
	"Tamachi",
	"Hamamatsucho",
	"Shimbashi",
	"Yurakusho",
	};

	stations.assign(std::begin(station), std::end(station));
}
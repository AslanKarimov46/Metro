#include "f.h"

std::vector<std::string> stations_red{
    "Академгородок",
    "Житомирская",
    "Святошин",
    "Нивки",
    "Берестейская",
    "Шулявская",
    "Политехнический институт",
    "Вокзальная",
    "Университет",
    "Театральная",
    "Крещатик",
    "Арсенальная",
    "Днепр",
    "Гидропарк",
    "Левобережная",
    "Дарница",
    "Черниговская",
    "Лесная"};

std::vector<int> RedLineTime;
    for(size_t i=1; i!=stations_red.size(); i++)
        RedLineTime.push_back(i);
	
std::vector<std::string> stations_blue{
    "Героев Днепра",
    "Минская",
    "Оболонь",
    "Петровка",
    "Тараса Шевченко",
    "Контрактовая площадь",
    "Почтовая площадь",
    "Площадь Независимости",
    "Крещатик",
    "Площадь Льва Толстого",
    "Олимпийская",
    "Дворец Украина",
    "Лыбедская",
    "Демиевская",
    "Голосеевская",
    "Васильковская",
    "Выставочный центр",
    "Ипподром",
    "Теремки"};

std::vector<int> BlueLineTime;
    for(size_t i=1; i!=stations_blue.size(); i++)
        RedLineTime.push_back(i);

std::vector<std::string> stations_green{
    "Сырец",
    "Дорогожичи",
    "Лукьяновская",
    "Золотые ворота",
    "Дворец спорта",
    "Кловская",
    "Печерская",
    "Дружбы Народов",
    "Выдубичи",
    "Теличка",
    "Славутич",
    "Осокорки",
    "Позняки",
    "Харьковская",
    "Бориспольская",
    "Красный хутор"};

std::vector<int> GreenLineTime;
    for(size_t i=1; i!=stations_green.size(); i++)
        RedLineTime.push_back(i);


void find_stations(std::string first, std::string second, std::pair<std::string, int>& index1, std::pair<std::string, int>& index2){
		
        for(size_t i=0; i!=stations_red.size(); i++){
			if(stations_red[i]==first){
				index1.second=i;
				index1.first="stations_red";
			}
			if(stations_red[i]==second){
				index2.second=i;
				index2.first="stations_red";
			}	
		}
		
        for(size_t i=0; i!=stations_green.size(); i++){
			if(stations_green[i]==first){
				index1.second=i;
				index1.first="stations_green";
			}
			if(stations_green[i]==second){
				index2.second=i;
				index2.first="stations_green";
			}	
		}
		
        for(size_t i=0; i!=stations_blue.size(); i++){
			if(stations_blue[i]==first){
				index1.second=i;
				index1.first="stations_blue";
			}
			if(stations_blue[i]==second){
				index2.second=i;
				index2.first="stations_blue";
			}	
		}
}

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

std::vector<int> RedLineTime{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
	
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

std::vector<int> BlueLineTime{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

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
    "Славутич",
    "Осокорки",
    "Позняки",
    "Харьковская",
    "Бориспольская",
    "Красный хутор"};

std::vector<int> GreenLineTime{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};


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

int route(std::string& FirstStation, std::string& SecondStation){
    int res_time=0;
    std::pair<std::string, int> Coord1, Coord2;
    find_stations(FirstStation, SecondStation, Coord1, Coord2);

    // Рассмотрим случаи когда мы путешествуем, только по 1ой ветке
    if(Coord1.first==Coord2.first){
        if(Coord1.second<=Coord2.second){
            for(int i=Coord1.second; i!=Coord2.second; i++){
                if(Coord1.first=="stations_red"){
                    std::cout<<res_time<<"\n"; 
                    res_time+=RedLineTime[i];
                    std::cout<<"RedLineTime["<<i<<"] = "<<RedLineTime[i]<<"\n";
                }
                if(Coord1.first=="stations_green"){
                    res_time+=GreenLineTime[i];
                    std::cout<<"GreenLineTime["<<i<<"] = "<<GreenLineTime[i]<<"\n";
                }
                if(Coord1.first=="stations_blue"){
                    res_time+=BlueLineTime[i];
                    std::cout<<"BlueLineTime["<<i<<"] = "<<BlueLineTime[i]<<"\n";
                }
            }
        }else{
            for(int i=Coord1.second-1; i!=Coord2.second-1; i--){
                if(Coord1.first=="stations_red"){
                    res_time+=RedLineTime[i];
                    std::cout<<"RedLineTime["<<i<<"] = "<<RedLineTime[i]<<"\n";
                }
                if(Coord1.first=="stations_green"){
                    res_time+=GreenLineTime[i];
                    std::cout<<"GreenLineTime["<<i<<"] = "<<GreenLineTime[i]<<"\n";
                }
                if(Coord1.first=="stations_blue"){
                    res_time+=BlueLineTime[i];
                    std::cout<<"BlueLineTime["<<i<<"] = "<<BlueLineTime[i]<<"\n";
                }
            }
        }
    }else{  
    
        // Начинаем с красной
        
        if(Coord1.first=="stations_red"){
            // Идем на зеленую  
        
            if(Coord2.first=="stations_green"){
                // Идем на театральную
        
                if(Coord1.second<=9){ 
                    for(size_t i=Coord1.second-2; i!=9; i++){
                        res_time+=RedLineTime[i];
                        std::cout<<"RedLineTime["<<i<<"] = "<<RedLineTime[i]<<"\n";
                    }
                }else{
                    for(size_t i=Coord1.second-1; i!=8; i--){
                        res_time+=RedLineTime[i];
                        std::cout<<"RedLineTime["<<i<<"] = "<<RedLineTime[i]<<"\n";
                    }
                }

                // Переход с театральной на Золотые ворота потом куда надо
                if(Coord2.second<=3){
                    for(size_t i=Coord2.second; i!=3; i++){
                        res_time+=GreenLineTime[i];
                        std::cout<<"GreenLineTime["<<i<<"] = "<<RedLineTime[i]<<"\n";
                    }
                }else{
                    for(size_t i=Coord2.second-1; i!=2; i--){
                        res_time+=GreenLineTime[i];
                        std::cout<<"GreenLineTime["<<i<<"] = "<<RedLineTime[i]<<"\n";
                    }
                }

        
            }else{
                // та же ситуация расписывать лень
                if(Coord1.second<=9){ 
                    for(size_t i=Coord1.second-2; i!=10; i++){
                        res_time+=RedLineTime[i];
                        std::cout<<"RedLineTime["<<i<<"] = "<<RedLineTime[i]<<"\n";
                    }
                }else{
                    for(size_t i=Coord1.second-1; i!=9; i--){
                        res_time+=RedLineTime[i];
                        std::cout<<"RedLineTime["<<i<<"] = "<<RedLineTime[i]<<"\n";
                    }
                }

                if(Coord2.second<=7){
                    for(size_t i=Coord2.second; i!=7; i++){
                        res_time+=BlueLineTime[i];
                        std::cout<<"BlueLineTime["<<i<<"] = "<<BlueLineTime[i]<<"\n";
                    }
                }else{
                    for(size_t i=Coord2.second-2; i!=6; i--){
                        res_time+=BlueLineTime[i];
                        std::cout<<"BlueLineTime["<<i<<"] = "<<BlueLineTime[i]<<"\n";
                    }
                }
            }
        }


    }

    return res_time;
}
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
    "Театральная",										// Переход на зеленую линию
    "Крещатик",											// Переход на синюю линию 
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
    "Площадь Независимости",							// Переход на красную линюю
    "Площадь Льва Толстого",							// Переход на зеленую линюю
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
    "Золотые ворота",									// Переход на красную линию
    "Дворец спорта",									// Переход на синюю линюю
    "Кловская",
    "Печерская",
    "Дружбы Народов",
    "Выдубичи",
    "Славутич",
    "Осокорки",
    "Позняки",
    "Харьковская",
    "Вырлица",
    "Бориспольская",
    "Красный хутор"};

std::vector<int> GreenLineTime{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

int Red_to_Green=1, Red_to_Blue=5, Green_to_Blue=3;

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

        if(Coord1.first=="stations_red"){
            if( (Coord1.second<=9 && Coord2.second<=9) || (Coord1.second>=10 && Coord2.second>=10) ){
                for(int i=Coord1.second; i!=Coord2.second; i++){  
                    res_time+=RedLineTime[i];
                    std::cout<<"RedLineTime["<<i<<"]"<<RedLineTime[i]<<"\n";    
                }
                std::cout<<"\n";
            }else{
                if(Coord1.second<=9){
                    int a=GreenLineTime[3]+BlueLineTime[7]+Red_to_Green+Green_to_Blue+Red_to_Blue;
                    std::cout<<"a="<<a<<"\n";
                    std::cout<<"RedLineTime[9]="<<RedLineTime[9]<<"\n";
                    if(a>RedLineTime[9])
                        a=RedLineTime[9];
                    std::cout<<"a="<<a<<"\n";
                    res_time+=route(FirstStation, stations_red[9]);
                    std::cout<<"res_time="<<res_time<<"\n";
                    res_time+=a;
                    std::cout<<"res_time="<<res_time<<"\n";
                    res_time+=route(stations_red[10], SecondStation);
                    std::cout<<"res_time="<<res_time<<"\n";
                }else{ 
                    res_time=route(SecondStation, FirstStation);
                    std::cout<<"res_time="<<res_time<<"\n";
                } 
            }
        }

        if(Coord1.first=="stations_green"){
            if( (Coord1.second<=3 && Coord2.second<=3) || (Coord1.second>=4 && Coord2.second>=4) ){
                for(int i=Coord1.second; i!=Coord2.second; i++) 
                    res_time+=GreenLineTime[i];   
            }else{
                if(Coord1.second<=3){
                    int a=RedLineTime[9]+BlueLineTime[7]+Red_to_Green+Green_to_Blue+Red_to_Blue;
                    std::cout<<"a="<<a<<"\n";
                    std::cout<<"GreenLineTime[3]="<<GreenLineTime[3]<<"\n";
                    if(a>GreenLineTime[3])
                        a=GreenLineTime[3];
                    std::cout<<"a="<<a<<"\n";
                    res_time+=route(FirstStation, stations_green[3]);
                    std::cout<<"res_time="<<res_time<<"\n";
                    res_time+=a;
                    std::cout<<"res_time="<<res_time<<"\n";
                    res_time+=route(stations_green[4], SecondStation);
                    std::cout<<"res_time="<<res_time<<"\n";
                
                }else{
                    res_time=route(SecondStation, FirstStation);
                    std::cout<<"res_time="<<res_time<<"\n";
                }
            }
        }

        if(Coord1.first=="stations_blue"){
            if( (Coord1.second<=7 && Coord2.second<=7) || (Coord1.second>=8 && Coord2.second>=8) ){
                for(int i=Coord1.second; i!=Coord2.second; i++) 
                    res_time+=BlueLineTime[i];   
            }else{
                if(Coord1.second<=7){
                    int a=RedLineTime[9]+GreenLineTime[3]+Red_to_Green+Green_to_Blue+Red_to_Blue;
                    std::cout<<"a="<<a<<"\n";
                    std::cout<<"BlueLineTime[7]="<<BlueLineTime[7]<<"\n";
                    if(a>BlueLineTime[7])
                        a=GreenLineTime[3];
                    std::cout<<"a="<<a<<"\n";
                    res_time+=route(FirstStation, stations_blue[7]);
                    std::cout<<"res_time="<<res_time<<"\n";
                    res_time+=a;
                    std::cout<<"res_time="<<res_time<<"\n";
                    res_time+=route(stations_blue[8], SecondStation);
                    std::cout<<"res_time="<<res_time<<"\n";
                }
                else{
                res_time=route(SecondStation, FirstStation);
                std::cout<<"res_time="<<res_time<<"\n";
                }
            }
        }

    }
    else{  
    
        // Начинаем с красной
        
        if(Coord1.first=="stations_red"){ 

            if(Coord2.first=="stations_green"){

                if(Coord1.second<=9){
                    if(Coord2.second<=3){
                        res_time+=route(FirstStation, stations_red[9]);
                        res_time+=route(SecondStation, stations_green[3]);
                    }else{
                        res_time+=route(FirstStation, stations_red[9]);
                        res_time+=route(stations_green[3]), stations_green[4];
                        res_time+=route(stations_green[4], SecondStation);
                    }
                }else{
                    if(Coord2.second<=3){
                        res_time+=route(FirstStation, stations_red[9]);
                        res_time+=route(stations_green[3], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_red[10]);
                        res_time+=route(stations_blue[7], stations_blue[8]);
                        res_time+=route(stations_green[4], SecondStation);
                    }
                }
        
            }else{

                if(Coord1.second<=10){
                    if(Coord2.second<=7){
                        res_time+=route(FirstStation, stations_red[10]);
                        res_time+=route(stations_blue[7], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_red[9]);
                        res_time+=route(stations_green[3], stations_green[4]);
                        res_time+=route(SecondStation, stations_blue[8]);
                    }
                }else{
                    if(Coord2.second<=7){
                        res_time+=route(FirstStation, stations_red[10]);
                        res_time+=route(SecondStation, stations_blue[7]);
                    }else{
                        res+=route(FirstStation, stations_blue[10]);
                        res+=route(SecondStation, stations_blue[10]);
                    }
                }
            }
        }


    }

    return res_time;
}

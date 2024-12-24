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

std::vector<unsigned int> RedLineTime{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
	
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

std::vector<unsigned int> BlueLineTime{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

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

std::vector<unsigned int> GreenLineTime{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

int Red_to_Green=1, Red_to_Blue=5, Green_to_Blue=3, Green_to_Red=5, Blue_to_Red=9, Blue_to_Green=2;

void find_stations(const std::string& first, const std::string& second, std::pair<std::string, int>& index1, std::pair<std::string, int>& index2){
		
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

            if(index1.first=="123"){
                throw std::invalid_argument("Введите 1ую станцию еще раз\n");
            }        
        

    /*if(index1.first=="123"){
        throw std::invalid_argument("Введите 1ую станцию еще раз\n");
    }
    if(index2.first=="456"){
        throw std::invalid_argument("Введите 2ую станцию еще раз\n");
    }*/
}

int route(const std::string& FirstStation, const std::string& SecondStation){
    int res_time=0;
    std::pair<std::string, int> Coord1={"123", 5}, Coord2={"456", 9};
    find_stations(FirstStation, SecondStation, Coord1, Coord2);

    // Рассмотрим случаи когда мы путешествуем, только по 1ой ветке
    if(Coord1.first==Coord2.first){

        if(Coord1.first=="stations_red"){
            if( (Coord1.second<=9 && Coord2.second<=9) || (Coord1.second>=10 && Coord2.second>=10) ){
                if(Coord1.second<=Coord2.second){
					for(int i=Coord1.second; i!=Coord2.second; i++){  
						res_time+=RedLineTime[i];
                        std::cout<<"The next station is: "<<stations_red[i+1]<<" Arrival time is: "<<RedLineTime[i]<<"\n";
					}
                }else{
					for(int i=Coord1.second; i!=Coord2.second; i--){
						res_time+=RedLineTime[i-1];
                        std::cout<<"The next station is: "<<stations_red[i-1]<<" Arrival time is: "<<RedLineTime[i-1]<<"\n";
					}
				}	
            }else{
				if(Coord1.second<=9){
                    res_time+=route(FirstStation, stations_red[9]);					
                    int a=GreenLineTime[3]+BlueLineTime[7]+Red_to_Green+Green_to_Blue+Blue_to_Red;
					if(a>=RedLineTime[9]){
                        std::cout<<"The next station is: "<<stations_red[10]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
						a=RedLineTime[9];
                    }else{
                        std::cout<<"Перейдите на зеленую линию на станцию ЗОЛОТЫЕ ВОРОТА\n";
                        std::cout<<"The next station is: "<<stations_green[4]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                        std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                        std::cout<<"The next station is: "<<stations_blue[7]<<" Arrival time is: "<<BlueLineTime[8]<<"\n";
                        std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                    }
					res_time+=a;
					res_time+=route(stations_red[10], SecondStation);
				}else{
					res_time+=route(FirstStation, stations_red[10]);
                    int a=GreenLineTime[3]+BlueLineTime[7]+Red_to_Blue+Blue_to_Green+Green_to_Red;
                    if(a>=RedLineTime[9]){
                        a=RedLineTime[9];
                        std::cout<<"The next station is: "<<stations_red[9]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                    }else{
                        std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                        std::cout<<"The next station is: "<<stations_blue[8]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                        std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                        std::cout<<"The next station is: "<<stations_green[3]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                        std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                    }
					res_time+=a;
					res_time+=route(stations_red[9], SecondStation);
				}
                 
            }
        }

        if(Coord1.first=="stations_green"){
            if( (Coord1.second<=3 && Coord2.second<=3) || (Coord1.second>=4 && Coord2.second>=4) ){
                if(Coord1.second<=Coord2.second){ 
                    for(int i=Coord1.second; i!=Coord2.second; i++){
                        res_time+=GreenLineTime[i];   
                        std::cout<<"The next station is: "<<stations_green[i+1]<<" Arrival time is: "<<GreenLineTime[i]<<"\n";
				    }
                }else{
                    for(int i=Coord1.second; i!=Coord2.second; i--){
                        res_time+=GreenLineTime[i-1];
                        std::cout<<"The next station is: "<<stations_green[i-1]<<" Arrival time is: "<<GreenLineTime[i-1]<<"\n";
                    }
                }
            }else{
                if(Coord1.second<=3){
                    res_time+=route(FirstStation, stations_green[3]);                 
                    int a=RedLineTime[9]+BlueLineTime[7]+Green_to_Red+Red_to_Blue+Blue_to_Green;
                    if(a>=GreenLineTime[3]){
                        std::cout<<"The next station is: "<<stations_green[4]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                        a=GreenLineTime[3];
                    }else{
                        std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                        std::cout<<"The next station is: "<<stations_red[10]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                        std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                        std::cout<<"The next station is: "<<stations_blue[8]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                        std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                    }
                    res_time+=a;
                    res_time+=route(stations_green[4], SecondStation);
                }else{
                    res_time+=route(FirstStation, stations_green[4]);
                    int a=RedLineTime[9]+BlueLineTime[7]+Green_to_Blue+Blue_to_Red+Red_to_Green;
                    if(a>=GreenLineTime[3]){
                        a=GreenLineTime[3];
                        std::cout<<"The next station is: "<<stations_green[3]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                    }else{
                        std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                        std::cout<<"The next station is: "<<stations_blue[7]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                        std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                        std::cout<<"The next station is: "<<stations_red[9]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                        std::cout<<"Перейдите на зеленую линию на станцию ЗОЛОТЫЕ ВОРОТА\n";
                    }
                    res_time+=a;
                    res_time+=route(stations_green[3], SecondStation);
                }
            }
        }

        if(Coord1.first=="stations_blue"){
            if( (Coord1.second<=7 && Coord2.second<=7) || (Coord1.second>=8 && Coord2.second>=8) ){
                if(Coord1.second<=Coord2.second){ 
                    for(int i=Coord1.second; i!=Coord2.second; i++){  
                        res_time+=BlueLineTime[i];  
                        std::cout<<"The next station is: "<<stations_blue[i+1]<<" Arrival time is: "<<BlueLineTime[i]<<"\n";
                    } 
                }else{
                    for(int i=Coord1.second; i!=Coord2.second; i--){
                        res_time+=BlueLineTime[i-1];
                        std::cout<<"The next station is: "<<stations_blue[i-1]<<" Arrival time is: "<<BlueLineTime[i-1]<<"\n";
                    }
                }   
            }else{
                if(Coord1.second<=7){
                    res_time+=route(FirstStation, stations_blue[7]);                 
                    int a=RedLineTime[9]+GreenLineTime[3]+Blue_to_Red+Red_to_Green+Green_to_Blue;
                    if(a>=BlueLineTime[7]){
                        std::cout<<"The next station is: "<<stations_blue[8]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                        a=BlueLineTime[7];
                    }else{
                        std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                        std::cout<<"The next station is: "<<stations_red[9]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                        std::cout<<"Перейдите на зеленую линию на станцию ЗОЛОТЫЕ ВОРОТА\n";
                        std::cout<<"The next station is: "<<stations_green[4]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                        std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                    }
                    res_time+=a;
                    res_time+=route(stations_blue[8], SecondStation);
                }else{
                    res_time+=route(FirstStation, stations_blue[8]);
                    int a=RedLineTime[9]+GreenLineTime[3]+Blue_to_Green+Green_to_Red+Red_to_Blue;
                    if(a>=BlueLineTime[7]){
                        a=BlueLineTime[7];
                        std::cout<<"The next station is: "<<stations_blue[7]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                    }else{
                        std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                        std::cout<<"The next station is: "<<stations_green[3]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                        std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                        std::cout<<"The next station is: "<<stations_red[10]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                        std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                    }
                    res_time+=a;
                    res_time+=route(stations_blue[7], SecondStation);
                }
            }
        }

    }
    else{  
    
        // Начинаем с красной
        
        if(Coord1.first=="stations_red") { 

            if(Coord2.first=="stations_green"){

                if(Coord1.second<=9){
                    if(Coord2.second<=3){
                        res_time+=route(FirstStation, stations_red[9]);
                        std::cout<<"Перейдите на зеленую линию на станцию ЗОЛОТЫЕ ВОРОТА\n";
                        res_time+=Red_to_Green;
                        res_time+=route(stations_green[3], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_red[9]);
                        int a=RedLineTime[9]+Red_to_Blue+BlueLineTime[7]+Blue_to_Green;
                        if( a>=(GreenLineTime[3]+Red_to_Green) ){
                            a=GreenLineTime[3]+Red_to_Green;
                            std::cout<<"Перейдите на зеленую ветку на станцию ЗОЛОТЫЕ ВОРОТА\n";
                            std::cout<<"The next station is: "<<stations_green[4]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                        }else{
                            std::cout<<"The next station is: "<<stations_red[10]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                            std::cout<<"The next station is: "<<stations_blue[8]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_green[4], SecondStation);
                    }
                }else{
                    if(Coord2.second<=3){
                        res_time+=route(FirstStation, stations_red[10]);
                        int a=Red_to_Blue+BlueLineTime[7]+Blue_to_Green+GreenLineTime[3];
                        if(a>=(RedLineTime[9]+Red_to_Green)){
                            a=RedLineTime[9]+Red_to_Green;
                            std::cout<<"The next station is: "<<stations_red[9]<<" Arrival time is:"<<RedLineTime[9]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ЗОЛОТЫЕ ВОРОТА\n";
                        }else{
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                            std::cout<<"The next station is: "<<stations_blue[8]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                            std::cout<<"The next station is: "<<stations_green[3]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_green[3], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_red[10]);
                        int a=RedLineTime[9]+Red_to_Green+GreenLineTime[3];
                        if(a>=(Red_to_Blue+BlueLineTime[7]+Blue_to_Green)){
                            a=Red_to_Blue+BlueLineTime[7]+Blue_to_Green;
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                            std::cout<<"The next station is:"<<stations_blue[8]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                        }else{
                            std::cout<<"The next station is: "<<stations_red[9]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ЗОЛОТЫЕ ВОРОТА\n";
                            std::cout<<"The next station is: "<<stations_green[4]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_green[4], SecondStation);
                    }
                }
        
            }else{

                if(Coord1.second<=9){
                    if(Coord2.second<=7){
                        res_time+=route(FirstStation, stations_red[9]);
                        int a=Red_to_Green+GreenLineTime[3]+Green_to_Blue+BlueLineTime[7];
                        if(a>=(RedLineTime[9]+Red_to_Blue)){
                            a=RedLineTime[9]+Red_to_Blue;
                            std::cout<<"The next station is: "<<stations_red[10]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                        }else{
                            std::cout<<"Перейдите на зеленую линию на станцию ЗОЛОТЫЕ ВОРОТА\n";
                            std::cout<<"The next station is: "<<stations_green[4]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                            std::cout<<"The next station is: "<<stations_blue[7]<<" Arrival time is: "<<BlueLineTime[7]<<"\n"; 
                        }
                        res_time+=a;
                        res_time+=route(stations_blue[7], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_red[9]);
                        int a=RedLineTime[9]+Red_to_Blue+BlueLineTime[7];
                        if(a>=(Red_to_Green+GreenLineTime[3]+Green_to_Blue)){
                            a=Red_to_Green+GreenLineTime[3]+Green_to_Blue;
                            std::cout<<"Перейдите на зеленую линию на станцию ЗОЛОТЫЕ ВОРОТА\n";
                            std::cout<<"The next station is: "<<stations_green[4]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                        }else{
                            std::cout<<"The next station is: "<<stations_red[10]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                            std::cout<<"The next station is: "<<stations_blue[8]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_blue[8], SecondStation);
                    }
                }else{
                    if(Coord2.second<=7){
                        res_time+=route(FirstStation, stations_red[10]);
                        std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                        res_time+=route(stations_blue[7], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_red[10]);
                        int a=RedLineTime[9]+Red_to_Green+GreenLineTime[3]+Green_to_Blue;
                        if(a>=(Red_to_Blue+BlueLineTime[7])){
                            a=Red_to_Blue+BlueLineTime[7];
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                            std::cout<<"The next station is: "<<stations_blue[8]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                        }else{
                            std::cout<<"The next station is: "<<stations_red[9]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ЗОЛОТЫЕ ВОРОТА\n";
                            std::cout<<"The next station is: "<<stations_green[4]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_blue[8], SecondStation);
                    }
                }
            }
        }

        if(Coord1.first=="stations_green"){

            if(Coord2.first=="stations_red"){
                if(Coord1.second<=3){
                    if(Coord2.second<=9){
                        res_time+=route(FirstStation, stations_green[3]);
                        std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                        res_time+=Green_to_Red;
                        res_time+=route(stations_red[9], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_green[3]);
                        int a=GreenLineTime[3]+Green_to_Blue+BlueLineTime[7]+Blue_to_Red;
                        if(a>=(Green_to_Red+RedLineTime[9])){
                            a=Green_to_Red+RedLineTime[9];
                            std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                            std::cout<<"The next station is: "<<stations_red[10]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                        }else{
                            std::cout<<"The next station is: "<<stations_green[4]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                            std::cout<<"The next station is: "<<stations_blue[7]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_red[10], SecondStation);
                    }
                }else{
                    if(Coord2.second<=9){
                        res_time+=route(FirstStation, stations_green[4]);
                        int a=Green_to_Blue+BlueLineTime[7]+Blue_to_Red+RedLineTime[9];
                        if(a>=(GreenLineTime[3]+Green_to_Red)){
                            a=GreenLineTime[3]+Green_to_Red;
                            std::cout<<"The next station is: "<<stations_green[3]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                        }else{
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                            std::cout<<"The next station is: "<<stations_blue[7]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                            std::cout<<"The next station is: "<<stations_red[9]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_red[9], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_green[4]);
                        int a=GreenLineTime[3]+Green_to_Red+RedLineTime[9];
                        if(a>=(Green_to_Blue+BlueLineTime[7])){
                            a=Green_to_Blue+BlueLineTime[7];
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                            std::cout<<"The next station is: "<<stations_blue[7]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                        }else{
                            std::cout<<"The next station: "<<stations_green[3]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                            std::cout<<"The next station is: "<<stations_red[10]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                        }
                        res_time+=route(stations_red[10], SecondStation);
                    }
                }
            // С Зеленой на Синюю
            }else{
                if(Coord1.second<=3){
                    if(Coord2.second<=7){
                        res_time+=route(FirstStation, stations_green[3]);
                        int a=GreenLineTime[3]+Green_to_Blue+BlueLineTime[7]+Blue_to_Red;
                        if(a>=(Green_to_Red+RedLineTime[9])){
                            a=Green_to_Red+RedLineTime[9];
                            std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                            std::cout<<"The next station is: "<<stations_red[10]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                        }else{
                            std::cout<<"The next station is: "<<stations_green[4]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                            std::cout<<"The next station is: "<<stations_blue[7]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_blue[7], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_green[3]);
                        int a=Green_to_Red+RedLineTime[9]+Red_to_Blue+BlueLineTime[7];
                        if(a>=(GreenLineTime[3]+Green_to_Blue)){
                            a=GreenLineTime[3]+Green_to_Blue;
                            std::cout<<"The next station is: "<<stations_green[4]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                        }else{
                            std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                            std::cout<<"The next station is: "<<stations_red[10]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                            std::cout<<"The next station is: "<<stations_blue[8]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_blue[8], SecondStation);
                    }
                }else{
                    if(Coord2.second<=7){
                        res_time+=route(FirstStation, stations_green[4]);
                        int a=GreenLineTime[3]+Green_to_Red+RedLineTime[9]+Red_to_Blue;
                        if(a>=(Green_to_Blue+BlueLineTime[7])){
                            a=Green_to_Blue+BlueLineTime[7];
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                            std::cout<<"The next station is: "<<stations_blue[7]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                        }else{
                            std::cout<<"The next station is: "<<stations_green[3]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                            std::cout<<"The next station is: "<<stations_red[10]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                            std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ НЕЗАВИСИМОСТИ\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_blue[7], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_green[4]);
                        std::cout<<"Перейдите на синюю линию на станцию ПЛОЩАДЬ ЛЬВА ТОЛСТОГО\n";
                        res_time+=Green_to_Blue;
                        res_time+=route(stations_blue[8], SecondStation);
                    }
                }

            }
        }

        if(Coord1.first=="stations_blue"){

            if(Coord2.first=="stations_red"){
                if(Coord1.second<=7){
                    if(Coord2.second<=9){
                        res_time+=route(FirstStation, stations_blue[7]);
                        int a=BlueLineTime[7]+Blue_to_Green+GreenLineTime[3]+Green_to_Red;
                        if(a>=(Blue_to_Red+RedLineTime[9])){
                            a=Blue_to_Red+RedLineTime[9];
                            std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                            std::cout<<"The next station is: "<<stations_red[9]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                        }else{
                            std::cout<<"The next station is: "<<stations_blue[8]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                            std::cout<<"The next station is: "<<stations_green[3]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_red[9], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_blue[7]);
                        std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                        res_time+=Blue_to_Red;
                        res_time+=route(stations_red[10], SecondStation);
                    }
                }else{
                    if(Coord2.second<=9){
                        res_time+=route(FirstStation, stations_blue[8]);
                        int a=BlueLineTime[7]+Blue_to_Red+RedLineTime[9];
                        if(a>=(Blue_to_Green+GreenLineTime[3]+Green_to_Red)){
                            a=Blue_to_Green+GreenLineTime[3]+Green_to_Red;
                            std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                            std::cout<<"The next station is: "<<stations_green[3]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                        }else{
                            std::cout<<"The next station is: "<<stations_blue[7]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                            std::cout<<"The next station is: "<<stations_red[9]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_red[9], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_blue[8]);
                        int a=Blue_to_Green+GreenLineTime[3]+Green_to_Red+RedLineTime[9];
                        if(a>=(BlueLineTime[7]+Blue_to_Red)){
                            a=BlueLineTime[7]+Blue_to_Red;
                            std::cout<<"The next station is: "<<stations_blue[7]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                        }else{
                            std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                            std::cout<<"The next station is: "<<stations_green[3]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию ТЕАТРАЛЬНАЯ\n";
                            std::cout<<"The next station is: "<<stations_red[10]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_red[10], SecondStation);
                    }
                }
            }else{
                if(Coord1.second<=7){
                    if(Coord2.second<=3){
                        res_time+=route(FirstStation, stations_blue[7]);
                        int a=BlueLineTime[7]+Blue_to_Green+GreenLineTime[3];
                        if(a>=(Blue_to_Red+BlueLineTime[9]+Red_to_Green)){
                            a=Blue_to_Red+BlueLineTime[9]+Red_to_Green;
                            std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                            std::cout<<"The next station is: "<<stations_red[9]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ЗОЛОТЫЕ ВОРОТА\n";
                        }else{
                            std::cout<<"The next station is: "<<stations_blue[8]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                            std::cout<<"The next station is: "<<stations_green[3]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_green[3], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_blue[7]);
                        int a=Blue_to_Red+RedLineTime[9]+Red_to_Green+GreenLineTime[3];
                        if(a>=(BlueLineTime[7]+Blue_to_Green)){
                            a=BlueLineTime[7]+Blue_to_Green;
                            std::cout<<"The next station is: "<<stations_blue[8]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                        }else{
                            std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                            std::cout<<"The next station is: "<<stations_red[9]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ЗОЛОТЫЕ ВОРОТА\n";
                            std::cout<<"The next station is: "<<stations_green[4]<<" Arrival time is"<<GreenLineTime[3]<<"\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_green[4], SecondStation);
                    }
                }else{
                    if(Coord2.second<=3){
                        res_time+=route(FirstStation, stations_blue[8]);
                        int a=BlueLineTime[7]+Blue_to_Red+RedLineTime[9]+Red_to_Green;
                        if(a>=(Blue_to_Green+GreenLineTime[3])){
                            a=Blue_to_Green+GreenLineTime[3];
                            std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                            std::cout<<"The next station is: "<<stations_green[3]<<" Arrival time is: "<<GreenLineTime[3]<<"\n";
                        }else{
                            std::cout<<"The next station is: "<<stations_blue[7]<<" Arrival time is: "<<BlueLineTime[7]<<"\n";
                            std::cout<<"Перейдите на красную линию на станцию КРЕЩАТИК\n";
                            std::cout<<"The next station is: "<<stations_red[9]<<" Arrival time is: "<<RedLineTime[9]<<"\n";
                            std::cout<<"Перейдите на зеленую линию на станцию ЗОЛОТЫЕ ВОРОТА\n";
                        }
                        res_time+=a;
                        res_time+=route(stations_green[3], SecondStation);
                    }else{
                        res_time+=route(FirstStation, stations_blue[8]);
                        std::cout<<"Перейдите на зеленую линию на станцию ДВОРЕЦ СПОРТА\n";
                        res_time+=Blue_to_Green;
                        res_time+=route(stations_green[4], SecondStation);
                    }
                }
            }
        }
    }
    return res_time;
}
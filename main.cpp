#include "f.h"

int main(){
    std::string startStation, destinationStation;
	std::getline(std::cin, startStation);
	std::getline(std::cin, destinationStation);
	std::pair<std::string, int> Coord1, Coord2;
	find_stations(startStation, destinationStation, Coord1, Coord2);
    std::cout << "Линия начальной станции: " << Coord1.first << '\n';
    std::cout << "Номер начальной станции:  " << Coord1.second+1 << '\n';   //То что в проге индексы с 0 считают, не значит что люди так считают
    std::cout << "Линия станции назначения: " << Coord2.first << '\n';
    std::cout << "Номер станции назначения:  " << Coord2.second+1 << '\n';   //То что в проге индексы с 0 считают, не значит что люди так считают
	std::cout << "Время кратчайшего маршрута: " << route(startStation, destinationStation)<<"\n";
	return 0;
}

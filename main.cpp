#include "f.h"

int main(){
    std::string startStation, destinationStation;
	std::getline(std::cin, startStation);
	std::getline(std::cin, destinationStation);
	std::pair<std::string, int> Coord1, Coord2;
	find_stations(startStation, destinationStation, Coord1, Coord2);
	std::cout<<"Номер 1ой станции: "<<Coord1.second<<"\nЦвет линии первой станции: "<<Coord1.first<<"\n";
	std::cout<<"Номер 2ой станции: "<<Coord2.second<<"\nЦвет линии второй станции: "<<Coord2.first<<"\n";
	std::cout<<route(startStation, destinationStation)<<"\n";

	return 0;
}

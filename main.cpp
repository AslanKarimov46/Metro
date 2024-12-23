#include "f.h"

int main() {
    std::string startStation, destinationStation;
	std::cout << "Введите станцию начала маршрута";
	std::getline(std::cin, startStation);
	std::cout << "Введите станцию конца маршрута";
	std::getline(std::cin, destinationStation);
	std::pair<std::string, int> Coord1, Coord2;
	find_stations(startStation, destinationStation, Coord1, Coord2);
	std::cout << "Время кратчайшего маршрута: " << route(startStation, destinationStation)<<"\n";
	return 0;
}

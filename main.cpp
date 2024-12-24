#include "f.h"

int main() {
    std::string startStation, destinationStation;
	std::cout << "Введите станцию начала маршрута";
	std::getline(std::cin, startStation);
	std::cout << "Введите станцию конца маршрута";
	std::getline(std::cin, destinationStation);
	std::pair<std::string, int> Coord1={"123", 5}, Coord2={"456", 9};
		try
	{
		while(true)
		{
			unsigned int timeMetro = route(startStation, destinationStation);
			std::cout << "Время кратчайшего маршрута: " << timeMetro << '\n';		
		}
	} catch(const std::invalid_argument& err){
            std::cout << "Ошибка в станции: " << err.what() << '\n';
        }



	return 0;
}

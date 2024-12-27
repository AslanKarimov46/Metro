#include "Metro.h"

int main() {
    std::string startStation, destinationStation;
    std::pair<std::string, int> startPos;
    std::cout << "Введите станцию начала маршрута: ";
    bool isRight = false;
    while(!isRight) {
        try {
            std::getline(std::cin, startStation);
            find_stations(startStation, startStation, startPos, startPos);
            isRight = true;
        } catch (const std::invalid_argument& exception) {
            std::cout << exception.what();
        }
    }
	std::cout << "Введите станцию конца маршрута: ";
    std::pair<std::string, int> endPos;
    isRight = false;
    while(!isRight) {
        try {
            std::getline(std::cin, destinationStation);
            find_stations(destinationStation, destinationStation, endPos, endPos);
            isRight = true;
        } catch (const std::invalid_argument& exception) {
            std::cout << exception.what();
        }
    }
    unsigned int timeMetro = route(startPos, endPos);
    std::cout << "Необходимое время на маршрут: " << timeMetro << '\n';
	return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
	std::vector<std::string> GreenLine {
		"Сырец",
		"Дорогожичи",
		"Лукьяновская",
		"Золотые Ворота",
		"Дворец Спорта",
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
		"Красный Хутор"
	};
	std::string Start, End;
	std::getline(std::cin, Start);
	std::getline(std::cin, End);
	auto StartPos = std::find(GreenLine.begin(), GreenLine.end(), Start);
	auto EndPos = std::find(GreenLine.begin(), GreenLine.end(), End);
	while(StartPos < EndPos) {
		StartPos++;
		std::cout << "Qaplar bağlanır. Növbəti stansiyası - " << GreenLine[StartPos-GreenLine.begin()] << '\n';
	}
	while(StartPos > EndPos) {
		StartPos--;
		std::cout << "Qaplar bağlanır. Növbəti stansiyası - " << GreenLine[StartPos-GreenLine.begin()] << '\n';
	}
	return 0;
}

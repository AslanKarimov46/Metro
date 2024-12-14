#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void OneLineRide(const std::vector<std::string>& Line, ptrdiff_t Start, ptrdiff_t End) {
	while(Start < End) {
		Start++;
		std::cout << "Qaplar bağlanır. Növbəti stansiyası - " << Line[Start] << '\n';
	}
	while(Start > End) {
		Start--;
		std::cout << "Qaplar bağlanır. Növbəti stansiyası - " << Line[Start] << '\n';
	}
}
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
	auto StartPos = std::find(GreenLine.begin(), GreenLine.end(), Start)-GreenLine.begin();
	auto EndPos = std::find(GreenLine.begin(), GreenLine.end(), End)-GreenLine.begin();
	OneLineRide(GreenLine, StartPos, EndPos);
	return 0;
}

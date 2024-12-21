#include "f.h"

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

	//Я чувствую, насколько неоптимизированный весь этот код, поэтому пусть меня спасёт тот факт,
	//что между станциями не может быть 255 минут времени. Иначе это уже не метро.
	/*std::vector<char> GreenLineTime{
		3, //Сырец - Дорогожичи
		2, //Дорогожичи - Лукьяновская
		4, //Лукьяновская - Золотые ворота
		5, //Золотые ворота - Дворец спорта
		3, //Дворец Спорта - Кловская
		4, //Кловская - Печерская
		3, //Печерская - Дружбы Народов
		2, //Дружбы Народов - Выдубичи
		4, //Выдубичи - Славутич
		5, //Славутич - Осокорки
		7, //Осокорки - Позняки
		2, //Позняки - Харьковская
		1, //Харьковская - Вырлица
		3, //Вырлица - Бориспольская
		2, //Бориспольская - Красный Хутор
	};
	std::string Start, End;
	std::getline(std::cin, Start);
	std::getline(std::cin, End);
	auto StartPos = std::find(GreenLine.begin(), GreenLine.end(), Start)-GreenLine.begin();
	auto EndPos = std::find(GreenLine.begin(), GreenLine.end(), End)-GreenLine.begin();
	OneLineRide(GreenLine, StartPos, EndPos);*/

	std::string FirstStation="Святошин", SecondStation="Арсенальная";
	//std::pair<std::string, int> Coord1, Coord2;
	//find_stations(FirstStation, SecondStation, Coord1, Coord2);
	//std::cout<<"Номер 1ой станции: "<<Coord1.second<<"\nЦвет линии первой станции: "<<Coord1.first<<"\n";
	//std::cout<<"Номер 2ой станции: "<<Coord2.second<<"\nЦвет линии второй станции: "<<Coord2.first<<"\n"; 
	std::cout<<route(FirstStation, SecondStation)<<"\n";
	
	auto StartPos = std::find(GreenLine.begin(), GreenLine.end(), "Сырец")-GreenLine.begin();
	auto EndPos = std::find(GreenLine.begin(), GreenLine.end(), End)-GreenLine.begin();

	return 0;
}

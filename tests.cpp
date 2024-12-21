#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "f.h"

std::pair<std::string, int> start;
std::pair<std::string, int> destination;
TEST_SUITE_BEGIN("Finding test");
TEST_SUITE("Red-Red") {
    TEST_CASE("Житомирская - Университет") {
        find_stations("Житомирская", "Университет", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(1 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(8 == destination.second);
    }   //StartRed - StartRed
    TEST_CASE("Университет - Житомирская") {
        find_stations("Университет", "Житомирская", start, destination);
        CHECK("stations_red" == destination.first);
        CHECK(1 == destination.second);
        CHECK("stations_red" == start.first);
        CHECK(8 == start.second);
    }   //StartRed - StartRed

    TEST_CASE("Шулявская - Днепр") {
        find_stations("Шулявская", "Днепр", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(5 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(12 == destination.second);
    }   //StartRed - EndRed
    TEST_CASE("Днепр - Шулявская") {
        find_stations("Днепр", "Шулявская", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(12 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(5 == destination.second);

    }   //EndRed - StartRed

    TEST_CASE("Дарница - Арсенальная") {
        find_stations("Дарница", "Арсенальная", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(15 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(11 == destination.second);
    }   //EndRed - EndRed
    TEST_CASE("Арсенальная - Дарница") {
        find_stations("Арсенальная", "Дарница", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(11 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(15 == destination.second);
    }   //EndRed - EndRed

    TEST_CASE("Вокзальная - Театральная") {
        find_stations("Вокзальная", "Театральная", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(7 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(9 == destination.second);
    }   //StartRed - LeftRedChange
    TEST_CASE("Театральная - Вокзальная") {
        find_stations("Театральная", "Вокзальная", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(9 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(7 == destination.second);
    }   //LeftRedChange - StartRed

    TEST_CASE("Политехнический институт - Крещатик") {
        find_stations("Политехнический институт", "Крещатик", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(6 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(10 == destination.second);
    }   //StartRed - RightRedChange
    TEST_CASE("Крещатик - Политехнический институт") {
        find_stations("Крещатик", "Политехнический институт", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(10 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(6 == destination.second);
    }   //RightRedChange - StartRed

    TEST_CASE("Левобережная - Крещатик") {
        find_stations("Левобережная", "Крещатик", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(14 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(10 == destination.second);
    }   //EndRed - RightRedChange
    TEST_CASE("Крещатик - Левобережная") {
        find_stations("Крещатик", "Левобережная", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(10 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(14 == destination.second);
    }   //RightRedChange - EndRed

    TEST_CASE("Гидропарк - Театральная") {
        find_stations("Гидропарк", "Театральная", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(13 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(9 == destination.second);
    }   //EndRed - LeftRedChange
    TEST_CASE("Театральная - Гидропарк") {
        find_stations("Театральная", "Гидропарк", start, destination);
        CHECK("stations_red" == start.first);
        CHECK(9 == start.second);
        CHECK("stations_red" == destination.first);
        CHECK(13 == destination.second);
    }   //LeftRedChange - EndRed
}

TEST_SUITE("Blue-Blue") {
    TEST_CASE("Героев Днепра - Тараса Шевченко") {
        find_stations("Героев Днепра", "Тараса Шевченко", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(0 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(4 == destination.second);
    }   //StartBlue - StartBlue
    TEST_CASE("Тараса Шевченко - Героев Днепра ") {
        find_stations("Тараса Шевченко", "Героев Днепра", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(4 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(0 == destination.second);
    }   //StartBlue - StartBlue

    TEST_CASE("Петровка - Лыбедская") {
        find_stations("Петровка", "Лыбедская", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(3 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(11 == destination.second);
    }   //StartBlue - EndBlue
    TEST_CASE("Лыбедская - Петровка") {
        find_stations("Лыбедская", "Петровка", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(11 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(3 == destination.second);

    }   //EndBlue - StartBlue

    TEST_CASE("Дворец Украина - Голосеевская") {
        find_stations("Дворец Украина", "Голосеевская", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(10 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(13 == destination.second);
    }   //EndBlue - EndBlue
    TEST_CASE("Голосеевская - Дворец Украина") {
        find_stations("Голосеевская", "Дворец Украина", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(13 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(10 == destination.second);
    }   //EndBlue - EndBlue

    TEST_CASE("Минская - Площадь Независимости") {
        find_stations("Минская", "Площадь Независимости", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(1 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(7 == destination.second);
    }   //StartBlue - UpBlueChange
    TEST_CASE("Площадь Независимости - Минская") {
        find_stations("Площадь Независимости", "Минская", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(7 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(1 == destination.second);
    }   //UpBlueChange - StartBlue

    TEST_CASE("Оболонь - Площадь Льва Толстого") {
        find_stations("Оболонь", "Площадь Льва Толстого", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(2 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(8 == destination.second);
    }   //StartBlue - DownBlueChange
    TEST_CASE("Площадь Льва Толстого - Оболонь") {
        find_stations("Площадь Льва Толстого", "Оболонь", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(8 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(2 == destination.second);
    }   //DownBlueChange - StartBlue

    TEST_CASE("Ипподром - Площадь Независимости") {
        find_stations("Ипподром", "Площадь Независимости", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(16 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(7 == destination.second);
    }   //EndBlue - UpBlueChange
    TEST_CASE("Площадь Независимости - Ипподром") {
        find_stations("Площадь Независимости", "Ипподром", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(7 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(16 == destination.second);
    }   //UpBlueChange - EndBlue

    TEST_CASE("Васильковская - Площадь Льва Толстого") {
        find_stations("Васильковская", "Площадь Льва Толстого", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(14 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(8 == destination.second);
    }   //EndBlue - DownBlueChange
    TEST_CASE("Площадь Льва Толстого - Васильковская") {
        find_stations("Площадь Льва Толстого", "Васильковская", start, destination);
        CHECK("stations_blue" == start.first);
        CHECK(8 == start.second);
        CHECK("stations_blue" == destination.first);
        CHECK(14 == destination.second);
    }   //DownBlueChange - EndBlue
}

TEST_SUITE("Green-Green") {
    TEST_CASE("Сырец - Лукьяновская") {
        find_stations("Сырец", "Лукьяновская", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(0 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(2 == destination.second);
    }   //StartGreen - StartGreen
    TEST_CASE("Лукьяновская - Сырец") {
        find_stations("Лукьяновская", "Сырец", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(2 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(0 == destination.second);
    }   //StartGreen - StartGreen

    TEST_CASE("Дорогожичи - Позняки") {
        find_stations("Дорогожичи", "Позняки", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(1 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(11 == destination.second);
    }   //Startgreen - Endgreen
    TEST_CASE("Позняки - Дорогожичи") {
        find_stations("Позняки", "Дорогожичи", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(11 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(1 == destination.second);

    }   //Endgreen - Startgreen

    TEST_CASE("Красный хутор - Славутич") {
        find_stations("Красный хутор", "Славутич", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(15 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(9 == destination.second);
    }   //Endgreen - Endgreen
    TEST_CASE("Славутич - Красный хутор") {
        find_stations("Славутич", "Красный хутор", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(9 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(15 == destination.second);
    }   //Endgreen - Endgreen

    TEST_CASE("Сырец - Дворец спорта") {
        find_stations("Сырец", "Дворец спорта", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(0 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(4 == destination.second);
    }   //StartGreen - RightGreenChange
    TEST_CASE("Дворец спорта - Сырец") {
        find_stations("Дворец спорта", "Сырец", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(4 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(0 == destination.second);
    }   //RightGreenChange - StartGreen

    TEST_CASE("Дорогожичи - Золотые ворота") {
        find_stations("Дорогожичи", "Золотые ворота", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(1 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(3 == destination.second);
    }   //StartGreen - LeftGreenChange
    TEST_CASE("Золотые ворота - Дорогожичи") {
        find_stations("Золотые ворота", "Дорогожичи", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(3 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(1 == destination.second);
    }   //LeftGreenChange - StartGreen

    TEST_CASE("Вырлица - Дворец спорта") {
        find_stations("Вырлица", "Дворец спорта", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(13 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(4 == destination.second);
    }   //EndGreen - RightGreenChange
    TEST_CASE("Дворец спорта - Вырлица") {
        find_stations("Дворец спорта", "Вырлица", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(4 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(13 == destination.second);
    }   //RightGreenChange - EndGreen

    TEST_CASE("Выдубичи - Золотые ворота") {
        find_stations("Выдубичи", "Золотые ворота", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(8 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(3 == destination.second);
    }   //EndGreen - LeftGreenChange
    TEST_CASE("Золотые ворота - Выдубичи") {
        find_stations("Золотые ворота", "Выдубичи", start, destination);
        CHECK("stations_green" == start.first);
        CHECK(3 == start.second);
        CHECK("stations_green" == destination.first);
        CHECK(8 == destination.second);
    }   //LeftGreenChange - EndGreen
}

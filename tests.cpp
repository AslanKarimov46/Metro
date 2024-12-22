#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "f.h"

std::pair<std::string, int> start;
std::pair<std::string, int> destination;

std::vector<int> RedLineTimeTest{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
int Red_to_GreenTest=1, Red_to_BlueTest=5, Green_to_BlueTest=3, Green_to_RedTest=5, Blue_to_RedTest=9, Blue_to_GreenTest=2;
std::vector<int> BlueLineTimeTest{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
std::vector<int> GreenLineTimeTest{1, 2, 3, 4789, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
//лучше варика я не придумал

TEST_SUITE_BEGIN("Finding test");
TEST_SUITE("Red-Red") {
    TEST_CASE("Житомирская - Университет") {
        find_stations("Житомирская", "Университет", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(1, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(8, destination.second);
    }   //StartRed - StartRed
    TEST_CASE("Университет - Житомирская") {
        find_stations("Университет", "Житомирская", start, destination);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(1, destination.second);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(8, start.second);
    }   //StartRed - StartRed

    TEST_CASE("Шулявская - Днепр") {
        find_stations("Шулявская", "Днепр", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(5, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(12, destination.second);
    }   //StartRed - EndRed
    TEST_CASE("Днепр - Шулявская") {
        find_stations("Днепр", "Шулявская", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(12, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(5, destination.second);

    }   //EndRed - StartRed

    TEST_CASE("Дарница - Арсенальная") {
        find_stations("Дарница", "Арсенальная", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(15, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(11, destination.second);
    }   //EndRed - EndRed
    TEST_CASE("Арсенальная - Дарница") {
        find_stations("Арсенальная", "Дарница", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(11, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(15, destination.second);
    }   //EndRed - EndRed

    TEST_CASE("Вокзальная - Театральная") {
        find_stations("Вокзальная", "Театральная", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(7, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(9, destination.second);
    }   //StartRed - LeftRedChange
    TEST_CASE("Театральная - Вокзальная") {
        find_stations("Театральная", "Вокзальная", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(9, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(7, destination.second);
    }   //LeftRedChange - StartRed

    TEST_CASE("Политехнический институт - Крещатик") {
        find_stations("Политехнический институт", "Крещатик", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(6, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(10, destination.second);
    }   //StartRed - RightRedChange
    TEST_CASE("Крещатик - Политехнический институт") {
        find_stations("Крещатик", "Политехнический институт", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(10, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(6, destination.second);
    }   //RightRedChange - StartRed

    TEST_CASE("Левобережная - Крещатик") {
        find_stations("Левобережная", "Крещатик", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(14, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(10, destination.second);
    }   //EndRed - RightRedChange
    TEST_CASE("Крещатик - Левобережная") {
        find_stations("Крещатик", "Левобережная", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(10, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(14, destination.second);
    }   //RightRedChange - EndRed

    TEST_CASE("Гидропарк - Театральная") {
        find_stations("Гидропарк", "Театральная", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(13, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(9, destination.second);
    }   //EndRed - LeftRedChange
    TEST_CASE("Театральная - Гидропарк") {
        find_stations("Театральная", "Гидропарк", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(9, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(13, destination.second);
    }   //LeftRedChange - EndRed
}

TEST_SUITE("Blue-Blue") {
    TEST_CASE("Героев Днепра - Тараса Шевченко") {
        find_stations("Героев Днепра", "Тараса Шевченко", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(0, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(4, destination.second);
    }   //StartBlue - StartBlue
    TEST_CASE("Тараса Шевченко - Героев Днепра ") {
        find_stations("Тараса Шевченко", "Героев Днепра", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(4, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(0, destination.second);
    }   //StartBlue - StartBlue

    TEST_CASE("Петровка - Лыбедская") {
        find_stations("Петровка", "Лыбедская", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(3, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(11, destination.second);
    }   //StartBlue - EndBlue
    TEST_CASE("Лыбедская - Петровка") {
        find_stations("Лыбедская", "Петровка", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(11, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(3, destination.second);

    }   //EndBlue - StartBlue

    TEST_CASE("Дворец Украина - Голосеевская") {
        find_stations("Дворец Украина", "Голосеевская", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(10, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(13, destination.second);
    }   //EndBlue - EndBlue
    TEST_CASE("Голосеевская - Дворец Украина") {
        find_stations("Голосеевская", "Дворец Украина", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(13, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(10, destination.second);
    }   //EndBlue - EndBlue

    TEST_CASE("Минская - Площадь Независимости") {
        find_stations("Минская", "Площадь Независимости", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(1, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(7, destination.second);
    }   //StartBlue - UpBlueChange
    TEST_CASE("Площадь Независимости - Минская") {
        find_stations("Площадь Независимости", "Минская", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(7, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(1, destination.second);
    }   //UpBlueChange - StartBlue

    TEST_CASE("Оболонь - Площадь Льва Толстого") {
        find_stations("Оболонь", "Площадь Льва Толстого", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(2, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(8, destination.second);
    }   //StartBlue - DownBlueChange
    TEST_CASE("Площадь Льва Толстого - Оболонь") {
        find_stations("Площадь Льва Толстого", "Оболонь", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(8, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(2, destination.second);
    }   //DownBlueChange - StartBlue

    TEST_CASE("Ипподром - Площадь Независимости") {
        find_stations("Ипподром", "Площадь Независимости", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(16, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(7, destination.second);
    }   //EndBlue - UpBlueChange
    TEST_CASE("Площадь Независимости - Ипподром") {
        find_stations("Площадь Независимости", "Ипподром", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(7, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(16, destination.second);
    }   //UpBlueChange - EndBlue

    TEST_CASE("Васильковская - Площадь Льва Толстого") {
        find_stations("Васильковская", "Площадь Льва Толстого", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(14, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(8, destination.second);
    }   //EndBlue - DownBlueChange
    TEST_CASE("Площадь Льва Толстого - Васильковская") {
        find_stations("Площадь Льва Толстого", "Васильковская", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(8, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(14, destination.second);
    }   //DownBlueChange - EndBlue
}

TEST_SUITE("Green-Green") {
    TEST_CASE("Сырец - Лукьяновская") {
        find_stations("Сырец", "Лукьяновская", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(0, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(2, destination.second);
    }   //StartGreen - StartGreen
    TEST_CASE("Лукьяновская - Сырец") {
        find_stations("Лукьяновская", "Сырец", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(2, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(0, destination.second);
    }   //StartGreen - StartGreen

    TEST_CASE("Дорогожичи - Позняки") {
        find_stations("Дорогожичи", "Позняки", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(1, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(11, destination.second);
    }   //Startgreen - Endgreen
    TEST_CASE("Позняки - Дорогожичи") {
        find_stations("Позняки", "Дорогожичи", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(11, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(1, destination.second);

    }   //Endgreen - Startgreen

    TEST_CASE("Красный хутор - Славутич") {
        find_stations("Красный хутор", "Славутич", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(15, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(9, destination.second);
    }   //Endgreen - Endgreen
    TEST_CASE("Славутич - Красный хутор") {
        find_stations("Славутич", "Красный хутор", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(9, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(15, destination.second);
    }   //Endgreen - Endgreen

    TEST_CASE("Сырец - Дворец спорта") {
        find_stations("Сырец", "Дворец спорта", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(0, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(4, destination.second);
    }   //StartGreen - RightGreenChange
    TEST_CASE("Дворец спорта - Сырец") {
        find_stations("Дворец спорта", "Сырец", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(4, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(0, destination.second);
    }   //RightGreenChange - StartGreen

    TEST_CASE("Дорогожичи - Золотые ворота") {
        find_stations("Дорогожичи", "Золотые ворота", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(1, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(3, destination.second);
    }   //StartGreen - LeftGreenChange
    TEST_CASE("Золотые ворота - Дорогожичи") {
        find_stations("Золотые ворота", "Дорогожичи", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(3, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(1, destination.second);
    }   //LeftGreenChange - StartGreen

    TEST_CASE("Вырлица - Дворец спорта") {
        find_stations("Вырлица", "Дворец спорта", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(13, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(4, destination.second);
    }   //EndGreen - RightGreenChange
    TEST_CASE("Дворец спорта - Вырлица") {
        find_stations("Дворец спорта", "Вырлица", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(4, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(13, destination.second);
    }   //RightGreenChange - EndGreen

    TEST_CASE("Выдубичи - Золотые ворота") {
        find_stations("Выдубичи", "Золотые ворота", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(8, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(3, destination.second);
    }   //EndGreen - LeftGreenChange
    TEST_CASE("Золотые ворота - Выдубичи") {
        find_stations("Золотые ворота", "Выдубичи", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(3, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(8, destination.second);
    }   //LeftGreenChange - EndGreen
}
TEST_SUITE_END();

TEST_SUITE_BEGIN("route test");
TEST_SUITE("Red-Red") {
    TEST_CASE("Житомирская - Университет") {
        int timeMetro = RedLineTimeTest[1] + RedLineTimeTest[2] + RedLineTimeTest[3] + RedLineTimeTest[4] + RedLineTimeTest[5] + RedLineTimeTest[6] + RedLineTimeTest[7];
        CHECK_EQ(route("Житомирская", "Университет"), timeMetro);
    }   //StartRed - StartRed
    TEST_CASE("Университет - Житомирская") {
        int timeMetro = RedLineTimeTest[7] + RedLineTimeTest[6] + RedLineTimeTest[5] + RedLineTimeTest[4] + RedLineTimeTest[3] + RedLineTimeTest[2] + RedLineTimeTest[1];
        CHECK_EQ(route("Университет", "Житомирская"), timeMetro);
    }   //StartRed - StartRed

    TEST_CASE("Шулявская - Днепр") {
        int timeMetro = RedLineTimeTest[5]+RedLineTimeTest[6]+RedLineTimeTest[7]+RedLineTimeTest[8]+RedLineTimeTest[10]+RedLineTimeTest[11];
        if(Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest < RedLineTimeTest[9])
        {
            timeMetro += Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest;
        }
        else
        {
            timeMetro += RedLineTimeTest[9];
        }
        CHECK_EQ(route("Шулявская", "Днепр"), timeMetro);
    }   //StartRed - EndRed
    TEST_CASE("Днепр - Шулявская") {
        int timeMetro = RedLineTimeTest[11]+RedLineTimeTest[10]+RedLineTimeTest[8]+RedLineTimeTest[7]+RedLineTimeTest[6]+RedLineTimeTest[5];
        if(Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest < RedLineTimeTest[9])
        {
            timeMetro += Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest;
        }
        else
        {
            timeMetro += RedLineTimeTest[9];
        }
        CHECK_EQ(route("Днепр", "Шулявская"), timeMetro);
    }   //EndRed - StartRed

    TEST_CASE("Дарница - Арсенальная") {
        int timeMetro = RedLineTimeTest[14]+RedLineTimeTest[13]+RedLineTimeTest[12]+RedLineTimeTest[11];
        CHECK_EQ(route("Дарница", "Арсенальная"), timeMetro);
    }   //EndRed - EndRed
    TEST_CASE("Арсенальная - Дарница") {
        int timeMetro = RedLineTimeTest[11]+RedLineTimeTest[12]+RedLineTimeTest[13]+RedLineTimeTest[14];
        CHECK_EQ(route("Арсенальная", "Дарница"), timeMetro);
    }   //EndRed - EndRed

    TEST_CASE("Вокзальная - Театральная") {
        int timeMetro = RedLineTimeTest[7]+RedLineTimeTest[8];
        CHECK_EQ(route("Вокзальная", "Театральная"), timeMetro);
    }   //StartRed - LeftRedChange
    TEST_CASE("Театральная - Вокзальная") {
        int timeMetro = RedLineTimeTest[8]+RedLineTimeTest[7];
        CHECK_EQ(route("Театральная", "Вокзальная"), timeMetro);
    }   //LeftRedChange - StartRed

    TEST_CASE("Политехнический институт - Крещатик") {
        int timeMetro = RedLineTimeTest[6]+RedLineTimeTest[7]+RedLineTimeTest[8];
        if(Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest < RedLineTimeTest[9])
        {
            timeMetro += Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest;
        }
        else
        {
            timeMetro += RedLineTimeTest[9];
        }
        CHECK_EQ(route("Политехнический институт", "Крещатик"), timeMetro);
    }   //StartRed - RightRedChange
    TEST_CASE("Крещатик - Политехнический институт") {
        int timeMetro = RedLineTimeTest[6]+RedLineTimeTest[7]+RedLineTimeTest[8];
        if(Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest < RedLineTimeTest[9])
        {
            timeMetro += Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest;
        }
        else
        {
            timeMetro += RedLineTimeTest[9];
        }
        CHECK_EQ(route("Крещатик", "Политехнический институт"), timeMetro);
    }   //RightRedChange - StartRed

    TEST_CASE("Левобережная - Крещатик") {
        int timeMetro = RedLineTimeTest[13]+RedLineTimeTest[12]+RedLineTimeTest[11]+RedLineTimeTest[10];
        CHECK_EQ(route("Левобережная", "Крещатик"), timeMetro);
    }   //EndRed - RightRedChange
    TEST_CASE("Крещатик - Левобережная") {
        int timeMetro = RedLineTimeTest[10]+RedLineTimeTest[11]+RedLineTimeTest[12]+RedLineTimeTest[13];
        CHECK_EQ(route("Крещатик", "Левобережная"), timeMetro);
    }   //RightRedChange - EndRed

    TEST_CASE("Гидропарк - Театральная") {
        int timeMetro = RedLineTimeTest[12]+RedLineTimeTest[11]+RedLineTimeTest[10];
        if(Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest < RedLineTimeTest[9])
        {
            timeMetro += Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest;
        }
        else
        {
            timeMetro += RedLineTimeTest[9];
        }
        CHECK_EQ(route("Гидропарк", "Театральная"), timeMetro);
    }   //EndRed - LeftRedChange
    TEST_CASE("Театральная - Гидропарк") {
        int timeMetro = RedLineTimeTest[10]+RedLineTimeTest[11]+RedLineTimeTest[12];
        if(Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest < RedLineTimeTest[9])
        {
            timeMetro += Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest;
        }
        else
        {
            timeMetro += RedLineTimeTest[9];
        }
        CHECK_EQ(route("Театральная", "Гидропарк"), timeMetro);
    }   //LeftRedChange - EndRed
}

TEST_SUITE("Blue-Blue") {
    TEST_CASE("Героев Днепра - Тараса Шевченко") {
        int timeMetro = BlueLineTimeTest[0]+BlueLineTimeTest[1]+BlueLineTimeTest[2]+BlueLineTimeTest[3];
        CHECK_EQ(route("Героев Днепра", "Тараса Шевченко"), timeMetro);
    }   //StartBlue - StartBlue
    TEST_CASE("Тараса Шевченко - Героев Днепра ") {
        int timeMetro = BlueLineTimeTest[3]+BlueLineTimeTest[2]+BlueLineTimeTest[1]+BlueLineTimeTest[0];
        CHECK_EQ(route("Тараса Шевченко", "Героев Днепра"), timeMetro);
    }   //StartBlue - StartBlue

    TEST_CASE("Петровка - Лыбедская") {
        int timeMetro = BlueLineTimeTest[3]+BlueLineTimeTest[4]+BlueLineTimeTest[5]+BlueLineTimeTest[6]+BlueLineTimeTest[8]+BlueLineTimeTest[9]+BlueLineTimeTest[10];
        if(Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest < BlueLineTimeTest[7])
        {
            timeMetro += Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest;
        }
        else
        {
            timeMetro += BlueLineTimeTest[7];
        }
        CHECK_EQ(route("Петровка", "Лыбедская"), timeMetro);
    }   //StartBlue - EndBlue
    TEST_CASE("Лыбедская - Петровка") {
        int timeMetro = BlueLineTimeTest[10]+BlueLineTimeTest[9]+BlueLineTimeTest[8]+BlueLineTimeTest[6]+BlueLineTimeTest[5]+BlueLineTimeTest[4]+BlueLineTimeTest[3];
        if(Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest < BlueLineTimeTest[7])
        {
            timeMetro += Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest;
        }
        else
        {
            timeMetro += BlueLineTimeTest[7];
        }
        CHECK_EQ(route("Лыбедская", "Петровка"), timeMetro);
    }   //EndBlue - StartBlue

    TEST_CASE("Дворец Украина - Голосеевская") {
        int timeMetro = BlueLineTimeTest[10]+BlueLineTimeTest[11]+BlueLineTimeTest[12];
        CHECK_EQ(route("Дворец Украина", "Голосеевская"), timeMetro);
    }   //EndBlue - EndBlue
    TEST_CASE("Голосеевская - Дворец Украина") {
        int timeMetro = BlueLineTimeTest[12]+BlueLineTimeTest[11]+BlueLineTimeTest[10];
        CHECK_EQ(route("Голосеевская", "Дворец Украина"), timeMetro);
    }   //EndBlue - EndBlue

    TEST_CASE("Минская - Площадь Независимости") {
        int timeMetro = BlueLineTimeTest[1]+BlueLineTimeTest[2]+BlueLineTimeTest[3]+BlueLineTimeTest[4]+BlueLineTimeTest[5]+BlueLineTimeTest[6];
        CHECK_EQ(route("Минская", "Площадь Независимости"), timeMetro);
    }   //StartBlue - UpBlueChange
    TEST_CASE("Площадь Независимости - Минская") {
        int timeMetro = BlueLineTimeTest[6]+BlueLineTimeTest[5]+BlueLineTimeTest[4]+BlueLineTimeTest[3]+BlueLineTimeTest[2]+BlueLineTimeTest[1];
        CHECK_EQ(route("Площадь Независимости", "Минская"), timeMetro);
    }   //UpBlueChange - StartBlue

    TEST_CASE("Оболонь - Площадь Льва Толстого") {
        int timeMetro = BlueLineTimeTest[2]+BlueLineTimeTest[3]+BlueLineTimeTest[4]+BlueLineTimeTest[5]+BlueLineTimeTest[6];
        if(Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest < BlueLineTimeTest[7])
        {
            timeMetro += Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest;
        }
        else
        {
            timeMetro += BlueLineTimeTest[7];
        }
        CHECK_EQ(route("Оболонь", "Площадь Льва Толстого"), timeMetro);
    }   //StartBlue - DownBlueChange
    TEST_CASE("Площадь Льва Толстого - Оболонь") {
        int timeMetro = BlueLineTimeTest[2]+BlueLineTimeTest[3]+BlueLineTimeTest[4]+BlueLineTimeTest[5]+BlueLineTimeTest[6];
        if(Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest < BlueLineTimeTest[7])
        {
            timeMetro += Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest;
        }
        else
        {
            timeMetro += BlueLineTimeTest[7];
        }
        CHECK_EQ(route("Площадь Льва Толстого", "Оболонь"), timeMetro);
    }   //DownBlueChange - StartBlue

    TEST_CASE("Ипподром - Площадь Независимости") {
        int timeMetro = BlueLineTimeTest[15]+BlueLineTimeTest[14]+BlueLineTimeTest[13]+BlueLineTimeTest[12]+BlueLineTimeTest[11]+BlueLineTimeTest[10]+BlueLineTimeTest[9]+BlueLineTimeTest[8];
        if(Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest < BlueLineTimeTest[7])
        {
            timeMetro += Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest;
        }
        else
        {
            timeMetro += BlueLineTimeTest[7];
        }
        CHECK_EQ(route("Ипподром", "Площадь Независимости"), timeMetro);
    }   //EndBlue - UpBlueChange
    TEST_CASE("Площадь Независимости - Ипподром") {
        int timeMetro = BlueLineTimeTest[8]+BlueLineTimeTest[9]+BlueLineTimeTest[10]+BlueLineTimeTest[11]+BlueLineTimeTest[12]+BlueLineTimeTest[13]+BlueLineTimeTest[14]+BlueLineTimeTest[15];
        if(Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest < BlueLineTimeTest[7])
        {
            timeMetro += Red_to_GreenTest + RedLineTimeTest[9] + Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest;
        }
        else
        {
            timeMetro += BlueLineTimeTest[7];
        }
        CHECK_EQ(route("Площадь Независимости", "Ипподром"), timeMetro);
    }   //UpBlueChange - EndBlue

    TEST_CASE("Васильковская - Площадь Льва Толстого") {
        int timeMetro = BlueLineTimeTest[13]+BlueLineTimeTest[12]+BlueLineTimeTest[11]+BlueLineTimeTest[10]+BlueLineTimeTest[9]+BlueLineTimeTest[8];
        CHECK_EQ(route("Васильковская", "Площадь Льва Толстого"), timeMetro);
    }   //EndBlue - DownBlueChange
    TEST_CASE("Площадь Льва Толстого - Васильковская") {
        int timeMetro = BlueLineTimeTest[8]+BlueLineTimeTest[9]+BlueLineTimeTest[10]+BlueLineTimeTest[11]+BlueLineTimeTest[12]+BlueLineTimeTest[13];
        CHECK_EQ(route("Площадь Льва Толстого", "Васильковская"), timeMetro);
    }   //DownBlueChange - EndBlue
}

TEST_SUITE("Green-Green") {
    TEST_CASE("Сырец - Лукьяновская") {
        int timeMetro = GreenLineTimeTest[0]+GreenLineTimeTest[1];
        CHECK_EQ(route("Сырец", "Лукьяновская"), timeMetro);
    }   //StartGreen - StartGreen
    TEST_CASE("Лукьяновская - Сырец") {
        int timeMetro = GreenLineTimeTest[1]+GreenLineTimeTest[0];
        CHECK_EQ(route("Лукьяновская", "Сырец"), timeMetro);
    }   //StartGreen - StartGreen

    TEST_CASE("Дорогожичи - Позняки") {
        int timeMetro = GreenLineTimeTest[1]+GreenLineTimeTest[2]+GreenLineTimeTest[4]+GreenLineTimeTest[5]+GreenLineTimeTest[6]+GreenLineTimeTest[7]+GreenLineTimeTest[8]+GreenLineTimeTest[9]+GreenLineTimeTest[10];
        if(Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest < GreenLineTimeTest[3])
        {
            timeMetro += Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest;
        }
        else
        {
            timeMetro += GreenLineTimeTest[3];
        }
        CHECK_EQ(route("Дорогожичи", "Позняки"), timeMetro);
    }   //Startgreen - Endgreen
    TEST_CASE("Позняки - Дорогожичи") {
        int timeMetro = GreenLineTimeTest[10]+GreenLineTimeTest[9]+GreenLineTimeTest[8]+GreenLineTimeTest[7]+GreenLineTimeTest[6]+GreenLineTimeTest[5]+GreenLineTimeTest[4]+GreenLineTimeTest[2]+GreenLineTimeTest[1];
        if(Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest < GreenLineTimeTest[3])
        {
            timeMetro += Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest;
        }
        else
        {
            timeMetro += GreenLineTimeTest[3];
        }
        CHECK_EQ(route("Позняки", "Дорогожичи"), timeMetro);

    }   //Endgreen - Startgreen

    TEST_CASE("Красный хутор - Славутич") {
        int timeMetro = GreenLineTimeTest[14]+GreenLineTimeTest[13]+GreenLineTimeTest[12]+GreenLineTimeTest[11]+GreenLineTimeTest[10]+GreenLineTimeTest[9];
        CHECK_EQ(route("Красный хутор", "Славутич"), timeMetro);
    }   //Endgreen - Endgreen
    TEST_CASE("Славутич - Красный хутор") {
        int timeMetro = GreenLineTimeTest[9]+GreenLineTimeTest[10]+GreenLineTimeTest[11]+GreenLineTimeTest[12]+GreenLineTimeTest[13]+GreenLineTimeTest[14];
        CHECK_EQ(route("Славутич", "Красный хутор"), timeMetro);
    }   //Endgreen - Endgreen

    TEST_CASE("Сырец - Дворец спорта") {
        int timeMetro = GreenLineTimeTest[0]+GreenLineTimeTest[1]+GreenLineTimeTest[2];
        if(Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest < GreenLineTimeTest[3])
        {
            timeMetro += Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest;
        }
        else
        {
            timeMetro += GreenLineTimeTest[3];
        }
        CHECK_EQ(route("Сырец", "Дворец спорта"), timeMetro);
    }   //StartGreen - RightGreenChange
    TEST_CASE("Дворец спорта - Сырец") {
        int timeMetro = GreenLineTimeTest[2]+GreenLineTimeTest[1]+GreenLineTimeTest[0];
        if(Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest < GreenLineTimeTest[3])
        {
            timeMetro += Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest;
        }
        else
        {
            timeMetro += GreenLineTimeTest[3];
        }
        CHECK_EQ(route("Дворец спорта", "Сырец"), timeMetro);
    }   //RightGreenChange - StartGreen

    TEST_CASE("Дорогожичи - Золотые ворота") {
        int timeMetro = GreenLineTimeTest[1]+GreenLineTimeTest[2];
        CHECK_EQ(route("Дорогожичи", "Золотые ворота"), timeMetro);
    }   //StartGreen - LeftGreenChange
    TEST_CASE("Золотые ворота - Дорогожичи") {
        int timeMetro = GreenLineTimeTest[2]+GreenLineTimeTest[1];
        CHECK_EQ(route("Золотые ворота", "Дорогожичи"), timeMetro);
    }   //LeftGreenChange - StartGreen

    TEST_CASE("Вырлица - Дворец спорта") {
        int timeMetro = GreenLineTimeTest[12]+GreenLineTimeTest[11]+GreenLineTimeTest[10]+GreenLineTimeTest[9]+GreenLineTimeTest[8]+GreenLineTimeTest[7]+GreenLineTimeTest[6]+GreenLineTimeTest[5]+GreenLineTimeTest[4];
        CHECK_EQ(route("Вырлица", "Дворец спорта"), timeMetro);
    }   //EndGreen - RightGreenChange
    TEST_CASE("Дворец спорта - Вырлица") {
        int timeMetro = GreenLineTimeTest[4]+GreenLineTimeTest[5]+GreenLineTimeTest[6]+GreenLineTimeTest[7]+GreenLineTimeTest[8]+GreenLineTimeTest[9]+GreenLineTimeTest[10]+GreenLineTimeTest[11]+GreenLineTimeTest[12];
        CHECK_EQ(route("Дворец спорта", "Вырлица"), timeMetro);
    }   //RightGreenChange - EndGreen

    TEST_CASE("Выдубичи - Золотые ворота") {
        int timeMetro = GreenLineTimeTest[7]+GreenLineTimeTest[6]+GreenLineTimeTest[5]+GreenLineTimeTest[4];
        if(Green_to_BlueTest + BlueLineTimeTest[7]+ Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest < GreenLineTimeTest[3])
        {
            timeMetro += Green_to_BlueTest + BlueLineTimeTest[7]+ Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest;
        }
        else
        {
            timeMetro += GreenLineTimeTest[3];
        }
        CHECK_EQ(route("Выдубичи", "Золотые ворота"), timeMetro);
    }   //EndGreen - LeftGreenChange
    TEST_CASE("Золотые ворота - Выдубичи") {
        int timeMetro = GreenLineTimeTest[4]+GreenLineTimeTest[5]+GreenLineTimeTest[6]+GreenLineTimeTest[7];
        if(Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7]+ Blue_to_GreenTest < GreenLineTimeTest[3])
        {
            timeMetro += Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7]+ Blue_to_GreenTest;
        }
        else
        {
            timeMetro += GreenLineTimeTest[3];
        }
        CHECK_EQ(route("Золотые ворота", "Выдубичи"), timeMetro);
    }   //LeftGreenChange - EndGreen
}

TEST_SUITE("One-Two")
{
    TEST_CASE("Берестейская (RED) -  Выставочный центр (BLUE)"){
        int timeMetro = RedLineTimeTest[4]+RedLineTimeTest[5]+RedLineTimeTest[6]+RedLineTimeTest[7]+RedLineTimeTest[8]+BlueLineTimeTest[8]+BlueLineTimeTest[9]+BlueLineTimeTest[10]+BlueLineTimeTest[11]+BlueLineTimeTest[12]+BlueLineTimeTest[13]+BlueLineTimeTest[14];
        if(Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest < RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7])
        {
            timeMetro += Red_to_GreenTest + GreenLineTimeTest[3]+ Green_to_BlueTest;
        }
        else
        {
            timeMetro += RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7];
        }
        CHECK_EQ(route("Берестейская", "Выставочный центр"), timeMetro);
    }
    TEST_CASE("Контрактовая площадь (BLUE) - Дарница (RED)"){
        int timeMetro = BlueLineTimeTest[5]+BlueLineTimeTest[6] + RedLineTimeTest[10]+RedLineTimeTest[11]+RedLineTimeTest[12]+RedLineTimeTest[13]+RedLineTimeTest[14];
        if(Blue_to_RedTest < BlueLineTimeTest[7] + Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest + RedLineTimeTest[9])
        {
            timeMetro += Blue_to_RedTest;
        }
        else
        {
            timeMetro += BlueLineTimeTest[7] + Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest + RedLineTimeTest[9];
        }
        CHECK_EQ(route("Контрактовая площадь", "Дарница"), timeMetro);
    }
    TEST_CASE("Нивки (RED) - Бориспольская (GREEN)"){
        int timeMetro = RedLineTimeTest[3]+RedLineTimeTest[4]+RedLineTimeTest[5]+RedLineTimeTest[6]+RedLineTimeTest[7]+RedLineTimeTest[8]+GreenLineTimeTest[4]+GreenLineTimeTest[5]+GreenLineTimeTest[6]+GreenLineTimeTest[7]+GreenLineTimeTest[8]+GreenLineTimeTest[9]+GreenLineTimeTest[10]+GreenLineTimeTest[11]+GreenLineTimeTest[12]+GreenLineTimeTest[13];
        if(Red_to_GreenTest + GreenLineTimeTest[3] < RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest)
        {
            timeMetro += Red_to_GreenTest + GreenLineTimeTest[3];
        }
        else
        {
            timeMetro += RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest;
        }
    }
    TEST_CASE("Дорогожичи (GREEN) - Лесная (RED)"){
        int timeMetro = GreenLineTimeTest[1] + GreenLineTimeTest[2] + RedLineTimeTest[10] + RedLineTimeTest[11] + RedLineTimeTest[12] + RedLineTimeTest[13] + RedLineTimeTest[14] + RedLineTimeTest[15] + RedLineTimeTest[16];
        if(Green_to_RedTest + RedLineTimeTest[9] < GreenLineTimeTest[3] + Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest)
        {
            timeMetro += Green_to_RedTest + RedLineTimeTest[9];
        }
        else
        {
            timeMetro += GreenLineTimeTest[3] + Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest;
        }
    }
    TEST_CASE("Теремки (BLUE) - Сырец (GREEN)"){
        int timeMetro = BlueLineTimeTest[16]+BlueLineTimeTest[15]+BlueLineTimeTest[14]+BlueLineTimeTest[13]+BlueLineTimeTest[12]+BlueLineTimeTest[11]+BlueLineTimeTest[10]+BlueLineTimeTest[9]+BlueLineTimeTest[8]+GreenLineTimeTest[2]+GreenLineTimeTest[1]+GreenLineTimeTest[0];
        if(Blue_to_GreenTest + GreenLineTimeTest[3] < BlueLineTimeTest[7] + Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest)
        {
            timeMetro += Blue_to_GreenTest + GreenLineTimeTest[3];
        }
        else
        {
            timeMetro += BlueLineTimeTest[7] + Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest;
        }
    }
    TEST_CASE("Красный Хутор (GREEN) - Героев Днепра (BLUE)") {
        int timeMetro = GreenLineTimeTest[14]+GreenLineTimeTest[13]+GreenLineTimeTest[12]+GreenLineTimeTest[11]+GreenLineTimeTest[10]+GreenLineTimeTest[9]+GreenLineTimeTest[8]+GreenLineTimeTest[7]+GreenLineTimeTest[6]+GreenLineTimeTest[5]+GreenLineTimeTest[4]+BlueLineTimeTest[6]+BlueLineTimeTest[5]+BlueLineTimeTest[4]+BlueLineTimeTest[3]+BlueLineTimeTest[2]+BlueLineTimeTest[1]+BlueLineTimeTest[0];
        if(Green_to_BlueTest+ BlueLineTimeTest[7] < GreenLineTimeTest[3]+Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest)
        {
            timeMetro += Green_to_BlueTest+ BlueLineTimeTest[7];
        }
        else
        {
            timeMetro += GreenLineTimeTest[3]+Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest;
        }
    }
}

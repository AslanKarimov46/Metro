#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Metro.h"

std::pair<std::string, int> start;
std::pair<std::string, int> destination;

std::vector<int> RedLineTimeTest{3, 3, 2, 2, 3, 2, 3, 2, 2, 2, 3, 2, 3, 3, 2, 2, 2};
int Red_to_GreenTest=3, Red_to_BlueTest=3, Green_to_BlueTest=3, Green_to_RedTest=3, Blue_to_RedTest=3, Blue_to_GreenTest=3;
std::vector<int> BlueLineTimeTest{2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 3, 4, 2};
std::vector<int> GreenLineTimeTest{2, 4, 5, 2, 2, 2, 2, 3, 5, 2, 4, 4, 2, 2, 2};
//лучше варика я не придумал

TEST_SUITE_BEGIN("Drive test");
TEST_SUITE("Red-Red") {
    TEST_CASE("Житомирская - Университет") {
        int timeMetro = RedLineTimeTest[1] + RedLineTimeTest[2] + RedLineTimeTest[3] + RedLineTimeTest[4] + RedLineTimeTest[5] + RedLineTimeTest[6] + RedLineTimeTest[7];
        find_stations("Житомирская", "Университет", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(1, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(8, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);

    }   //StartRed - StartRed
    TEST_CASE("Университет - Житомирская") {
        int timeMetro = RedLineTimeTest[7] + RedLineTimeTest[6] + RedLineTimeTest[5] + RedLineTimeTest[4] + RedLineTimeTest[3] + RedLineTimeTest[2] + RedLineTimeTest[1];
        find_stations("Университет", "Житомирская", start, destination);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(1, destination.second);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(8, start.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Шулявская", "Днепр", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(5, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(12, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);

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
        find_stations("Днепр", "Шулявская", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(12, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(5, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);

    }   //EndRed - StartRed

    TEST_CASE("Дарница - Арсенальная") {
        int timeMetro = RedLineTimeTest[14]+RedLineTimeTest[13]+RedLineTimeTest[12]+RedLineTimeTest[11];
        find_stations("Дарница", "Арсенальная", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(15, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(11, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);

    }   //EndRed - EndRed
    TEST_CASE("Арсенальная - Дарница") {
        int timeMetro = RedLineTimeTest[11]+RedLineTimeTest[12]+RedLineTimeTest[13]+RedLineTimeTest[14];
        find_stations("Арсенальная", "Дарница", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(11, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(15, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //EndRed - EndRed

    TEST_CASE("Вокзальная - Театральная") {
        int timeMetro = RedLineTimeTest[7]+RedLineTimeTest[8];
        find_stations("Вокзальная", "Театральная", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(7, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(9, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //StartRed - LeftRedChange
    TEST_CASE("Театральная - Вокзальная") {
        int timeMetro = RedLineTimeTest[8]+RedLineTimeTest[7];
        find_stations("Театральная", "Вокзальная", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(9, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(7, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Политехнический институт", "Крещатик", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(6, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(10, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Крещатик", "Политехнический институт", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(10, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(6, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);

    }   //RightRedChange - StartRed

    TEST_CASE("Левобережная - Крещатик") {
        int timeMetro = RedLineTimeTest[13]+RedLineTimeTest[12]+RedLineTimeTest[11]+RedLineTimeTest[10];
        find_stations("Левобережная", "Крещатик", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(14, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(10, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //EndRed - RightRedChange
    TEST_CASE("Крещатик - Левобережная") {
        int timeMetro = RedLineTimeTest[10]+RedLineTimeTest[11]+RedLineTimeTest[12]+RedLineTimeTest[13];
        find_stations("Крещатик", "Левобережная", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(10, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(14, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);

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
        find_stations("Гидропарк", "Театральная", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(13, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(9, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Театральная", "Гидропарк", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(9, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(13, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //LeftRedChange - EndRed
}

TEST_SUITE("Blue-Blue") {
    TEST_CASE("Героев Днепра - Тараса Шевченко") {
        int timeMetro = BlueLineTimeTest[0]+BlueLineTimeTest[1]+BlueLineTimeTest[2]+BlueLineTimeTest[3];
        find_stations("Героев Днепра", "Тараса Шевченко", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(0, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(4, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //StartBlue - StartBlue
    TEST_CASE("Тараса Шевченко - Героев Днепра ") {
        int timeMetro = BlueLineTimeTest[3]+BlueLineTimeTest[2]+BlueLineTimeTest[1]+BlueLineTimeTest[0];
        find_stations("Тараса Шевченко", "Героев Днепра", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(4, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(0, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Петровка", "Лыбедская", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(3, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(11, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);

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
        find_stations("Лыбедская", "Петровка", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(11, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(3, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //EndBlue - StartBlue

    TEST_CASE("Дворец Украина - Голосеевская") {
        int timeMetro = BlueLineTimeTest[10]+BlueLineTimeTest[11]+BlueLineTimeTest[12];
        find_stations("Дворец Украина", "Голосеевская", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(10, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(13, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //EndBlue - EndBlue
    TEST_CASE("Голосеевская - Дворец Украина") {
        int timeMetro = BlueLineTimeTest[12]+BlueLineTimeTest[11]+BlueLineTimeTest[10];
        find_stations("Голосеевская", "Дворец Украина", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(13, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(10, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //EndBlue - EndBlue

    TEST_CASE("Минская - Площадь Независимости") {
        int timeMetro = BlueLineTimeTest[1]+BlueLineTimeTest[2]+BlueLineTimeTest[3]+BlueLineTimeTest[4]+BlueLineTimeTest[5]+BlueLineTimeTest[6];
        find_stations("Минская", "Площадь Независимости", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(1, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(7, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //StartBlue - UpBlueChange
    TEST_CASE("Площадь Независимости - Минская") {
        int timeMetro = BlueLineTimeTest[6]+BlueLineTimeTest[5]+BlueLineTimeTest[4]+BlueLineTimeTest[3]+BlueLineTimeTest[2]+BlueLineTimeTest[1];
        find_stations("Площадь Независимости", "Минская", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(7, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(1, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Оболонь", "Площадь Льва Толстого", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(2, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(8, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);

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
        find_stations("Площадь Льва Толстого", "Оболонь", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(8, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(2, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Ипподром", "Площадь Независимости", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(16, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(7, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Площадь Независимости", "Ипподром", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(7, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(16, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //UpBlueChange - EndBlue

    TEST_CASE("Васильковская - Площадь Льва Толстого") {
        int timeMetro = BlueLineTimeTest[13]+BlueLineTimeTest[12]+BlueLineTimeTest[11]+BlueLineTimeTest[10]+BlueLineTimeTest[9]+BlueLineTimeTest[8];
        find_stations("Васильковская", "Площадь Льва Толстого", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(14, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(8, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //EndBlue - DownBlueChange
    TEST_CASE("Площадь Льва Толстого - Васильковская") {
        int timeMetro = BlueLineTimeTest[8]+BlueLineTimeTest[9]+BlueLineTimeTest[10]+BlueLineTimeTest[11]+BlueLineTimeTest[12]+BlueLineTimeTest[13];
        find_stations("Площадь Льва Толстого", "Васильковская", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(8, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(14, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //DownBlueChange - EndBlue
}

TEST_SUITE("Green-Green") {
    TEST_CASE("Сырец - Лукьяновская") {
        int timeMetro = GreenLineTimeTest[0]+GreenLineTimeTest[1];
        find_stations("Сырец", "Лукьяновская", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(0, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(2, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //StartGreen - StartGreen
    TEST_CASE("Лукьяновская - Сырец") {
        int timeMetro = GreenLineTimeTest[1]+GreenLineTimeTest[0];
        find_stations("Лукьяновская", "Сырец", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(2, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(0, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Дорогожичи", "Позняки", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(1, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(11, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Позняки", "Дорогожичи", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(11, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(1, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //Endgreen - Startgreen

    TEST_CASE("Красный хутор - Славутич") {
        int timeMetro = GreenLineTimeTest[14]+GreenLineTimeTest[13]+GreenLineTimeTest[12]+GreenLineTimeTest[11]+GreenLineTimeTest[10]+GreenLineTimeTest[9];
        find_stations("Красный хутор", "Славутич", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(15, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(9, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //Endgreen - Endgreen
    TEST_CASE("Славутич - Красный хутор") {
        int timeMetro = GreenLineTimeTest[9]+GreenLineTimeTest[10]+GreenLineTimeTest[11]+GreenLineTimeTest[12]+GreenLineTimeTest[13]+GreenLineTimeTest[14];
        find_stations("Славутич", "Красный хутор", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(9, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(15, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Сырец", "Дворец спорта", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(0, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(4, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Дворец спорта", "Сырец", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(4, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(0, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //RightGreenChange - StartGreen

    TEST_CASE("Дорогожичи - Золотые ворота") {
        int timeMetro = GreenLineTimeTest[1]+GreenLineTimeTest[2];
        find_stations("Дорогожичи", "Золотые ворота", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(1, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(3, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //StartGreen - LeftGreenChange
    TEST_CASE("Золотые ворота - Дорогожичи") {
        int timeMetro = GreenLineTimeTest[2]+GreenLineTimeTest[1];
        find_stations("Золотые ворота", "Дорогожичи", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(3, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(1, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }   //LeftGreenChange - StartGreen

    TEST_CASE("Вырлица - Дворец спорта") {
        int timeMetro = GreenLineTimeTest[12]+GreenLineTimeTest[11]+GreenLineTimeTest[10]+GreenLineTimeTest[9]+GreenLineTimeTest[8]+GreenLineTimeTest[7]+GreenLineTimeTest[6]+GreenLineTimeTest[5]+GreenLineTimeTest[4];
        find_stations("Вырлица", "Дворец спорта", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(13, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(4, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);

    }   //EndGreen - RightGreenChange
    TEST_CASE("Дворец спорта - Вырлица") {
        int timeMetro = GreenLineTimeTest[4]+GreenLineTimeTest[5]+GreenLineTimeTest[6]+GreenLineTimeTest[7]+GreenLineTimeTest[8]+GreenLineTimeTest[9]+GreenLineTimeTest[10]+GreenLineTimeTest[11]+GreenLineTimeTest[12];
        find_stations("Дворец спорта", "Вырлица", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(4, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(13, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Выдубичи", "Золотые ворота", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(8, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(3, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
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
        find_stations("Золотые ворота", "Выдубичи", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(3, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(8, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);

    }   //LeftGreenChange - EndGreen
}
TEST_SUITE_END();






TEST_SUITE("One-Two")
{
    TEST_CASE("Берестейская (RED) -  Выставочный центр (BLUE)") {
        int timeMetro =
                RedLineTimeTest[4] + RedLineTimeTest[5] + RedLineTimeTest[6] + RedLineTimeTest[7] + RedLineTimeTest[8] +
                BlueLineTimeTest[8] + BlueLineTimeTest[9] + BlueLineTimeTest[10] + BlueLineTimeTest[11] +
                BlueLineTimeTest[12] + BlueLineTimeTest[13] + BlueLineTimeTest[14];
        if (Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest <
            RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7]) {
            timeMetro += Red_to_GreenTest + GreenLineTimeTest[3] + Green_to_BlueTest;
        } else {
            timeMetro += RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7];
        }
        find_stations("Берестейская", "Выставочный центр", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(4, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(15, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }

    TEST_CASE("Контрактовая площадь (BLUE) - Дарница (RED)") {
        int timeMetro = BlueLineTimeTest[5] + BlueLineTimeTest[6] + RedLineTimeTest[10] + RedLineTimeTest[11] +
                        RedLineTimeTest[12] + RedLineTimeTest[13] + RedLineTimeTest[14];
        if (Blue_to_RedTest <
            BlueLineTimeTest[7] + Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest + RedLineTimeTest[9]) {
            timeMetro += Blue_to_RedTest;
        } else {
            timeMetro += BlueLineTimeTest[7] + Blue_to_GreenTest + GreenLineTimeTest[3] + Green_to_RedTest +
                         RedLineTimeTest[9];
        }
        find_stations("Контрактовая площадь", "Дарница", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(5, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(15, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }

    TEST_CASE("Нивки (RED) - Бориспольская (GREEN)") {
        int timeMetro =
                RedLineTimeTest[3] + RedLineTimeTest[4] + RedLineTimeTest[5] + RedLineTimeTest[6] + RedLineTimeTest[7] +
                RedLineTimeTest[8] + GreenLineTimeTest[4] + GreenLineTimeTest[5] + GreenLineTimeTest[6] +
                GreenLineTimeTest[7] + GreenLineTimeTest[8] + GreenLineTimeTest[9] + GreenLineTimeTest[10] +
                GreenLineTimeTest[11] + GreenLineTimeTest[12] + GreenLineTimeTest[13];
        if (Red_to_GreenTest + GreenLineTimeTest[3] <
            RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest) {
            timeMetro += Red_to_GreenTest + GreenLineTimeTest[3];
        } else {
            timeMetro += RedLineTimeTest[9] + Red_to_BlueTest + BlueLineTimeTest[7] + Blue_to_GreenTest;
        }
        find_stations("Нивки", "Бориспольская", start, destination);
        CHECK_EQ("stations_red", start.first);
        CHECK_EQ(3, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(14, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }

    TEST_CASE("Дорогожичи (GREEN) - Лесная (RED)") {
        int timeMetro = GreenLineTimeTest[1] + GreenLineTimeTest[2] + RedLineTimeTest[10] + RedLineTimeTest[11] +
                        RedLineTimeTest[12] + RedLineTimeTest[13] + RedLineTimeTest[14] + RedLineTimeTest[15] +
                        RedLineTimeTest[16];
        if (Green_to_RedTest + RedLineTimeTest[9] <
            GreenLineTimeTest[3] + Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest) {
            timeMetro += Green_to_RedTest + RedLineTimeTest[9];
        } else {
            timeMetro += GreenLineTimeTest[3] + Green_to_BlueTest + BlueLineTimeTest[7] + Blue_to_RedTest;
        }
        find_stations("Дорогожичи", "Лесная", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(1, start.second);
        CHECK_EQ("stations_red", destination.first);
        CHECK_EQ(17, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }

    TEST_CASE("Теремки (BLUE) - Сырец (GREEN)") {
        int timeMetro = BlueLineTimeTest[16] + BlueLineTimeTest[15] + BlueLineTimeTest[14] + BlueLineTimeTest[13] +
                        BlueLineTimeTest[12] + BlueLineTimeTest[11] + BlueLineTimeTest[10] + BlueLineTimeTest[9] +
                        BlueLineTimeTest[8] + GreenLineTimeTest[2] + GreenLineTimeTest[1] + GreenLineTimeTest[0];
        if (Blue_to_GreenTest + GreenLineTimeTest[3] <
            BlueLineTimeTest[7] + Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest) {
            timeMetro += Blue_to_GreenTest + GreenLineTimeTest[3];
        } else {
            timeMetro += BlueLineTimeTest[7] + Blue_to_RedTest + RedLineTimeTest[9] + Red_to_GreenTest;
        }
        find_stations("Теремки", "Сырец", start, destination);
        CHECK_EQ("stations_blue", start.first);
        CHECK_EQ(17, start.second);
        CHECK_EQ("stations_green", destination.first);
        CHECK_EQ(0, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }

    TEST_CASE("Красный Хутор (GREEN) - Героев Днепра (BLUE)") {
        int timeMetro = GreenLineTimeTest[14] + GreenLineTimeTest[13] + GreenLineTimeTest[12] + GreenLineTimeTest[11] +
                        GreenLineTimeTest[10] + GreenLineTimeTest[9] + GreenLineTimeTest[8] + GreenLineTimeTest[7] +
                        GreenLineTimeTest[6] + GreenLineTimeTest[5] + GreenLineTimeTest[4] + BlueLineTimeTest[6] +
                        BlueLineTimeTest[5] + BlueLineTimeTest[4] + BlueLineTimeTest[3] + BlueLineTimeTest[2] +
                        BlueLineTimeTest[1] + BlueLineTimeTest[0];
        if (Green_to_BlueTest + BlueLineTimeTest[7] <
            GreenLineTimeTest[3] + Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest) {
            timeMetro += Green_to_BlueTest + BlueLineTimeTest[7];
        } else {
            timeMetro += GreenLineTimeTest[3] + Green_to_RedTest + RedLineTimeTest[9] + Red_to_BlueTest;
        }
        find_stations("Красный хутор", "Героев Днепра", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(15, start.second);
        CHECK_EQ("stations_blue", destination.first);
        CHECK_EQ(0, destination.second);
        CHECK_EQ(route(start, destination), timeMetro);
    }
    TEST_CASE("Красный Хутор (GREEN) - Красный Хутор (GREEN)")
    {
        find_stations("Красный хутор", "Красный хутор", start, destination);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(15, start.second);
        CHECK_EQ("stations_green", start.first);
        CHECK_EQ(15, start.second);
        CHECK_EQ(route(start, destination), 0);

    }
}
    TEST_CASE("Этих станций на самом деле нет.")
    {
        CHECK_THROWS(find_stations("Такой", "СтанцииНет", start, destination));
        CHECK_THROWS_WITH(find_stations("Такой", "Сырец", start, destination), "Первая станция не найдена. Повторите ввод: ");
        CHECK_THROWS_WITH(find_stations("Теремки", "СтанцииНет", start, destination), "Вторая станция не найдена. Повторите ввод: ");
    }

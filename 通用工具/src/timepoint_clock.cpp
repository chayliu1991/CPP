#include <chrono>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

template <typename C>
void print_clock_data()
{
    cout << "- presion: ";
    typedef typename C::period P;
    if (ratio_less_equal<P, milli>::value)
    {
        typedef typename ratio_multiply<P, kilo>::type TT;
        cout << fixed << double(TT::num) / TT::den << " milliseconds" << endl;
    }
    else
    {
        cout << fixed << double(P::num) / P::den << " seconds" << endl;
    }
    cout << "- is_steady: " << boolalpha << C::is_steady << endl;
}

void test()
{
    double num = 10.0;
    for (int i = 0; i < 100; ++i)
    {
        for (int i = 0; i < 1000000; ++i)
        {
            auto temp = num * num + num;
        }
    }
}

std::string as_string(const std::chrono::system_clock::time_point &tp)
{
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
std:
    string ts = std::ctime(&t);
    ts.resize(ts.size() - 1);
    return ts;
}

inline std::chrono::system_clock::time_point make_time_pont(int year, int mon, int day, int hour, int min, int sec = 0)
{
    struct std::tm t;
    t.tm_sec = sec;
    t.tm_min = min;
    t.tm_hour = hour;
    t.tm_mday = day;
    t.tm_mon = mon - 1;
    t.tm_year = year - 1900;
    t.tm_isdst = -1;
    std::time_t tt = std::mktime(&t);
    if (tt == -1)
    {
        throw "no valid system time";
    }
    return std::chrono::system_clock::from_time_t(tt);
}

int main()
{
    {
        std::cout << "system_clock: " << std::endl;
        print_clock_data<std::chrono::system_clock>();

        std::cout << "high_resolution_clock: " << std::endl;
        print_clock_data<std::chrono::high_resolution_clock>();

        std::cout << "steady_clock: " << std::endl;
        print_clock_data<std::chrono::steady_clock>();
    }

    {
        auto system_start = chrono::system_clock::now();
        test();
        auto diff = chrono::system_clock::now() - system_start;
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
        cout << "run test cost : " << ms << " milliseconds" << endl;
    }

    {
        std::chrono::system_clock::time_point tp;
        std::cout << "epoch: " << as_string(tp) << std::endl;

        tp = std::chrono::system_clock::now();
        std::cout << "now: " << as_string(tp) << std::endl;
    }

    {
        std::chrono::time_point<std::chrono::system_clock> tp = std::chrono::system_clock::now() + std::chrono::hours(1);
        std::cout << "time_since_epoch: " << tp.time_since_epoch().count() << std::endl;
    }

    {
        auto tp1 = make_time_pont(2021, 1, 10, 3, 26, 32);
        std::cout << as_string(tp1) << std::endl;
    }

    return 0;
}
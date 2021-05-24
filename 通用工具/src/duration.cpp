#include <chrono>
#include <iostream>

using namespace std;

template <typename V, typename R>
ostream &operator<<(ostream &s, const std::chrono::duration<V, R> &dura)
{
    s << "[" << dura.count() << " of " << R::num << " / " << R::den << "]";
    return s;
}

int main()
{
    {
        std::chrono::duration<int> twenty_seconds(20);
        std::chrono::duration<double, std::ratio<60>> half_minutes(0.5);
        std::chrono::duration<long, std::ratio<1, 1000>> one_millseconds(1);

        std::chrono::seconds two_seconds(2);
        std::chrono::hours ten_hours(10);
        std::chrono::milliseconds eright_milliseconds(8);

        chrono::duration<double, ratio<1, 3>> d1(1);
        chrono::duration<double, ratio<1, 5>> d2(1);
        auto res = d1 + d2;

        std::chrono::hours a_day(24);
        std::cout << std::chrono::minutes(a_day).count() << " minutes" << std::endl;
        std::cout << std::chrono::seconds(a_day).count() << " seconds" << std::endl;

        std::chrono::seconds sec(0);
        sec += a_day;
        std::cout << sec.count() << " seconds" << std::endl;
        std::cout << std::chrono::milliseconds(sec).count() << " milliseconds" << std::endl;

        std::chrono::milliseconds d(42);
        std::cout << d << std::endl;

        std::chrono::seconds s(123);
        std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>(s);
        cout << m << endl;
    }

    return 0;
}
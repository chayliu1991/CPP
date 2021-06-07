#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>

int main(int argc, char *argv[])
{
    auto now = std::chrono::system_clock::now();
    time_t t = std::chrono::system_clock::to_time_t(now);
    tm *nowTm = localtime(&t);
    std::cout << std::put_time(nowTm, "date:%x\ntime:%X\n") << std::endl;

    tm date{};
    std::cout << "new date: ";
    std::cin >> std::get_time(&date, "%x");
    if (!std::cin)
        std::cout << "invalid format read" << std::endl;

    return 0;
}

#include <iostream>
#include <sstream>
#include <bitset>
#include <tuple>
#include <utility>

std::tuple<std::string, std::string, std::string> parseName(std::string name)
{
    std::string s1, s2, s3;
    std::istringstream(name) >> s1 >> s2 >> s3;
    if (s3.empty())
    {
        return std::tuple<std::string, std::string, std::string>(std::move(s1), "", std::move(s2));
    }
    else
    {
        return std::tuple<std::string, std::string, std::string>(std::move(s1), std::move(s2), std::move(s3));
    }
}

int main(int argc, char *argv[])
{
    {
        std::ostringstream os;
        os << "dec: " << 15 << std::hex << " hex: " << 15 << std::endl;
        std::cout << os.str() << std::endl;

        std::bitset<15> b(5789);
        os << "float: " << 4.67 << " bitset: " << b << std::endl;
        os.seekp(0);
        os << "oct: " << std::oct << 15;
        std::cout << os.str() << std::endl;
    }

    {
        auto t1 = parseName("Nicolai M. Josuttis");
        std::cout << "firstname: " << std::get<0>(t1) << std::endl;
        std::cout << "middlename: " << std::get<1>(t1) << std::endl;
        std::cout << "lastname: " << std::get<2>(t1) << std::endl;

        auto t2 = parseName("Nicolai Josuttis");
        std::cout << "firstname: " << std::get<0>(t2) << std::endl;
        std::cout << "middlename: " << std::get<1>(t2) << std::endl;
        std::cout << "lastname: " << std::get<2>(t2) << std::endl;
    }

    return 0;
}
#include <string>
#include <iostream>
#include <limits>
#include <exception>

int main(int argc, char *argv[])
{
    {
        try
        {
            std::cout << std::stoi("  777") << std::endl;
            std::cout << std::stod("  77.7") << std::endl;
            std::cout << std::stod("  -0x77") << std::endl;

            std::size_t idx;
            std::cout << std::stoi("42 is the truth,", &idx) << std::endl;
            std::cout << "unconvert idx: " << idx << std::endl;

            std::cout << std::stoi("   42", nullptr, 16) << std::endl;
            std::cout << std::stoi("   789", &idx, 8) << std::endl;
            std::cout << "unconvert idx: " << idx << std::endl;

            long long ll = std::numeric_limits<long long>::max();
            std::string s = std::to_string(ll);
            std::cout << s << std::endl;

            std::cout << std::stoi(s) << std::endl; //@ throw
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}

#include <regex>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::string data = "<person>\n"
                       "<first>Nico</first>\n"
                       "<last>Josuttis</last>\n"
                       "</person>\n";
    std::regex reg("<(.*)>(.*)</(\\1)>");

    //@ 关注的是整个匹配以及每次匹配的第二个 substring
    std::sregex_token_iterator pos(data.cbegin(), data.cend(), reg, {0, 2}); //@ 0: full match,2: second substring
    std::sregex_token_iterator end;
    for (; pos != end; ++pos)
    {
        std::cout << "match: " << pos->str() << std::endl;
    }
    std::cout << std::endl;

    std::string names = "nico,jim,helmut,paul,tim,john.paul,rita;hjta";
    std::regex sep("[\t\n]*[,;.][\t\n]*");
    std::sregex_token_iterator p(names.cbegin(), names.cend(), sep, -1); //@ -1,values between seperators
    std::sregex_token_iterator e;
    std::vector<std::string> vec(p, e);
    std::for_each(vec.cbegin(), vec.cend(), [](const std::string &s)
                  { std::cout << "name: " << s << std::endl; });

    return 0;
}
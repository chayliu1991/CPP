#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <regex>
#include <locale>

int main(int argc, char *argv[])
{
    {
        std::string s("The Zip Code of Brauschweig in Germany is 381000");
        std::cout << "original: " << s << std::endl;

        std::transform(s.cbegin(), s.cend(), s.begin(), [](char c)
                       { return tolower(c); });
        std::cout << "lowered: " << s << std::endl;

        std::for_each(s.begin(), s.end(), [](char &c)
                      { c = toupper(c); });
        std::cout << "uppered: " << s << std::endl;

        std::string search("Germany");
        std::string::const_iterator pos;
        pos = std::search(s.cbegin(), s.cend(), search.cbegin(), search.cend(), [](char c1, char c2)
                          { return toupper(c1) == toupper(c2); });
        if (pos != s.cend())
        {
            std::cout << search << " >> " << s << std::endl;
        }
    }

    {
        std::string s("The Zip Code of Brauschweig in Germany is 381000");
        std::regex p("Germany", std::regex_constants::icase);
        std::smatch sm;
        if (std::regex_search(s, sm, p))
        {
            std::cout << "position: " << sm.position() << std::endl;
        }
    }

    {
        const std::string hello("Hello,how are you?");
        std::string s(hello.begin(), hello.end());
        for (const auto c : s)
        {
            std::cout << c;
        }
        std::cout << std::endl;

        std::reverse(s.begin(), s.end());
        std::cout << "reversed: " << s << std::endl;

        std::sort(s.begin(), s.end());
        std::cout << "sorted: " << s << std::endl;

        s.erase(std::unique(s.begin(), s.end()), s.end());
        std::cout << "unique: " << s << std::endl;
    }

    {
        std::string input;
        //@ 不跳过前导空白
        std::cin.unsetf(std::ios::skipws);

        const std::locale &loc(std::cin.getloc());

        std::unique_copy(std::istream_iterator<char>(std::cin), std::istream_iterator<char>(),
                         std::back_inserter(input), [=](char c1, char c2)
                         { return isspace(c1, loc) && isspace(c2, loc); });
        std::cout << input << std::endl;
    }

    return 0;
}

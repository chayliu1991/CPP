#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    {
        //@ 构造
        std::string s0;
        std::string s{"hello"};
        std::string s1(s);

        std::string s2(s, 2);
        std::string s3(s, 2, 2);

        char *sp = "world";
        std::string s4(sp);
        std::string s5(sp, 3);

        std::string s6(10, 'h');

        std::string s7(s.begin(), s.end());
        std::string s8(std::move(s));
    }

    {
        //@ string 与 C-String
        std::string s("12345");
        atoi(s.c_str());

        try
        {
            char buf[100] = {};
            s.copy(buf, 100);
            std::cout << buf << std::endl;

            s.copy(buf, 100, 3);
            std::cout << buf << std::endl;

            s.copy(buf, 100, s.length() + 1); //@ throw
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    {
        const std::string cs("nico");
        const std::string s("abcde");
        const std::string t;

        try
        {
            std::cout << s[2] << std::endl;
            std::cout << s.at(2) << std::endl;
            std::cout << s.front() << std::endl;
            std::cout << s.back() << std::endl;

            std::cout << cs[cs.length()] << std::endl;    //@ C++11 之后 '\0'
            std::cout << cs.at(cs.length()) << std::endl; //@ throw
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::string s1 = {"abcde"};
        std::cout << s1.compare("abcd") << std::endl;
        std::cout << s1.compare("abcdef") << std::endl;
        std::cout << s1.compare("abcde") << std::endl;

        std::cout << s1.compare(s1) << std::endl;

        std::cout << s1.compare(1, 2, "bc", 2) << std::endl;
        std::cout << s1.compare(0, 2, "abd", 3) << std::endl;
    }

    {
        const std::string aString("othello");
        std::string s;
        s = aString;
        s = "two\nlines";
        s = 'c';

        s.assign(aString);
        s.assign(aString, 2);
        std::cout << s << std::endl;
        s.assign(aString, 1, 4);
        std::cout << s << std::endl;
        s.assign(aString, 2, std::string::npos);
        std::cout << s << std::endl;

        s.assign("two\nlines");
        std::cout << s << std::endl;
        s.assign("hello", 6); //@ 'h', 'e', 'l', 'l', 'l', 'o','\0'
        std::cout << s << std::endl;
        s.assign(6, 'x');
        std::cout << s << std::endl;
    }

    {
        const std::string aString("nihao,shijie");
        std::string s;

        s += aString;
        s += "two\nlines";
        s += '\n';
        s += {'o', 'k'};

        s.clear();
        s.append(aString);
        std::cout << s << std::endl;
        s.clear();
        s.append(aString, 0, 5);
        std::cout << s << std::endl;
        s.append(aString, 5); //@ s.append(aString,5,std::string::npos);
        std::cout << s << std::endl;
        s.clear();
        s.append("two\nlines");
        s.append("nico", 5);
        s.append(5, 'x');
        s.push_back('y');
        s.push_back('\n');
    }

    {
        const std::string aString("age");
        std::string s("p");
        s.insert(1, aString);
        std::cout << s << std::endl;

        s.insert(1, "ersifl");
        std::cout << s << std::endl;

        s.insert(0, " ");
        s.insert((std::string::size_type)0, 1, ' ');
    }
    {
        std::string s = "i18nd";
        s.pop_back();
        s.replace(1, 2, "hhhhdasdasdasd");
        std::cout << s << std::endl;

        s.erase(10);
        std::cout << s << std::endl;

        s.erase(3, 6);
        std::cout << s << std::endl;
    }

    {
        std::string s("interchangeablity");
        std::string sub;
        sub = s.substr();
        std::cout << sub << std::endl;

        sub = s.substr(11);
        std::cout << sub << std::endl;

        sub = s.substr(5, 7);
        std::cout << sub << std::endl;

        sub = s.substr(s.find('c'));
        std::cout << sub << std::endl;
    }

    {
        std::string s1("enter");
        std::string s2("nation");
        std::string i18n;

        i18n = 'i' + s1.substr(1) + s2 + "aliz" + s2.substr(1);
        std::cout << i18n << std::endl;
    }

    {
        std::string s1("enter");
        std::string s2("nation");

        std::string s3 = std::move(s1) + std::move(s2);
        std::cout << s3 << std::endl;
    }

    {
        std::string s("hi Bill,I'm sb,so please pay th bill");

        std::cout << s.find("sb") << std::endl;
        std::cout << s.find("sb", 5) << std::endl;
        std::cout << s.rfind("sb") << std::endl;

        std::cout << s.find_first_not_of("sb") << std::endl;
        std::cout << s.find_last_of("sb", 5) << std::endl;
        std::cout << s.find_first_not_of("sb") << std::endl;
        std::cout << s.find_last_not_of("sb") << std::endl;
        std::cout << s.find("dsadsdsb") << std::endl;
    }

    return 0;
}
#include <string>
#include <iostream>

//@ prog.dat mydir hello. oops.tmp end.dat data.raw
int main(int argc, char *argv[])
{
    std::string filename, basename, extname, tmpname;
    const std::string suffix("tmp");

    for (int i = 1; i < argc; ++i)
    {
        filename = argv[i];
        std::string::size_type idx = filename.find('.');
        if (idx == std::string::npos)
        {
            tmpname = filename + '.' + suffix;
        }
        else
        {
            basename = filename.substr(0, idx);
            extname = filename.substr(idx + 1);

            if (extname.empty())
            {
                tmpname = filename;
                tmpname += suffix;
            }
            else if (extname == suffix)
            {
                tmpname = filename;
                tmpname.replace(idx + 1, extname.size(), "xxx");
            }
            else
            {
                tmpname = filename;
                tmpname.replace(idx + 1, std::string::npos, suffix);
            }
        }

        std::cout << filename << " => " << tmpname << std::endl;
    }

    return 0;
}

#include <bitset>
#include <iostream>

int main()
{
    {
        enum Color
        {
            red,
            yellow,
            green,
            blue,
            white,
            black,
            numofColors
        };
        std::bitset<numofColors> usedColors;
        usedColors.set(red);
        usedColors.set(blue);

        std::cout << "bitfield of used colors: " << usedColors << std::endl;
        std::cout << "number of used colors: " << usedColors.count() << std::endl;
        std::cout << "bitfield of unused colors: " << ~usedColors << std::endl;

        if (usedColors.any())
        {
            for (int c = 0; c < numofColors; ++c)
            {
                if (usedColors[Color(c)])
                {
                    std::cout << "use color: " << c << std::endl;
                }
            }
        }
    }

    {
        std::cout << "267 as binary short: " << std::bitset<std::numeric_limits<unsigned short>::digits>(267) << std::endl;
        std::cout << "10,000,000 with 24 bits: " << std::bitset<24>(1e7) << std::endl;
        std::cout << "\"1010010011\" as number: " << std::bitset<100>("1010010011").to_ullong() << std::endl;
    }
    return 0;
}

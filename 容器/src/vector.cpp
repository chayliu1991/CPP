#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename C>
void PRINT_ELEMENTS(const C &c, const std::string &prefix)
{
    std::cout << prefix;
    for (auto const &elem : c)
        std::cout << elem << " ";
    std::cout << std::endl;
}

int main()
{
    {
        std::vector<int> coll{1, 2, 3, 3, 4, 5, 8, 9, 3};
        coll.erase(std::remove(coll.begin(), coll.end(), 3), coll.end());
        PRINT_ELEMENTS(coll, "after erase:");

        auto pos = std::find(coll.begin(), coll.end(), 5);
        coll.erase(pos);
        PRINT_ELEMENTS(coll, "after erase first 5:");
    }

    {
        std::vector<char> coll(64);
        strcpy(coll.data(), "hello,world");
        printf("%s\n", coll.data());
    }

    {
        std::vector<std::string> sentences;
        sentences.reserve(5);
        sentences.push_back("Hello");
        sentences.insert(sentences.end(), {"how", "are", "you", "man", "?"});
        PRINT_ELEMENTS(sentences, "sentences is: ");
        std::cout << "sentences max_size: " << sentences.max_size() << std::endl;
        std::cout << "sentences size: " << sentences.size() << std::endl;
        std::cout << "sentences capacity: " << sentences.capacity() << std::endl;
        std::swap(sentences[1], sentences[3]);
        PRINT_ELEMENTS(sentences, "sentences after swap is: ");

        sentences.shrink_to_fit();
        std::cout << "sentences size after shrink_to_fit: " << sentences.size() << std::endl;
        std::cout << "sentences capacity after shrink_to_fit: " << sentences.capacity() << std::endl;
    }
    return 0;
}
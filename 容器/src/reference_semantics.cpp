#include <iostream>
#include <deque>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <memory>

class Item
{
private:
    std::string name;
    float price;

public:
    Item(const std::string &n, float p = 0) : name(n), price(p)
    {
    }

    std::string get_name() const
    {
        return name;
    }

    void set_name(const std::string &n)
    {
        name = n;
    }

    float get_price() const
    {
        return price;
    }

    void set_price(float p)
    {
        price = p;
    }
};

template <typename Coll>
void print_items(const std::string &msg, const Coll &coll)
{
    std::cout << msg << std::endl;
    for (const auto &elem : coll)
    {
        std::cout << "	" << elem->get_name() << ":" << elem->get_price() << std::endl;
    }
}

int main()
{
    {
        typedef std::shared_ptr<Item> ItemPtr;

        std::set<ItemPtr> allItems;
        std::deque<ItemPtr> bestsellers;

        bestsellers = {ItemPtr(new Item("Kong Yize", 20.10)), ItemPtr(new Item("A Midsummer", 14.98)), ItemPtr(new Item("The MAltess Falcon", 8.78))};
        allItems = {ItemPtr(new Item("Water", 0.65)), ItemPtr(new Item("Pizza", 1.76))};
        allItems.insert(bestsellers.begin(), bestsellers.end());

        print_items("bestsellers:", bestsellers);
        print_items("allItems:", allItems);

        std::for_each(allItems.begin(), allItems.end(), [](ItemPtr ptr)
                      { ptr->set_price(ptr->get_price() * 2); });
        print_items("allItems:", allItems);

        bestsellers[1] = *std::find_if(allItems.begin(), allItems.end(), [](ItemPtr ptr)
                                       { return ptr->get_name() == "Pizza"; });
        print_items("bestsellers:", bestsellers);

        bestsellers[0]->set_price(99.08);
        print_items("bestsellers:", bestsellers);
    }

    {
        std::vector<std::reference_wrapper<Item>> books;
        Item f("Faust", 12.65);
        books.push_back(f);

        for (const auto &book : books)
        {
            std::cout << book.get().get_name() << ":" << book.get().get_price() << std::endl;
        }

        f.set_name("Jikee");
        std::cout << books[0].get().get_name() << std::endl;
    }

    return 0;
}
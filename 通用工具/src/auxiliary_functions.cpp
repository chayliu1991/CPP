#include <algorithm>
#include <iostream>

bool int_ptr_less(int *a, int *b)
{
    return *a < *b;
}

class MyContainter
{
private:
    int *elems;
    int num_elements;

public:
    void swap(MyContainter &ths)
    {
        std::swap(elems, ths.elems);
        std::swap(num_elements, ths.num_elements);
    }
};
//@ 全局的 swap 接口
inline void swap(MyContainter &c1, MyContainter &c2) noexcept(noexcept(c1.swap(c2)))
{
    c1.swap(c2);
}

int main()
{
    {
        int x = 17;
        int y = 42;
        int z = 33;

        int *px = &x;
        int *py = &y;
        int *pz = &z;

        int *pmax = std::max(px, py, int_ptr_less);
        std::pair<int *, int *> extremes = std::minmax({px, py, pz}, int_ptr_less);
    }

    int i = 1;
    long l = 10L;
    std::swap(i, l); //@ 错误，类型不一致

    return 0;
}
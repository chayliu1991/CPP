#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

struct ClassA
{
    ClassA(int val) { cout << "ClassA(int val)" << endl; }
    ~ClassA() { cout << "~ClassA" << endl; }
};

class ClassB
{
private:
    //@ 类中包含 raw 指针，析构时需要主动释放
    ClassA *ptr1;
    ClassA *ptr2;

    //@ 使用 unique_ptr 则不需要显示释放
    //std::unique_ptr<ClassA> ptr1;
    //std::unique_ptr<ClassA> ptr2;
public:
    ClassB(int val1, int val2) : ptr1(new ClassA(val1)), ptr2(new ClassA(val2)) {}
    ClassB(const ClassB &x) : ptr1(new ClassA(*x.ptr1)), ptr2(new ClassA(*x.ptr2)) {}

    const ClassB &operator=(const ClassB &x)
    {
        *ptr1 = *x.ptr1;
        *ptr2 = *x.ptr2;
        return *this;
    }

    ~ClassB()
    {
        delete ptr1;
        delete ptr2;
    }
};

struct Dir
{
};
class DirCloser
{
public:
    void operator()()
    {
        std::cout << "dir close" << std::endl;
    }
};

//@ 自定义删除器，需要指明类型
template <typename T>
using uniquePtr = std::unique_ptr<T, void (*)(T *)>;

struct Base
{
};
struct Derived : public Base
{
};

int main()
{
    std::unique_ptr<string> up(new string("nico"));
    (*up)[0] = 'N';
    up->append("lai");
    cout << *up << endl;

    string *sp = up.release(); //@ up 放弃拥有权
    cout << *sp << endl;
    if (up == nullptr)
        cout << "up is nullptr" << endl;

    up = nullptr;
    up.reset();

    string *p = new string("hello");
    unique_ptr<string> up1(p);
    //unique_ptr<string> up2(p); //@ 错误，up1 和 up2 拥有同一份数据

    std::unique_ptr<int> pi{new int(10)};
    //std::unique_ptr<int> pi_2(pi); //@ 错误，不支持拷贝操作
    std::unique_ptr<int> pi_3(std::move(pi)); //@ 正确，支持移动

    {
        ClassB cb(1, 2);
    }

    std::unique_ptr<std::string[]> strings(new std::string[10]);
    strings[0] = "hello";
    strings[1] = "world";

    {
        uniquePtr<int> unip(new int[10], [](int *p)
                            { delete p; });
    }

    std::unique_ptr<Base[]> bup(new Base[10]); //@ 正确
    //std::unique_ptr<Base[]> bup(new Derived[10]); //@ 错误

    return 0;
}

#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <vector>

template <typename T>
void foo(const T &val)
{
    if (std::is_pointer<T>::value)
    {
        cout << "foo() called for a pointer" << endl;
    }
    else
    {
        cout << "foo() called for a value" << endl;
    }
}

template <typename T>
void foo_impl(T val, std::true_type)
{
    cout << "integral is called" << endl;
}

template <typename T>
void foo_impl(T val, std::false_type)
{
    cout << "not integral is called" << endl;
}

template <typename T>
void foo_impl(T val)
{
    foo_impl(val, std::is_integral<T>());
}

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type min(const T1 &x, const T2 &y)
{
    return x < y ? x : y;
}

template <typename T>
void func(T val)
{
    std::cout << typeid(val).name() << endl;
}

void f(int x, int y)
{
    cout << "x + y = " << x + y << endl;
}

class C
{
public:
    void memfunc(int x, int y)
    {
        cout << "x + y = " << x + y << endl;
    }
};

int main()
{
    {
        int *p = new int(2);
        foo(p);
        foo(2);
        delete p;
    }

    {
        foo_impl(2);
        foo_impl(3.14);
    }

    {
        auto min_int_long = min(1, 20L);
    }

    {
        cout << "========================== is_const ==========================\n";
        cout << boolalpha;
        cout << std::is_const<int>::value << endl;
        cout << std::is_const<const volatile int>::value << endl;
        cout << std::is_const<int *const>::value << endl;
        cout << std::is_const<int *const *>::value << endl;
        cout << std::is_const<const int[]>::value << endl;
    }

    {
        //@ 第一个类型如果是 noclass 类型，永远将获得 false_type
        cout << "========================== is_assignable ==========================\n";
        cout << boolalpha;
        cout << std::is_assignable<int, int>::value << endl;
        cout << std::is_assignable<int &, int>::value << endl;
        cout << std::is_assignable<int &&, int>::value << endl;
        cout << std::is_assignable<int *, int>::value << endl;
        cout << std::is_assignable<long, int>::value << endl;
    }

    {
        cout << "========================== is_constructible ==========================\n";
        cout << boolalpha;
        cout << std::is_constructible<int>::value << endl;
        cout << std::is_constructible<int, int>::value << endl;
        cout << std::is_constructible<int &, int>::value << endl;
        cout << std::is_constructible<int &&, int>::value << endl;
        cout << std::is_constructible<long, int>::value << endl;
    }

    {
        typedef const int &T;
        add_const<T>::type;            //@ const int&
        add_lvalue_reference<T>::type; //@ const int&
        add_rvalue_reference<T>::type; //@ const int& (lvalue remains lvalue)
        add_pointer<T>::type;          //@ const int*
        //make_signed<T>::type;			 //@ undefined behavior
        //make_unsigned<T>::type;			 //@ undefined behavior
        remove_const<T>::type;     //@ const int&
        remove_reference<T>::type; //@ const int
        remove_pointer<T>::type;   //@ const int&
    }

    {
        cout << "========================== rank ==========================\n";
        cout << rank<int>::value << endl;
        cout << rank<int[5]>::value << endl;
        cout << rank<int[][7]>::value << endl;
        cout << rank<int[5][7]>::value << endl;
    }

    {
        cout << "========================== extent ==========================\n";
        cout << extent<int>::value << endl;
        cout << extent<int[5]>::value << endl;
        cout << extent<int[][7]>::value << endl;
        cout << extent<int[5][7]>::value << endl;
        cout << extent<int[5][7], 0>::value << endl;
        cout << extent<int[5][7], 1>::value << endl;
        cout << extent<int[5][7], 2>::value << endl;
    }

    {
        remove_extent<int>::type;       //@ int
        remove_extent<int[]>::type;     //@ int
        remove_extent<int[5]>::type;    //@ int
        remove_extent<int[][7]>::type;  //@ int[7]
        remove_extent<int[5][7]>::type; //@ int[7]

        remove_all_extents<int>::type;       //@ int
        remove_all_extents<int[]>::type;     //@ int
        remove_all_extents<int[5]>::type;    //@ int
        remove_all_extents<int[][7]>::type;  //@ int
        remove_all_extents<int[5][7]>::type; //@ int
    }

    {
        cout << "========================== ref wrapper ==========================\n";
        int i = 10;
        func(std::ref(i));
        func(std::cref(i));
    }

    {
        std::vector<std::function<void(int, int)>> tasks;
        tasks.push_back(f);
        tasks.push_back([](int x, int y)
                        { cout << "x + y = " << x + y << endl; });

        for (const auto t : tasks)
            t(1, 2);
    }

    return 0;
}
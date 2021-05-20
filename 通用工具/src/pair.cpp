#include <utility>
#include <iostream>
#include <tuple>

using namespace std;

class Foo
{
public:
	Foo(tuple<int, float>)
	{
		cout << "Foo::Foo(tuple<int, float>)" << endl;
	}

	template <typename ... Args>
	Foo(Args...args)
	{
		cout << "Foo::Foo(Args...args)" << endl;
	}
};

int main()
{
	tuple<int, float> t(1,3.12);
	pair<int, Foo> p1(42,t);

	//@ 被迫使用接受 tuple 元素的构造函数，而不是 tuple 整体的构造函数
	//@ 两个实参必须是 tuple 才能被迫导致这个行为
	pair<int, Foo> p2(piecewise_construct, make_tuple(42),t);
	return 0;
}
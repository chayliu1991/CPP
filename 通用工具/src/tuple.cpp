#include <iostream>
#include <complex>
#include <string>
#include <tuple>

using namespace std;
template <int IDX, int MAX, typename... Args>
struct PrintTuple
{
	static void print(std::ostream &strm, const std::tuple<Args...> &t)
	{
		strm << std::get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
		PrintTuple<IDX + 1, MAX, Args...>::print(strm, t);
	}
};

template <int MAX, typename... Args>
struct PrintTuple<MAX, MAX, Args...>
{
	static void print(std::ostream &strm, const std::tuple<Args...> &t) {}
};

template <typename... Args>
std::ostream &operator<<(std::ostream &strm, const std::tuple<Args...> &t)
{
	strm << "[";
	PrintTuple<0, sizeof...(Args), Args...>::print(strm, t);
	return strm << "]";
}

int main()
{
	tuple<string, int, int, complex<double>> t;

	//@ index 必须是编译期常量
	tuple<int, float, string> t1{42, 6.6, "nico"};
	cout << t1 << endl;

	auto t2 = make_tuple(22, 44, "nico");
	get<1>(t1) = get<1>(t2);
	cout << get<1>(t1) << endl;

	if (t1 < t2)
		cout << t1 << "<" << t2 << endl;
	else
		cout << t1 << ">=" << t2 << endl;

	return 0;
}
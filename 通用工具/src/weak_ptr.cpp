#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main()
{
	try
	{
		shared_ptr<string> sp(new string("hi"));
		weak_ptr<string> wp = sp;
		sp.reset();
		cout << "use count: " << wp.use_count() << endl;
		cout << "expired: " << boolalpha << wp.expired() << endl;
		shared_ptr<string> p(wp);
	}
	catch (const std::exception &e)
	{
		cerr << "exception: " << e.what() << endl;
	}
	return 0;
}
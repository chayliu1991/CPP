#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

struct X
{
	int a;
};

class base
{
public:
	base() { std::cout << "base" << std::endl; }
	~base() { std::cout << "~base" << std::endl; }
	void print() { std::cout << "base::print" << std::endl; }
};

class derived : public base
{
public:
	derived() { std::cout << "derived" << std::endl; }
	~derived() { std::cout << "~derived" << std::endl; }
	void print() { std::cout << "derived::print" << std::endl; }
};

std::shared_ptr<X> global; //@ initially nullptr
void foo()
{
	std::shared_ptr<X> local{new X};
	std::cout << "local use count: " << local.use_count() << endl;
	std::atomic_store(&global, local);
	std::cout << "local use count: " << local.use_count() << endl;
}

int main()
{
	shared_ptr<string> pNico(new string("nico"));
	shared_ptr<string> pJutta = make_shared<string>("jutta");
	shared_ptr<string> pMade{new string("made")};

	(*pNico)[0] = 'N';
	pJutta->replace(0, 1, "J");
	pMade->at(0) = 'M';

	vector<shared_ptr<string>> WhoMadeCoffee;
	WhoMadeCoffee.push_back(pNico);
	WhoMadeCoffee.push_back(pJutta);
	WhoMadeCoffee.push_back(pMade);

	for (auto ptr : WhoMadeCoffee)
	{
		cout << *ptr << " ";
	}
	cout << endl;

	*pNico = "Nicolai";

	for (auto ptr : WhoMadeCoffee)
	{
		cout << *ptr << " ";
	}
	cout << endl;

	cout << "use count:" << WhoMadeCoffee[0].use_count() << endl;

	{
		shared_ptr<string> pCustomDeleter(new string("custom"), [](string *p)
										  {
											  cout << "delete " << *p << endl;
											  delete p;
										  });
	}

	shared_ptr<X> px(new X);		//@ X 拥有对象 a
	shared_ptr<int> pi(px, &px->a); //@ shard_ptr 指向 a 必须保持外层对象的声明周期，通过 aliasing 构造函数附加其引用计数

	{
		//@ static_pointer_cast
		std::shared_ptr<base> b_ptr = std::make_shared<derived>();
		b_ptr->print();
		auto d_ptr = std::static_pointer_cast<derived>(b_ptr);
		d_ptr->print();
	}

	foo();

	/*std::shared_ptr<int> p(new int[10], [](int *p) { delete p; });*/
	std::shared_ptr<int> p(new int[10], std::default_delete<int[]>());
	*(p.get()) = 1;

	return 0;
}
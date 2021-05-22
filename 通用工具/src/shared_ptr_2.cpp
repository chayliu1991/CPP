#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person
{
public:
	string name;

	shared_ptr<Person> mother;
	shared_ptr<Person> father;
	vector<shared_ptr<Person>> kids; //@ 存放 shared_ptr 将导致循环引用，无法正确释放资源
	//vector<weak_ptr<Person>> kids; //@ 存放 weak_ptr 可以避免循环引用

	Person(const string &n, shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr) : name(n), mother(m), father(f)
	{
	}

	~Person()
	{
		cout << "delete " << name << endl;
	}

	void set_parents_and_their_kids(shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr)
	{
		mother = m;
		father = f;
		if (m != nullptr)
			m->kids.push_back(shared_ptr<Person>(this));
		if (f != nullptr)
			f->kids.push_back(shared_ptr<Person>(this));
	}
};

class PersonEx : public enable_shared_from_this<PersonEx>
{
public:
	string name;

	shared_ptr<PersonEx> mother;
	shared_ptr<PersonEx> father;
	vector<shared_ptr<PersonEx>> kids;

	PersonEx(const string &n, shared_ptr<PersonEx> m = nullptr, shared_ptr<PersonEx> f = nullptr) : name(n), mother(m), father(f)
	{
	}

	~PersonEx()
	{
		cout << "delete " << name << endl;
	}

	void set_parents_and_their_kids(shared_ptr<PersonEx> m = nullptr, shared_ptr<PersonEx> f = nullptr)
	{
		mother = m;
		father = f;
		if (m != nullptr)
			m->kids.push_back(shared_ptr<PersonEx>(shared_from_this()));
		if (f != nullptr)
			f->kids.push_back(shared_ptr<PersonEx>(shared_from_this()));
	}
};

shared_ptr<Person> init_family(const string &name)
{
	shared_ptr<Person> mom(new Person(name + "'s mom"));
	shared_ptr<Person> dad(new Person(name + "'s dad"));
	shared_ptr<Person> kid(new Person(name, mom, dad));
	mom->kids.push_back(kid);
	dad->kids.push_back(kid);
	return kid;
}

int main()
{
	//@ 错误示范1：两组拥有权，导致重复释放
	int *p = new int;
	shared_ptr<int> sp1(p);
	shared_ptr<int> sp2(p);

	//@ 正确做法：创建对象和资源时直接指定 shared_ptr
	shared_ptr<int> sp3(new int);
	shared_ptr<int> sp4(sp3);

	//@ 错误示范2：this 直接构造 shared_ptr 也会导致重复释放的问题
	shared_ptr<Person> kid(new Person("nico"));
	shared_ptr<Person> mother(new Person("nico'mom"));
	shared_ptr<Person> father(new Person("nico'father"));
	kid->set_parents_and_their_kids(mother, father);
	cout << "kid use count: " << kid.use_count() << endl; //@ 引用计数是1

	//@ 正确做法：继承自 enable_shared_from_this
	shared_ptr<PersonEx> kid_ex(new PersonEx("nico"));
	shared_ptr<PersonEx> mother_ex(new PersonEx("nico'mom"));
	shared_ptr<PersonEx> father_ex(new PersonEx("nico'father"));
	kid_ex->set_parents_and_their_kids(mother_ex, father_ex);
	cout << "kid_ex use count: " << kid_ex.use_count() << endl; //@ 引用计数是3

	//@ 错误示范3：shared_ptr 循环引用，导致资源无法释放
	{
		shared_ptr<Person> p = init_family("nico");
		cout << "nico is shared " << p.use_count() << " times " << endl;
	}
	//@ 正确做法：/vector<weak_ptr<Person>> kids;

	return 0;
}
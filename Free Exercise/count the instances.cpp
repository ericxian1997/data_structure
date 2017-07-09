#include<iostream>
using namespace std;

class Person
{
private:
    static int count;
public:
    Person(){count++;}
    ~Person(){count--;}
    static int getObjectNum() { return count; }
};

int Person::count = 0;


int main()
{
	cout << Person::getObjectNum() << endl;
	{
		Person a;
		cout<< Person::getObjectNum() << endl;
	}
	return 0;
}

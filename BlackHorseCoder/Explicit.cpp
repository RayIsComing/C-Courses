
#include <iostream>
#include <string>
 
using namespace std;
 
class Book
{
public:
	Book(){}
	explicit Book(const string name, const int price = 100) : _name(name), _price(price){
		cout << "构造函数调用！" << endl;;
	};
 
	void IsSameBook(const Book & book)
	{
		if (_name == book._name)
			cout << "两本书重名！" << endl;
		else
			cout << "两本书不重名！" << endl;
	}
private:
	string _name;
	int _price;
};
 
int main()
{
	Book A("AA");	
	Book B = Book("AA");
	A.IsSameBook(B);	
	system("Pause");

}
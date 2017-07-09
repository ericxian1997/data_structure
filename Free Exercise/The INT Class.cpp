#include<iostream>
using namespace std;

class INT
{
  int i;
public:
  int getI() { return i; }
  INT(int i = 0) { this->i = i; }
  INT(const INT& other) { this->i = other.i; }
  INT& operator = (int i) { this->i = i; return *this;}
  INT operator + (const INT b) { INT temp; temp.i = this->i + b.i; return temp; }
  INT& operator ++ () { i++; return *this; }
  const INT operator ++(int) { INT old(*this); ++(*this); return old; }
  bool operator == (const INT b)
  {
      if(this->i == b.i)  return true;
      else  return false;
  }
  friend ostream& operator << (ostream& os, const INT& a) { os << a.i; return os;}
  //INT& operator << { cout << i }
  //add any member function needed here
};



//  补充完整INT类的定义和实现，使得主函数
int main()
{
  INT a=1, b(2), c;
  c = 3;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "a+b = " << a+b << endl;
  cout << "++a = " << ++a << endl;

  cout << "a++ = " << a++ << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;
  cout << "a == b? " << (a==b) << endl;
  cout << "a == c? " << (a==c) << endl;
}

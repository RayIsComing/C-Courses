#include <iostream>
using namespace std;
#include <vector>

void printVector(vector<int>& v) {
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    // TODO:这个iterator是什么
    cout << *it << " ";//指针
  }
  cout << endl;
}

// vector 容器的构造
void test01() {
  vector<int> v1;  
  //默认构造，无参构造。

  for (int i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  printVector(v1);

  //通过区间的形式进行构造。
  vector<int> v2(v1.begin(), v1.end());
  //把两个迭代器传进去 进行赋值
  printVector(v2);

  // n个element方式构造
  vector<int> v3(10, 100);
  printVector(v3);

  //拷贝构造函数；
  vector<int> v4(v3);
  // TODO：拷贝的方式为啥是传值？？
  printVector(v4);
}

int main() {
  test01();
  system("pause");

  return 0;
}

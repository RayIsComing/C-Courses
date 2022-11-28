#include<iostream>
using namespace std;
#include<vector>

//TODO：绝对引用和相对引用



void printVector(vector<int>& v) {
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    // TODO:这个iterator是什么
    cout << *it << " ";//指针
  }
  cout << endl;
}

//vector的赋值

void Test01(){
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        //给v1赋值
    }
    printVector(v1);

    //赋值 operate =

    //assign赋值，赋值区间
    //assign赋值，

}

int main(){

    system("pause");

    return 0;
}
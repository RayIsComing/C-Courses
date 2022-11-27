#include<iostream>
using namespace std;

class CRectangle{
    public:
    int h,w;
    //仅仅给出了成员函数的声明
    int Area();
    int Perameter();
    int Init(int w_,int h_);
};

//给出成员函数的定义
CRectangle::Area(){
    return h*w;
}
CRectangle::Perameter(){
    return 2*(h+w);
}
CRectangle::(int w_, int h_){
    w = w_;
    h = h_;
}

int main(){
    

}
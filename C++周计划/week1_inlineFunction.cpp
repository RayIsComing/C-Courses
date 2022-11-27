

inline int Max(int a, int b)
{
    int c;
    if (a>b) {
        c=a;
    }
    else{
        c=b;
    }
    return c;
}

//调用情况

int main()
{
    int m;
    int n;
    int K = Max(m,n);
    return K;
}
//不是内联函数状态：
int main()
{
    int m;
    int n;
    //int K = Max(m,n);
    int a;//多余栈
    int b;//多余栈
    int K=Max(a,b){
        int c;
        if (a>b) {
            c=a;
        }
        else{
            c=b;
        }
        return c;
    }
    return K;
}

//内联函数
int main()
{
    int m;
    int n;
    //int K = Max(m,n);
    int a;//多余栈
    int b;//多余栈
    int c;
        if (m>n) {
            c=m;
        }
        else{
            c=n;
        }
        return c;
 return K;
}



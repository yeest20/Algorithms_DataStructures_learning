/*************************************************************************
	> File Name: test.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Sun 29 Sep 2024 10:22:25 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    int a = 2, b;
    b = a;
    cout << a << "  " << b << endl;
    a = 3;
    cout << a << "  " << b << endl;

    int c[10] = {20, 30, 40};
    int *p1 = c, *p2;
    p2 = p1 - 1;
    cout << "p1 : " << p1 << " p2 : " << p2 << endl;
    cout << "c : " << c << endl;
    
    cout << "p1 : " << p1 << " p2 : " << p2[1] << endl;
    cout << "c : " << c << endl;
    cout << "*p2 : " << *p2 << endl;
    return 0;
}

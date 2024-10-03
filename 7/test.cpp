/*************************************************************************
	> File Name: test.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Wed 02 Oct 2024 01:42:58 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void add(int *p){
    cout << " p in : " << p << endl;
    cout << "p + 1 in : " << p + 1 << endl;
    
}


int main(){
    int a[5] = {1, 2, 3, 4, 5};
    int* p = a;
    cout << "a : "<< a << endl;
    cout << "p : "<< p << endl;
    add(p);
    cout << "a : "<< a << endl;
    cout << "p : "<< p << endl;
}

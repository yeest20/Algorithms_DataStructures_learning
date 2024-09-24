/*************************************************************************
	> File Name: 1.factorial.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Fri 20 Sep 2024 04:55:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int factorial(int n){
    if(n == 1) return 1;
    return n * factorial(n - 1);
}



int main(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;

    return 0;
}

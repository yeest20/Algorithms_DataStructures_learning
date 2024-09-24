/*************************************************************************
	> File Name: 186.HZOJ.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Fri 20 Sep 2024 05:06:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int f(int n){
    if(n == 1) return 1;
    return 2 * (f(n - 1) + 1);
}



int main(){
    int n;
    cin >> n;
    cout << f(n) << endl;

    return 0;
}

/*************************************************************************
	> File Name: 186HZOJ.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Fri 20 Sep 2024 05:50:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


#define MAX_N 100000
int a[MAX_N + 5];


int f(const int k){
    if(k + a[k] > a[0]) return 1;
    return f(a[k] + k) + 1;
}

int main(){
    cin >> a[0];
    for(int i = 1; i <= a[0]; i++) cin >> a[i];
    cout << f(1) << endl;

    return 0;
}

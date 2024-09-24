/*************************************************************************
	> File Name: 235HZOJ.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Fri 20 Sep 2024 06:29:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n;
int arr[10];

void printf_one_resule(int n){
    for(int i = 0; i <= n; i++){
        cout << arr[i];
        if(i < n) cout << " ";
    }
    cout << endl;
    return;
}


void f(int i, int j){
    if(j > n) return;
    for(int k = j; k <= n; k++){
        arr[i] = k;
        printf_one_resule(i);
        f(i + 1, k + 1);
    } 
}

int main(){
    cin >> n;
    f(0, 1);
    return 0;
}

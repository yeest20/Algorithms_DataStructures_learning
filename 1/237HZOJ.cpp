/*************************************************************************
	> File Name: 237HZOJ.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Fri 20 Sep 2024 07:56:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[5];
int n;

void print_result(){
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

void f(int i){
    if(i >= n){
        print_result();
        return;
    } 
    
    for(int k = 1; k <= n; k++){
        if(i == 0) arr[i] = k;
        /* 数字在前面没有出现过        */
        int flag = 0;
        for(int l = 0; l < i; l++) {
            if(arr[l] == k) {
                flag = 1; 
                break;
            }
        }
        if(flag) continue;
        /* 数字在前面没有出现过        */
        arr[i] = k;
        f(i + 1);
    }
}



int main(){
    cin >> n;
    f(0);

    return 0;
}

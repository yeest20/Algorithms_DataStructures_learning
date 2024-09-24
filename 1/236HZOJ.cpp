/*************************************************************************
	> File Name: 236HZOJ.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Fri 20 Sep 2024 07:05:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m;
int arr[10] = {0};
void print(){
    for(int i = 0; i < m; i++){
        cout << arr[i];
        if(i < m - 1) cout << " ";
    }
    cout << endl;
    return;
}

void f(int i, int j, int max){
    if(i >= m) {
        print();
        return;
    }

    for(int k = j; k <= max; k++){
        arr[i] = k;
        f(i + 1, k + 1, max + 1);
    } 


}

int main(){
    cin >> n >> m;
    f(0, 1, n - m + 1);
    return 0;
}

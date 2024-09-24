/*************************************************************************
	> File Name: 263HZOJ.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Tue 24 Sep 2024 09:11:53 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

bool isValid(int a[], int n){
    stack<int> s;
    int x = 1;
    for(int i = 0; i < n; i++){
        if(s.empty() || s.top() < a[i]){
            while(x <= a[i]) s.push(x), x += 1;
        }
        if(s.empty() || s.top() != a[i]) return false; // 调用top/pop一定保证栈非空
        s.pop();
        
    }
    return true;
}

int main(){
    int n, a[25], cnt = 20;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) a[i] = i + 1;
    do{
        if(isValid(a, n)){
            for(int i = 0; i < n; i++){
                cout << a[i];
            }
            cout << endl;
            cnt -= 1;
        }
    }while(next_permutation(a, a + n) && cnt);

    return 0;
}

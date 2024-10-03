/*************************************************************************
	> File Name: test.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Tue 01 Oct 2024 10:18:31 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


int main(){
    int l = 10;
    cout << " i : " << endl;
    for(int i = 1; i < l; i++){
        cout << i << endl;
    }
    cout << " l : " << endl;
    while(l - 1){
        cout << l << endl;
        l--;
    }
    

    vector<int> vec(10);
    for(int i = 0; i < 10; i++) vec[i] = i;
    for(auto x : vec) cout << x << endl;
    return 0;
}

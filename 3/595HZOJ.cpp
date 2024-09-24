/*************************************************************************
	> File Name: 595HZOJ.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Tue 24 Sep 2024 06:20:00 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

int main(){
    int n, flag = 0;
    cin >> n;
    vector<string> ops(n), stack;
    string target;
    for(int i = 0; i < n; i++) cin >> ops[i];
    cin >> target;
    for(int i = 0; i < n; i++){
        if(target == ops[i]){
            stack.push_back(ops[i]);
            flag = 1;
            break;
        }
        if(ops[i] == "return"){
            stack.pop_back();
        }else{
            stack.push_back(ops[i]);
        }
    }
    if(!flag){
        cout << "NOT REFERENCED" << endl;
        return 0;
    }
    
    for(int i = 0; i < stack.size(); i++){
        if(i) cout << "->";
        cout << stack[i];
    }
    cout << endl;

    return 0;
}

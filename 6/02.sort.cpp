/*************************************************************************
	> File Name: 02.sort.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Mon 30 Sep 2024 04:26:53 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cstdlib>
#include"./00.sort_test.h"
using namespace std;

void output(int *arr, int n){
    cout << "arr : " << endl;
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return;
}

void output(const vector<int> &vec){
    cout << "vector : " << endl;
    for(auto x : vec) cout << x << " ";
    cout << endl;
    return;
}

struct Data{
    int x, y;
};

void output(vector<Data> &data){
    cout << "Data : " << endl;
    for(auto x : data) cout << "(" << x.x << "," << x.y << ")" << endl;
}

bool comp(Data a, Data b){
    if(a.x <= b.x) return true;
    else return false;
}


int main(){
    srand(time(0));
    // 基本使用
    int *arr = getRandData(10);
    output(arr, 10);
    sort(arr, arr + 10);  //sort(adrbegin, adrend)
    output(arr, 10);
    sort(arr, arr + 10, greater<int>()); // greater:模板函数，反之
    output(arr, 10);

    // vector
    vector<int> vec;
    for(int i = 0; i < 10; i++) vec.push_back(rand() % 10000);
    output(vec);
    sort(vec.begin(), vec.end());
    output(vec);
    sort(vec.begin(), vec.end(), greater<int>());
    output(vec);
    
    // 自定义类型
    vector<Data> data;
    for(int i = 0; i < 10; i++){
        Data d;
        d.x = rand() % 100, d.y = rand() % 100;
        data.push_back(d);
    }
    output(data);
    sort(data.begin(), data.end(), comp); // 自定义比较规则，返回true的条件为排序方式
    output(data);
    
    // 新建输出结果
    int *arr1 = getRandData(10);
    int *ind = getRandData(10);
    for(int i = 0; i < 10; i++) ind[i] = i;
    output(arr1 , 10);
    sort(ind, ind + 10, [&](int i, int j) -> bool{
        return arr1[i] < arr1[j];
    });
    output(ind, 10);
    for(int i = 0; i < 10; i++) cout << arr1[ind[i]] << " ";
    cout << endl;
    output(arr1, 10);
    return 0;
}






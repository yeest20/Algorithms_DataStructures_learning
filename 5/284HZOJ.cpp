/*************************************************************************
	> File Name: 284HZOJ.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Sun 29 Sep 2024 11:52:19 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<cstdio>
using namespace std;

void getsales(set<pair<int, int>> &sales, set<pair<int, int>> &days){
    pair<int, int> product1; // 商品信息，first为过期日期，second为利润
    pair<int, int> product2; 
    // 遍历日期堆，本次要处理的商品为x
    // 如果x的日期大于日期堆的数量，直接加入
    // 如果x的日期等于日期堆的数量，判断x的利润是否大于利润堆的最小值
    // 如果大于：弹出利润堆最小值，压入x
    // 如果小于：弹出x
    while(!days.empty()){
        if(days.begin()->first > sales.size()){
            product2.first = days.begin()->second;
            product2.second = days.begin()->first;    // 这里写的很丑，但是功能预计正确。目的是向利润堆插入以利润为first的商品信息。
            sales.insert(product2);
            days.erase(days.begin());
        }else{
            if(days.begin()->second > sales.begin()->first){                
                sales.erase(sales.begin());
                product2.first = days.begin()->second;
                product2.second = days.begin()->first;
                sales.insert(product2);
                days.erase(days.begin());
            }else{
                days.erase(days.begin());
            } 
            
        }
    }
    return;
}

int main(){
    int N;
    cin >> N;
    pair<int, int> product1; // 商品信息，first为过期日期，second为利润
    pair<int, int> product2; // 商品信息，first为利润，second为过期日期
    set<pair<int, int>> sales; // 小顶堆，维护利润最小值
    set<pair<int, int>> days; // 小顶堆，维护日期从小到大
    // 将所有信息读入到日期堆中
    for(int i = 0; i < N; i++){
        cin >> product1.second >> product1.first;
        days.insert(product1);
    }
    // 函数，得到利润堆
    getsales(sales, days);
    // 遍历求和
    int profit = 0;
    for(auto x : sales){
        profit += x.first;
    }
    cout << profit << endl;
    return 0;
}

/*************************************************************************
	> File Name: 248HZOJ.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Tue 01 Oct 2024 12:00:00 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


long long getInversPair(vector<int> &arr, int l, int r){
    if(r - l <= 1)  return 0;

    int n = r - l, mid =  n / 2; //mid = (l + r) / 2
    //cout << "n : " << n << endl << "mid : " << mid << endl;
    long long  a = 0, b = 0, c = 0;
    a = getInversPair(arr, l, l + mid);
    b = getInversPair(arr, l + mid, r);
    
    sort(arr.begin() + l, arr.begin() + l + mid);
    sort(arr.begin() + l + mid, arr.begin() + r);
    int p1 = l, p2 = l + mid;
    int cnt = mid;
    //cout << "cnt : " << cnt << endl;
    while(p1 < l + mid || p2 < r){
        if(p1 == l + mid || (p2 != r && arr[p2] < arr[p1])){
            p2++;
            c += cnt;
        }else{
            p1++;
            cnt -= 1;
        }
    }
    //cout << "a : "<< a << endl;
    //cout << "b : "<< b << endl;
    //cout << "c : "<< c << endl; 
    return a + b + c;
}


int main(){
    vector<int> arr;
    int n, temp;
    while(cin >> n){
        if(n == 0) break;
        arr.clear();
        for(int i = 0; i < n; i++)  {
            cin >> temp; 
            arr.push_back(temp); 
        }
        //cout << n << endl;
        //for(int i = 0; i < n; i++) cout << arr[i] << endl;
        cout << getInversPair(arr, 0, n) << endl;
    }
    return 0;
}

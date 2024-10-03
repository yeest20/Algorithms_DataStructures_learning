/*************************************************************************
	> File Name: 02.exercise.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Tue 01 Oct 2024 04:18:13 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

double f(double x){
    if(x <= 3000) return x - 0.03 * x;
    else if(x <= 12000) return x - 0.1 * x + 210;
    else if(x <= 25000) return x - 0.2 * x + 1410;
    else if(x <= 35000) return x - 0.25 * x + 2660;
    else if(x <= 55000) return x - 0.3 * x + 4410;
    else if(x <= 80000) return x - 0.35 * x + 7160;
    else return x - 0.45 * x + 15160;
}

double find(double n){
    double head = 0, tail = 2 * n, mid;
    while(head <= tail){
        mid = (head + tail) / 2.0;
        if(abs(f(mid) - n) < 1e-6)  return mid;
        else if(f(mid) < n) head = mid;
        else tail = mid;
    }
    return -1;
}


int main(){
    double n;
    while(~scanf("%lf", &n)){
        printf("%.2lf\n", find(n));
    }

    return 0;
}

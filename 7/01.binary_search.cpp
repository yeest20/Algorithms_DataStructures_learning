/*************************************************************************
	> File Name: 01.binary_search.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Tue 01 Oct 2024 03:54:53 PM CST
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<cstdio>
#include<string>
using namespace std;

void output(int* arr, int n, int ind = -1){
    int len = 0;
    for(int i = 0; i < n; i++) len += printf("%3d ", i);
    cout << endl;
    for(int i = 0; i < len; i++) printf("-");
    cout << endl;
    for(int i = 0; i < n; i++){
        if(i == ind) printf("\033[1;32m");
        printf("%3d ", arr[i]);
        if(i == ind) printf("\033[0m");
    }
    cout << endl;
}

int binary_search(int *arr, int n, int x){
    int head = 0, tail = n - 1, mid;
    while(head <= tail){
        mid = (head + tail) / 2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] < x) {head = mid + 1; continue;}
        tail = mid - 1;
    }
    return -1;
}

void test_binary_search(int n){
    int *arr = (int*)malloc(sizeof(int) * n);
    arr[0] = rand() % 10;
    for(int i = 1; i < n; i++) arr[i] = arr[i - 1] + rand() % 10;
    output(arr, n);
    int x;
    while(scanf("%d", &x) != EOF){
        if( x == -1) break;
        int ind = binary_search(arr, n, x);
        output(arr, n, ind);
    }
    free(arr);
}



int main(){
    srand(time(0));
    #define MAX_N 10
    test_binary_search(MAX_N);
    return 0;
}

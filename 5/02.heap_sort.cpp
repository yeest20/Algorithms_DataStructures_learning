/*************************************************************************
	> File Name: 02.heap_sort.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Sat 28 Sep 2024 10:38:36 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>

#define cmp >
#define ROOT 1
#define FATHER(i) ((i) / 2)
#define LEFT(i) ((i) * 2)
#define RIGHT(i) ((i) * 2 + 1)
using namespace std;

#define TEST(func, arr, n){\
    printf("TEST : %s\n", #func);\
    int *temp = (int *)malloc(sizeof(int) * n);\
    memcpy(temp, arr, sizeof(int) * n);\
    long long b = clock();\
    func(temp, n);\
    long long e = clock();\
    if(check(temp, n)){\
        printf("OK\n");\
    }else{\
        printf("Fail\n");\
    }\
    printf("%lld ms\n", 1000 * (e - b)/ CLOCKS_PER_SEC);\
    free(temp);\
    }

void heap_sort(int*, int);

int check(int* arr_sorted, int n){
    for(int i = 1; i < n; i++){
        if(arr_sorted[i] < arr_sorted[i - 1]) return false;
    }
    return true;
}

int* getRandData(int n){
    int *arr = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) arr[i] = rand() % 100000;
    return arr;
}

void up_update(int *data, int i){
    while(i > ROOT && data[i] cmp data[FATHER(i)]){
        swap(data[i], data[FATHER(i)]);
        i = FATHER(i);
    }
    return;
}

void normal_heap_build(int *data, int n){
    for(int i = 2; i <= n; i++){
        up_update(data, i);
    }
    return;
}

void normal_heap(int *arr, int n){
    int *data = arr - 1;
    normal_heap_build(data, n);
    heap_sort(data, n);
    return ;
}


inline void down_updata(int* data, int i, int n){
    while(LEFT(i) <= n){
        int ind = i, l = LEFT(i), r = RIGHT(i);
        if(data[l] cmp data[ind]) ind = l;
        if(r <= n && data[r] cmp data[ind]) ind = r;
        if(ind == i) break;
        swap(data[ind], data[i]);
        i = ind;
    }
    return;
}
void linear_heap_build(int* data, int n){
    for(int i = n / 2; i >= 1; i--){
        down_updata(data, i, n);
    }
    return;
}
void linear_heap(int *arr, int n){
    int *data = arr - 1;
    linear_heap_build(data, n);
    heap_sort(data, n);
    return;
}

void heap_sort(int *data, int n){
    for(int i = n; i>= 2; i--){
        swap(data[i], data[1]);
        down_updata(data , 1, i - 1);
    }

    return;
}

int main(){
    srand(time(0));
    #define MAX_N 10000000
    int *arr = getRandData(MAX_N);
    TEST(normal_heap, arr, MAX_N);
    TEST(linear_heap, arr, MAX_N);
    
    return 0;
}

/*************************************************************************
	> File Name: 0.0.sort_test.h
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Sun 29 Sep 2024 03:33:08 PM CST
 ************************************************************************/

#ifndef _00SORT_TEST_H
#define _00SORT_TEST_H
#include<string.h>

#define SMALL_DATA_N 5000
#define BIG_DATA_N 10000000

__attribute__((constructor))
void __init_Rand__(){
    srand(time(0));
}

bool check(int *arr, int l, int r){
    for(int i = l + 1; i < r; i++){
        if(arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int *getRandData(int n){
    int *arr = (int*) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) arr[i] = rand() % 10000;
    return arr;
}

#define TEST(func, arr, n){\
    printf("Test %s : \n", #func);\
    int *temp = (int *)malloc(sizeof(int) * n);\
    memcpy(temp, arr, sizeof(int) * n);\
    long long b = clock();\
    func(temp, 0, n);\
    long long e = clock();\
    if(check(temp, 0, n)){\
       printf("OK\n");\
        printf("%d items use : %lld ms \n", n, 1000 * (e - b) / CLOCKS_PER_SEC);\
    }else{\
        printf("Failed\n");\
    }\
    free(temp);\
}

#endif

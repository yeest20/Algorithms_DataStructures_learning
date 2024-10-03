/*************************************************************************
	> File Name: 01.selection_sort.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Sun 29 Sep 2024 03:31:14 PM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"./00.sort_test.h"

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    return;
}
// 选择排序
void selection_sort(int *arr, int l, int r){
    for(int i = l, I = r - 1; i < I; i++){
        int ind = i;
        for(int j = i + 1; j < r; j++){
            if(arr[j] < arr[ind]) ind = j;
        }
        swap(arr[ind], arr[i]);
    }
    return ;
}
// 插入排序：无监督插入
void insert_sort(int *arr, int l, int r){
    // 无监督：全局最小值置于首位
    int minID = l;
    for(int i = l + 1; i < r; i++){
        if(arr[i] < arr[minID]) minID = i;
    }
    //swap(arr[l], arr[minID]);//为什么不行？ 稳定排序
    while(minID > l){
        swap(arr[minID], arr[minID - 1]);
        minID -= 1;
    }
    for(int i = l + 2; i < r; i++){
        for(int j = i;; j--){
            if(arr[j] >=  arr[j - 1]) break;
            swap(arr[j], arr[j - 1]);
        }
    }
    return;
}
// 希尔排序（分组插入排序）
inline int max(int a, int b){
    return a > b? a : b;
    
}

void insert_sort_2(int* arr, int l, int r, int step){
    int minID = l;
    for(int i = l + step; i < r; i += step){
        if(arr[i] < arr[minID]) minID = i;
    }
    
    while(minID > l){
        swap(arr[minID], arr[minID - step]);
        minID -= step;
    }

    for(int i = l + 2 * step; i < r; i += step){
        int j = i;
        while(arr[j] < arr[j - step]){
            swap(arr[j], arr[j - step]);
            j -= step;
        }
    }
    return;
}

void shell_sort(int *arr, int l, int r){
    int k = 2, n = r - l, step;
    int step_hibbard = 1;
    /*
    while(step != 1){
        step = n / k;
        insert_sort_2(arr, l, r, step);
        } 
        k *= 2;
    }
    */
    while(step_hibbard <= n / 2)  step_hibbard = step_hibbard * 2 + 1;
    do{
        step_hibbard /= 2;
        for(int i = l, I = l + step_hibbard; i < I; i++){
            insert_sort_2(arr, i, r, step_hibbard);
        } 
    }while(step_hibbard > 1);
    return;
}
// 冒泡排序
void bubble_sort(int* arr, int l, int r){
    int flag = 0;
    int n = r - l;
    for(int i = 0, I = n - 1; i < I; i++){
        flag = 1;
        for(int j = l; j < r - i - 1; j++){
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = 0;
            }
        }
        if(flag) break;
    }
    return;
}
int threePointMid(int a, int b, int c){
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b ,c);
    return b;
}
//快速排序
void quick_sort(int* arr, int l, int r){
    if(r - l <= 16){
        if(r - l <= 1) return;
        else if(r - l <= 2){
            if(arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
            return;
        }else{
            insert_sort(arr, l, r);
            return;
        }
    }
    while(l < r){
    //优化2:树高，base值优化
        int base = threePointMid(arr[l], arr[r - 1], arr[(l + r) / 2]);
        int lp = l, rp = r - 1;
    // 优化1: 头尾指针直接交换
        do{
            while(arr[lp] < base) lp += 1;
            while(arr[rp] > base) rp -= 1;
            if(lp <= rp) swap(arr[lp++], arr[rp--]);
        }while(lp <= rp);
    // 优化3: 单边递归
        quick_sort(arr, l, lp);
        l = lp;
    }
    return;
}

//归并排序
int *buff;
void merge_sort(int *arr, int l, int r){
    if(r - l <= 1) return;
    if(r - l <= 2) if(arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);
    // 归并
    int p1 = l, p2 = mid, k = 0;
    // 优化1：开足够大的空间重复利用
    while(p1 < mid || p2 < r){
        if(p2 == r || (p1 < mid && arr[p1] <= arr[p2])) buff[k++] = arr[p1++];
        else buff[k++] = arr[p2++];
    }
    for(int i  = l; i < r; i++) arr[i] = buff[i - l];
    return ;
}

//基数排序
void radix_sort(int *arr, int l, int r){
    #define K  65536 //2^16 
    int* cnt = (int *) malloc(sizeof(int) * K); // 数字出现次数
    int* temp = (int *) malloc(sizeof(int) * (r - l));
    // round 1
    memset(cnt, 0, sizeof(int) * K);
    for(int i = l; i < r; i++) cnt[arr[i] % K] += 1;
    for(int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
    for(int i = r - 1; i>= 1; i--) temp[--cnt[arr[i] % K]] == arr[i];
    memcpy(arr + l, temp, sizeof(int) * (r - l));
    // round 2
    memset(cnt, 0, sizeof(int) * K);
    for(int i = l; i < r; i++) cnt[arr[i] / K] += 1;
    for(int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
    for(int i = r - 1; i>= 1; i--) temp[--cnt[arr[i] / K]] == arr[i];
    memcpy(arr + l, temp, sizeof(int) * (r - l));

    return ;
}

int main(){
    //int *arr = getRandData(SMALL_DATA_N);
    int *arr = getRandData(BIG_DATA_N);
    //TEST(selection_sort, arr, SMALL_DATA_N); 
    //TEST(insert_sort, arr, SMALL_DATA_N);
    //TEST(shell_sort, arr, SMALL_DATA_N);
    //TEST(bubble_sort, arr, SMALL_DATA_N);
    //TEST(quick_sort, arr, SMALL_DATA_N);
    TEST(quick_sort, arr, BIG_DATA_N);
    buff = (int *)malloc(sizeof(int) * BIG_DATA_N);
    TEST(merge_sort, arr, BIG_DATA_N);
    TEST(radix_sort, arr, BIG_DATA_N);
    //free(buff);
    free(arr);
    return 0;
}

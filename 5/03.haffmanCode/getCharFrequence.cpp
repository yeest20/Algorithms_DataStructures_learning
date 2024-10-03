/*************************************************************************
	> File Name: getCharFrequence.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Sat 28 Sep 2024 12:10:52 PM CST
 ************************************************************************/

#include<iostream>
#include<ctime>
using namespace std;

#define CharSize 26

int main(){
    srand(time(0));
    printf("%d\n", CharSize);
    for(int i = 0; i < CharSize; i++){
        int fre = rand() % 100000;
        printf("%c %d\n", 'a' + i, fre);
    }
    return 0;
}

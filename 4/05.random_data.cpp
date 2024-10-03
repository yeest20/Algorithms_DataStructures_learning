/*************************************************************************
	> File Name: random_data.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Thu 26 Sep 2024 10:14:19 PM CST
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
    srand(time(0));
    printf("26\n");
    for(int i = 0; i < 26; i++){
        printf("%c %d\n", 'a' + i, rand() % 100000);
    }


    return 0;
}



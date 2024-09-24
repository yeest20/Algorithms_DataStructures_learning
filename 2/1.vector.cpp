/*************************************************************************
	> File Name: 1.vector.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Fri 20 Sep 2024 10:43:47 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
using namespace std;

typedef struct vector{
    int size, count;
    int *data;
} vector;

vector *getNewVector(int n){
    vector *p = (vector *)malloc(sizeof(vector));
    p->size = n;
    p->count = 0;
    p->data = (int *)malloc(sizeof(int) * n);
    return p;
}

void clear(vector *v){
    if(v == NULL) return;
    free(v->data);
    free(v);
    return;
}

int expand(vector *v){
    if(v == NULL) return 0;
    printf("expand v from %d to %d\n", v->size, 2 * v->size);
    int *p = (int*)realloc(v->data, sizeof(int) * 2 * v->size);
    if(p == NULL) return 0;
    v->data = p;
    v->size *= 2;
    return 1;
}

int insert(vector *v, int pos, int val){
    if(pos < 0 || pos > v->count) return 0;
    if(v->size == v->count && !expand(v)) return 0;
    for(int i = v->count - 1; i >= pos; i--){
        v->data[i + 1] = v->data[i];
    }
    v->data[pos] = val;
    v->count++;
    return 1;
}

int erase(vector *v, int pos){
    if(pos < 0 || pos >= v->count) return 0;
    for(int i = pos + 1; i < v->count; i++){
        v->data[i] = v->data[i - 1];
    }
    v->count--;
    return 1;
}

void output_vector(vector *v){
    cout << "vector : " << endl;
    for(int i = 0; i < v->count; i++){
        cout << i << " " ;
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    for(int i = 0; i < v->count; i++){
        cout << v->data[i] << " ";
    }
    cout << endl;
}

int main(){
    srand(time(0));
    #define MAX_OP  10
    vector *v = getNewVector(2);
    for(int i = 0; i < MAX_OP; i++){
        int op = rand() % 4, pos, val, ret;
        switch(op){
            case 0:
            case 1:
            case 2:
                pos = rand() % (v -> count + 2);
                val = rand() % 10;
                ret = insert(v, pos, val);
                cout << "insert " << val << " at " << pos << " to vector = " << ret << endl;
                break;
            case 3:
                pos = rand() % (v -> count + 2);
                cout << "erase item at " << pos << " in vector = " << erase(v, pos) << endl;
                break;
            default: cout << "default" << endl; break;
        }
        output_vector(v);
    } 

    clear(v);

    return 0;
}

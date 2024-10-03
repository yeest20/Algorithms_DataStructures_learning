/*************************************************************************
	> File Name: 01.priority_queue.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Fri 27 Sep 2024 10:51:35 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef struct PriorityQueue{
    int *__data, *data;
    int size, n;
} PriorityQueue;

PriorityQueue *initPQ(int size){
    PriorityQueue *p = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    p->__data = (int*)malloc(sizeof(int) * size);
    p->data = p->__data - 1;
    p->size = size;
    p->n = 0;
    return p;
}

int isempty(PriorityQueue *p){
    return p->n == 0;
}

int isfull(PriorityQueue *p){
    return p->n == p->size;
}

int front(PriorityQueue *p){
    return p->data[1];
}
void up_updata(int* data, int id){
    if(id == 1) return;
    if(data[id] < data[id / 2]) return;
    swap(data[id], data[id / 2]);
    up_updata(data, id / 2);
    return;
}
int push(PriorityQueue* p, int val){
    if(isfull(p)) return 0;
    p->n += 1;
    p->data[p->n] = val; 
    up_updata(p->data, p->n);
    return 1;
}

int max_id(int a, int b){
    return a > b? 1 : 0;
} 

void down_updata(int* data, int id, const int &n){
    if(id > n) return; 
    if(data[id] > data[id * 2] && data[id] > data[id * 2 + 1]) return;
    if(data[id * 2] > data[id * 2 + 1]){
        swap(data[id], data[id * 2]);
        down_updata(data, id * 2, n);
    }else{
        swap(data[id], data[id * 2 + 1]);
        down_updata(data, id * 2 + 1, n);
    }
    return; 
}
int pop(PriorityQueue* p){
    if(isempty(p)) return 0;
    p->data[1] = p->data[p->n]; 
    p->n -= 1;
    down_updata(p->data, 1, p->n);
    return 1;
}

void clear(PriorityQueue *p){
    if(p == NULL) {
        cout << "p == null" << endl;
        return;
    }
    free(p->__data);
    free(p);
    return;
}

void output(const int data[], const int &n){
    for(int i = 1; i <= n; i++){
        printf("%d ", data[i]);
    }
    cout << endl;
}

int main(){
    srand(time(0));
    PriorityQueue *q = initPQ(10);
    for(int i = 0; i < 20;  i++){
        int op = rand() % 3, val = rand() % 100, ret = 0;        
        if(op){
            ret = push(q, val);
            printf("push %d to q is %d\n", val, ret);
            output(q->data, q->n);
        }else{
            ret = pop(q);
            printf("pop q is %d\n", ret);
            output(q->data, q->n);
        } 
    }
    clear(q);
    return 0;
}

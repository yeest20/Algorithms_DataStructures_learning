/*************************************************************************
	> File Name: 03.skip_list.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Tue 01 Oct 2024 06:08:24 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cinttypes>
using namespace std;

// 单个节点
typedef struct Node{
    int key, level;
    Node *next, *up, *down;
} Node;

// 跳跃表
#define MAX_LEVER 32
typedef struct Skiplist{
    Node* head, *tail;
    int max_level;
} Skiplist;

// 新建节点组， 返回最高节点的地址
Node *getNewNode(int key, int n){
    Node *nodes = (Node*)malloc(sizeof(Node) * n);
    for(int i = 0; i < n; i++){
        nodes[i].key = key;
        nodes[i].level = i;
        nodes[i].next  = nullptr;
        nodes[i].down = (i == 0? nullptr : &nodes[i - 1]);
        nodes[i].up = (i == n - 1? nullptr : &nodes[i + 1]);
    }
    return &nodes[n - 1];
}
// 清除节点组
void clearNode(Node *p){
    if(p = nullptr) return;
    free(p);
    return;
}
// 新建跳跃表，返回左上角节点地址
Skiplist *getNewSkiplist(int n){
    Skiplist* p = (Skiplist*)malloc(sizeof(Skiplist));
    p->head = getNewNode(INT32_MIN , n);
    p->tail = getNewNode(INT32_MAX, n);
    Node *p1 = p->head, *p2 = p->tail;
    while(p1){
        p1->next = p2;
        p1 = p1->down, p2 = p2->down;
    }
    p->max_level = n;
    return p;
}
// 清除跳跃表
void clear(Skiplist* s){
    if(s = nullptr) return;
    Node *p = s->head;
    while(p->level) p = p->down;
    Node *q;
    while(p){
        q = p->next;
        clearNode(p);
        p = q;
    }
    free(s);   
    return;
}
// 查找元素
Node *find(Skiplist *s, int val){
    Node *p = s->head;
    while(p && p->key != val){
        if(p->next->key <= val) p = p->next;
        else p = p->down;
    }
    return p;
}
double randDouble(){
    #define MAX_RAND_N 1000000
    return rand() % MAX_RAND_N * 1.0 / MAX_RAND_N;
    #undef MAX_RAND_N
}

int randLevel(Skiplist *s){
    int level = 1;
    double p = 1.0 / 2.0;
    while(randDouble() < p) level += 1;
    return min(s->max_level, level);
}
// 插入元素
void insert(Skiplist *s, int val){
    int level = randLevel(s);
    cout << "level : "<< level << endl;
    while(s->head->level + 1 < level) cout << "here" << endl, s->head = s->head->up;
    Node *node = getNewNode(val, level);
    Node *p = s->head;
    while(p->level != node->level) p = p->down;
    while(p){
        while(p->next->key < node->key) p = p->next;
        node->next = p->next;
        p->next = node;
        p = p->down;
        node = node->down;
    }
    return;

}

void output(Skiplist* s){
    Node* p = s->head, *flag = s->tail;
    int len = 0;
    for(int i = 0; i < p->level; i++) len += printf("%4d", i);
    printf("\n");
    for(int i = 0; i < len; i++) printf("-");
    printf("\n");
    while(p->level > 0) p = p->down, flag = flag->down;
    p = p->next;
    while(p != flag){
        for(Node *q = p; q; q = q->up) printf("%4d", q->key);
        printf("\n");
        p = p->next;
    }
}


int main(){
    srand(time(0)); 
    int x;
    Skiplist *s =getNewSkiplist(32);
    while(~scanf("%d", &x)){
        if(x == -1) break;
        insert(s, x);
    }
    output(s);
    
    while(~scanf("%d", &x)){
        Node *p = find(s, x);
        printf("find result : ");
        if(p){
            printf("key = %d, level = %d\n", p->key, p->level);
        }else printf("NULL\n");
    }

    return 0;
}

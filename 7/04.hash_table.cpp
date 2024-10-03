/*************************************************************************
	> File Name: 04.hash_table.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Wed 02 Oct 2024 11:50:49 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>

using namespace std;

typedef struct Node{
    char* s;
    Node* next;
} Node;

typedef struct HashTable{
    Node* data;
    int cnt, size;
} HashTable;

Node *getNewNode(const char* s){
    Node* p = (Node*)malloc(sizeof(Node));
    p->s = strdup(s);
    p->next = nullptr;
    return p;
}

HashTable* getNewHashTable(int n){
    HashTable *h = (HashTable*)malloc(sizeof(HashTable));
    h->data = (Node*)malloc(sizeof(Node) * n);
    h->size = n;
    h->cnt = 0;
    return h;
}

void clearNode(Node *p){
    if(p == nullptr) return;
    if(p->s) free(p->s);
    free(p);
    return;
}

void clearHashTable(HashTable *h){
    if(h == nullptr) return;
    for(int i = 0; i < h->size; i++){
        Node *p = h->data[i].next, *q;
        while(p){
            q = p->next;
            clearNode(p);
            p = q;
        }
    }
    free(h->data);
    free(h);
    return;
}

int hash_func(const char *s){
    int seed = 131, h = 0;
    for(int i = 0; s[i]; i++){
        h = h * seed + s[i];
    }
    return h & 0x7fffffff;
}

bool find(HashTable *h, const char* s){
    int hcode = hash_func(s), ind = hcode % h->size;   
    Node* p = h->data[ind].next;
    while(p){
        if(strcmp(p->s, s) == 0) return true;
        p = p->next;
    }
    return false;
}
HashTable* expand(HashTable*);

bool insert(HashTable* (&h), const char* s){
    if(h->cnt >= h->size * 2) h = expand(h);
    int hcode = hash_func(s), ind = hcode % h->size;   
    Node* p = getNewNode(s);
    p->next = h->data[ind].next;
    h->data[ind].next = p;
    h->cnt += 1;
    return true;
}

HashTable* expand(HashTable* h){
    HashTable *new_h = getNewHashTable(h->size * 2);
    for(int i = 0; i < h->size; i++){
        Node *p = h->data[i].next;
        while(p){
            insert(new_h, p->s);
            p = p->next;
        }
    }
    new_h->cnt = h->cnt;
    clearHashTable(h);
    return new_h;
}


void output(HashTable* h){
    for(int i = 0; i < h->size; i++){
        printf("%d : ", i);
        Node *p = h->data[i].next;
        while(p){
            printf("%10s --->", p->s);
            p = p->next;
        }
        cout << endl;
    }

    return;
}

int main(){
    srand(time(0));
    char s[100];
    #define MAX_N 2
    HashTable* h = getNewHashTable(MAX_N);
    while(~scanf("%s", s)){
        if(strcmp(s, "end") == 0) break;
        insert(h, s);
    }
    output(h);
    while(~scanf("%s", s)){
        if(strcmp(s, "end") == 0) break;
        printf("find(%s) = %d\n", s, find(h, s));
    }
    #undef MAX_N
    return 0;
}

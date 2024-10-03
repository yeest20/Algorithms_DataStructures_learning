/*************************************************************************
	> File Name: 04.haffman.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Thu 26 Sep 2024 10:12:19 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define ROOT 1
#define FATHER(I) I / 2
#define LEFT(I) I * 2
#define RIGHT(I) I * 2 + 1

typedef struct Node{
    char ch;
    int freq;
    struct Node* lchild, *rchild;
} Node;

typedef struct Heap{
    Node**__data, **data;
    int size, n;
}Heap;

Heap *getNewHeap(int size){
    Heap *h = (Heap*)malloc(sizeof(Heap));
    h->__data = (Node**)malloc(sizeof(Node *) * size);
    h->data = h->__data - 1;
    h->n = 0;
    h->size = size;
    return h;
}

void clear(Heap* h){
    if(h == NULL) return;
    free(h->__data);
    free(h);
    return;
}

int isfull(Heap* h){
    return h->size == h->n;
}

void surface(Heap* h, int i){
    while(i > ROOT && h->data[i]->freq < h->data[FATHER(i)]->freq){
        swap(h->data[FATHER(i)],h->data[i]);
        i = FATHER(i);
    }
    return;
}

int push(Heap* h, Node* val){
    if(isfull(h)) return 0;
    h->n += 1;
    h->data[h->n] = val;
    surface(h, h->n);
    return 1;
}

int isempty(Heap* h){
    return h->n == 0;
}

void submerge(Heap* h){
    int i = ROOT;
    while(LEFT(i) < h->n){
        int ind = i, l = LEFT(i), r = RIGHT(i);
        if(h->data[l]->freq < h->data[ind]->freq) ind = l;
        if(h->data[r]->freq < h->data[ind]->freq) ind = r;
        if(ind == i) break;
        swap(h->data[ind],h->data[i]);
        i = ind;
    }
    return;
}
Node* top(Heap* h){
    if(isempty(h)) return NULL;
    return h->data[1];
}

int pop(Heap* h){
    if(isempty(h)) return 0;
    h->data[1] = h->data[h->n];
    h->n -= 1;
    submerge(h);
    return 1;
}

Node* getNewNode(int freq, char ch){
    Node *p = (Node*)malloc(sizeof(Node));
    p->ch = ch;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node* root){
    if(root == NULL) return;
    clear(root->lchild);
    clear(root->rchild);
    return;
}

void swap(Node **node_arr, int i, int j){
    Node* temp = node_arr[i];
    node_arr[i] = node_arr[j];
    node_arr[j] = temp;
    return;
}

Node* buildHaffmanTree(Node** node_arr, int n){
    for(int i = 0; i < n; i++){
        printf("%c %d\n", node_arr[i]->ch, node_arr[i]->freq);
    }
    cout << endl;
    Heap* h = getNewHeap(n);
    for(int i = 0; i < n; i++){
        push(h, node_arr[i]);
    }
        
    Node *left, *right;
    for(int i = 1; i < n; i++){
        left = top(h);
        pop(h);
        right = top(h);
        pop(h);
        Node* newnode = getNewNode(left->freq + right->freq, '0');
        newnode->lchild = left;
        newnode->rchild = right;
        push(h, newnode);
    }
    Node* root = top(h);
    clear(h);
    return root;
}

char *char_code[128] = {0};

void getHaffmanCode(Node* root, char buff[], int k){
    buff[k] = 0;
    if(root->lchild == NULL && root->rchild == NULL){
        printf("%c : %s\n", root->ch, buff);
        char_code[root->ch] = strdup(buff);
        return;
    }
    buff[k] = '0';
    getHaffmanCode(root->lchild, buff, k + 1);
    buff[k] = '1';
    getHaffmanCode(root->rchild, buff, k + 1);
    return;
}

int main(){
    // 用s读c,保证正确率
    char s[10];
    int n, freq;    
    scanf("%d", &n); 
    // 节点数组 存储节点化的字符信息
    Node** node_arr = (Node **)malloc(sizeof(Node *) * n);
    for(int i = 0; i < n; i++){
        scanf("%s %d", s, &freq);
        node_arr[i] = getNewNode(freq, s[0]);
    } 
    Node *root = buildHaffmanTree(node_arr, n);
    cout << "build tree debug..." << endl;
    char buff[1000];
    getHaffmanCode(root, buff, 0);
    /*for(int i  = 0; i < 128; i++){
        if(char_code[i] == NULL) continue;
        printf("%c : %s\n", i, char_code[i]);
    }*/
    cout << endl;
    clear(root);
    return 0;
}

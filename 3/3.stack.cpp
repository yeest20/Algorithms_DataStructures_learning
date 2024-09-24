/*************************************************************************
	> File Name: 3.stack.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Mon 23 Sep 2024 05:27:11 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

typedef struct Stack{
    int *data;
    int size, top;
} Stack;

Stack* initStack(int n){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
} 

void clear(Stack *s){
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return;
}

int expand(Stack *s){
    s->data = (int *)realloc(s->data, sizeof(int) * s->size * 2); 
    if(s->data == NULL) return 0;
    s->size *= 2;
    return 1;
}

int push(Stack* s, int val){
    if(s == NULL) return 0;
    if(s->top + 1 == s->size && !expand(s)) return 0;
    s->data[s->top + 1] = val;
    s->top += 1;
    return 1;
}

int pop(Stack* s){
    if(s->top < 0) return 0;
    if(s == NULL) return 0;
    s->top -= 1;
    return 1;
}

int seekTop(Stack* s){
    if(s->top < 0) return 0;
    if(s == NULL) return 0;
    return s->data[s->top];

}

void output_stack(Stack* s){
    for(int i = s->top; i >= 0; i--){
        printf("| %1d |\n", s->data[i]);
        printf("-----\n");
    }
    return;
}

int main(){
    srand(time(0));
    #define MAX_OP 10
    Stack* s = initStack(MAX_OP);
    for(int i = 0; i < 2 * MAX_OP; i++){
        int OP = rand() % 3;
        int val = rand() % 10, ret;
        switch(OP){
            case 0: case 1:
                ret = push(s, val);
                printf("push %d to stack at top %d is %d\n", val, s->top, ret);
                output_stack(s);
                break;
            case 2:
                ret = pop(s);
                printf("pop from stack is %d\n", ret);
                printf("seek top %d\n", seekTop(s));
                output_stack(s);
                break;
        }
    }
    clear(s);
    return 0;
}

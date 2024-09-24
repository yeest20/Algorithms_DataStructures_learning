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
#include<string>

using namespace std;

typedef struct Stack{
    char *data;
    int size, top;
} Stack;

Stack* initStack(int n){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (char*)malloc(sizeof(char) * n);
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
    s->data = (char *)realloc(s->data, sizeof(char) * s->size * 2); 
    if(s->data == NULL) return 0;
    s->size *= 2;
    return 1;
}

int push(Stack* s, char val){
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

char seekTop(Stack* s){
    if(s->top < 0) return 0;
    if(s == NULL) return 0;
    return s->data[s->top];

}

void output_stack(Stack* s){
    for(int i = s->top; i >= 0; i--){
        printf("| %c |\n", s->data[i]);
        printf("-----\n");
    }
    return;
}

void testStack(Stack* s){
    srand(time(0));
    #define MAX_OP 10
    for(int i = 0; i < 2 * MAX_OP; i++){
        int OP = rand() % 3;
        int val = rand() % 10, ret;
        switch(OP){
            case 0: case 1:
                ret = push(s, val);
                printf("push %c to stack at top %d is %d\n", val, s->top, ret);
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
    return;
}


int main(){
    string str;
    while(cin >> str){
        Stack* s = initStack(10); 
        int flag = 1;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
                push(s, str[i]);
                continue;
            }
            if(str[i] == ')'){
                if(seekTop(s) != '(' ){
                    flag = 0;
                    break;
                }
                pop(s);
            }
            if(str[i] == ']'){
                if(seekTop(s) != '['){
                    flag = 0;
                    break;
                }
                pop(s);
            }
            if(str[i] == '}'){
                if(seekTop(s) != '{'){
                    flag = 0;
                    break;
                }
                pop(s);
            }
        }
        if(s->top != -1) flag = 0;
        if(flag) {
            cout << "true" << endl;
        }else{
            cout << "false" << endl;
        } 
        clear(s);
    }
    return 0;
}

/*************************************************************************
	> File Name: 04.set_Heap.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Sat 28 Sep 2024 06:11:13 PM CST
 ************************************************************************/

#include<iostream>
#include<set>
#include<ctime>
using namespace std;

void test1(){
    cout << "set base usage" << endl;
    set<int> s;
    cout << s.size() <<endl;
    s.insert(3);
    s.insert(4);
    cout << s.size() << endl;
    return;
}

void test2(){
    cout << "set item unique feature : " <<  endl;
    set<int> s;
    cout << s.size() << endl;
    s.insert(3);
    cout << s.size() << endl;
    s.insert(4);
    cout << s.size() << endl;
    s.insert(4);
    cout << s.size() << endl;
    return;
}

void test3(){
    cout << "set item unique feature but use pair : " <<  endl;
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0;
    cout << s.size() << endl;
    s.insert(PII(3, tot++));
    cout << s.size() << endl;
    s.insert(PII(4, tot++));
    cout << s.size() << endl;
    s.insert(PII(4, tot++));
    cout << s.size() << endl;
    return;
}

void test4(){
    cout << "foreach set item : " <<  endl;
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0;
    s.insert(PII(3, tot++));
    s.insert(PII(5, tot++));
    s.insert(PII(4, tot++));
    s.insert(PII(4, tot++));

    for(auto x : s){
        cout << x.first << " " << x.second << endl;
    }
    return;
}

void test5(){
    cout << "set replace heap : " << endl;
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0;
    for(int i = 0; i < 10; i++){
        s.insert(PII(rand() % 20, tot++));
    }
    for(auto x : s){
        cout << "(" << x.first << " " << x.second << ")" << endl;
    }
    for(int i = 0; i < 4; i++){
        cout << "s.begin() = " << s.begin()->first << endl;
        s.erase(s.begin());  
    }
    return ;
}

int main(){
    srand(time(0));
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
    return 0;
}



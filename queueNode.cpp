#include<iostream>
#include<string>
using namespace std;
class node{
    private:
        string userName;
        node* next;
    public:
        node(string name){
            userName = name;
            next = NULL;
        }
}
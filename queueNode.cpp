#include<iostream>
#include<string>
using namespace std;
class node{
    public:
        int userID;
        node* next;
        node(int id){
            userID = id;
            next = NULL;
        }
};
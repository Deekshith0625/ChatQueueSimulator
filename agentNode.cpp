#include<iostream>
using namespace std;
class Agent{
    private:
        int ID;
        node* next;
    public:
        node(int id){
            ID = id;
            next = NULL;
        }
};
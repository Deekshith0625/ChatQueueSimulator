#include<iostream>
#include<string>
using namespace std;
class chatQueue{
    private:
        string username;
        int userid;
    public:
        chatQueue();
};

class node{
    private:
        int data;
        node*next;

    public:
    
    node(){
        next=NULL;
    }
};

int main(){
    cout<<"DS project"<<endl;
    int choice;
    while(1){
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"In agent"<<endl;
                break;
                return 0;
        }
    }
}
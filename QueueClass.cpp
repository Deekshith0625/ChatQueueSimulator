#include<iostream>
using namespace std;
class Queue {
    private:
        node* front;
        node* rear;
    
    public:
        Queue() {
            front = NULL;
            rear = NULL;
        }
        void joinQueue(int Id);
        void serveCompleted(vector<Agent>& agents);
        void showQueue();
    };
    void Queue::joinQueue(int Id) {
        node* newUser = new node(Id);
        if (rear == NULL) {
            front = rear = newUser;
        } else {
            rear->next = newUser;
            rear = newUser;
        }
        cout << "User " << Id << " joined the queue.\n";
    }
    void Queue::serveCompleted(vector<Agent>& agents) {
        if (front == NULL) {
            cout << "No users in queue.\n";
            return;
        }
        for (auto& agent : agents) {
            if (agent.isAvailable) {
                node* temp = front;
                front = front->next;
                if (front == NULL) rear = NULL;
    
                agent.isAvailable = false; 
    
                cout << "Agent " << agent.ID << " is now serving User " << temp->userID << "\n";
                delete temp;
                return;
            }
        }
        cout << "No available agents at the moment. Please wait.\n";
    }
    
    void Queue::showQueue() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }
    
        cout << "Current Queue: ";
        node* temp = front;
        while (temp != NULL) {
            cout << temp->userID << " ";
            temp = temp->next;
        }
       cout << "\n";
    }
    
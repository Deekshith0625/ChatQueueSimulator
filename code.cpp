#include<iostream>
#include<string>
#include<vector>
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
class Agent{
    public:
        int ID;
        bool isAvailable;
        Agent(int id){
            ID = id;
            isAvailable = true;
         }
};



class Queue {
    private:
        node* front;
        node* rear;
    
    public:
        Queue() {
            front = nullptr;
            rear = nullptr;
        }
        void joinQueue(int Id);
        void serveCompleted(vector<Agent>& agents);
        void showQueue();
    };
    void Queue::joinQueue(int Id) {
        node* newUser = new node(Id);
        if (rear == nullptr) {
            front = rear = newUser;
        } else {
            rear->next = newUser;
            rear = newUser;
        }
        cout << "User " << Id << " joined the queue.\n";
    }
    void Queue::serveCompleted(vector<Agent>& agents) {
        if (front == NULL) {
            std::cout << "No users in queue.\n";
            return;
        }
        for (auto& agent : agents) {
            if (agent.isAvailable) {
                node* temp = front;
                front = front->next;
                if (front == NULL) rear = NULL;
    
                agent.isAvailable = false; 
    
                cout << "Agent " << agent.ID<< " is now serving User " << temp->userID << "\n";
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
        while (temp != nullptr) {
            cout << temp->userID << " ";
            temp = temp->next;
        }
       cout << "\n";
    }
    
    
 

void releaseAgent(vector<Agent>& agents, int agentId) {
    for (auto& agent : agents) {
        if (agent.ID == agentId) {
            if (!agent.isAvailable) {
                agent.isAvailable = true;
               cout << "Agent " << agent.ID<< " is now available.\n";
            } else {
                cout << "Agent " << agent.ID << " is already available.\n";
            }
            return;
        }
    }
    cout << "Agent ID not found.\n";
}



int main() {
    Queue chatQueue;
    int choice, Id = 1;
    int numAgents;

    cout << "Enter number of agents: ";
   cin >> numAgents;

    vector<Agent> agents;
    for (int i = 1; i <= numAgents; ++i) {
        agents.push_back(Agent(i));
    }

    while (true) {
        cout << "\n--- Chat Queue Menu ---\n";
        cout << "1. New user joins\n";
        cout << "2. Serve next user\n";
       cout << "3. Release agent\n";
        cout << "4. Show queue\n";
        cout << "5. Exit\n";
       cout << "Enter choice: ";
      cin >> choice;

        switch (choice) {
            case 1:
                chatQueue.joinQueue(Id++);
                break;
            case 2:
                chatQueue.serveCompleted(agents);
                break;
            case 3: {
                int Id;
                cout << "Enter Agent ID to release: ";
                cin >> Id;
                releaseAgent(agents, Id);
                break;
            }
            case 4:
                chatQueue.showQueue();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}
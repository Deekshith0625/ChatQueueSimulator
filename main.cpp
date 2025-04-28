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
        vector<pair<int,int>> servingList;
        void showServingList();
        void releaseUser(vector<Agent>& agents, int userId);
        bool isUserAlreadyExist(int userId);
    };
    void Queue::joinQueue(int Id) {
        if (isUserAlreadyExist(Id)) {
            cout << "Error: User ID " << Id << " is already in the queue or being served.\n";
            return;
        }
        
        node* newUser = new node(Id);
        if (rear == nullptr) {
            front = rear = newUser;
        } else {
            rear->next = newUser;
            rear = newUser;
        }
        cout << "User : " << Id << " joined the queue.\n";
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
    
                cout << "Agent : " << agent.ID << " is now serving User " << temp->userID << "\n";
                servingList.push_back({agent.ID, temp->userID});

                delete temp;
                return;
            }
        }
        cout << "No available agents at the moment. Please wait.\n";
    }
    bool Queue::isUserAlreadyExist(int userId) {
        // Check queue
        node* temp = front;
        while (temp != nullptr) {
            if (temp->userID == userId) {
                return true;
            }
            temp = temp->next;
        }
    
        // Check serving list
        for (const auto& pair : servingList) {
            if (pair.second == userId) {
                return true;
            }
        }
    
        return false;
    }
    
    void Queue:: releaseUser(vector<Agent>& agents,  int userId) {
        for (auto it = servingList.begin(); it != servingList.end(); ++it) {
            if (it->second == userId) {
                int agentId = it->first;
    
                // Find the agent and set them as available
                for (auto& agent : agents) {
                    if (agent.ID == agentId) {
                        agent.isAvailable = true;
                        break;
                    }
                }
    
                servingList.erase(it);
                cout << "User : " << userId << " has been released. Agent " << agentId << " is now available.\n";
                return;
            }
        }
        cout << "User ID : " << userId << " not found in serving list.\n";
    }
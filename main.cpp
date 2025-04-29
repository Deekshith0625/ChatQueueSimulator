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

    void Queue:: showServingList() {
        if (servingList.empty()) {
            cout << "No agents are currently serving users.\n";
            return;
        }
        cout << "Currently Serving:\n";
        for (const auto& pair : servingList) {
            cout << "Agent " << pair.first << " is serving User " << pair.second << "\n";
        }
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
    int choice, userId;
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
         cout<<"5.show serving list\n";
        cout<<"6.Release user\n";
        cout<<"7.EXIT";
       cout << "Enter choice: ";
       
      cin >> choice;

        switch (choice) {
            case 1:
                cout<<"Enter User ID to join Queue :";
                cin>>userId;
                chatQueue.joinQueue(userId);
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
                chatQueue.showServingList();
                break;
            case 6:
                int user;
                cout<<"enter the user ID to release";
                cin>>user;
                chatQueue.releaseUser(agents,user);
                break;
            case 7:
                return 0;
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
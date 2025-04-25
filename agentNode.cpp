#include<iostream>
using namespace std;
class Agent{
    public:
        int ID;
        bool isAvailable;
        Agent(int id){
            ID = id;
            isAvailable = true;
         }
};

void releaseAgent(vector<Agent>& agents, int agentId) {
    for (auto& agent : agents) {
        if (agent.ID == agentId) {
            if (!agent.isAvailable) {
                agent.isAvailable = true;
               cout << "Agent " << agent.ID << " is now available.\n";
            } else {
                cout << "Agent " << agent.ID << " is already available.\n";
            }
            return;
        }
    }
    cout << "Agent ID not found.\n";
}

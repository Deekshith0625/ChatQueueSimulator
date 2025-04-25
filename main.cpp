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
               cout << "Invalid choice.\n";
        }
    }
}

Chat Queue Management System (C++)
Overview

A console-based C++ application that simulates a customer support queue system. It manages users waiting for service and assigns them to available agents efficiently using a queue-based approach.

Use Case
Customer support/chat systems
Call center management
Helpdesk or ticketing systems
Queue-based service applications
Key Features
Add users to queue (no duplicates allowed)
Assign users to available agents
Track active agent-user sessions
Release users and free agents
Display queue and serving list
Tech Stack
Language: C++
Concepts: OOP, Linked List, Queue (FIFO)
STL: vector, pair
How It Works
Users join a queue
Available agents are assigned users
Active sessions are tracked
Users can be released after service
Agents become available again
Run the Project
g++ main.cpp -o chat_queue
./chat_queue

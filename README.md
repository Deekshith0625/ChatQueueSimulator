# Chat Queue Management System (C++)

## Overview
A console-based C++ application that simulates a customer support queue system. It manages users waiting for service and assigns them to available agents efficiently using a queue-based approach.

## Use Case
- Customer support/chat systems  
- Call center management  
- Helpdesk or ticketing systems  
- Queue-based service applications  

## Key Features
- Add users to queue (no duplicates allowed)  
- Assign users to available agents  
- Track active agent-user sessions  
- Release users and free agents  
- Display queue and serving list  

## Tech Stack
- Language: C++  
- Concepts: OOP, Linked List, Queue (FIFO)  
- STL: vector, pair  

## How It Works
1. Users join a queue  
2. Available agents are assigned users  
3. Active sessions are tracked  
4. Users can be released after service  
5. Agents become available again  

## Run the Project
```bash
g++ main.cpp -o chat_queue
./chat_queue

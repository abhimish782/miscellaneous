#include <iostream>
#include <vector>
#include <queue>
 // checking for github
std::vector<int> roundRobinLoadBalancer(int n, const std::vector<int>& arrival, const std::vector<int>& burstTime) {
    std::vector<int> result;
    std::queue<int> availableServers;
    std::vector<int> serverEndTime(n, 0);

    for (size_t i = 0; i < arrival.size(); ++i) {
        int requestTime = arrival[i];
        int requestBurstTime = burstTime[i];

        // Clear any servers whose end time has passed
        while (!availableServers.empty() && serverEndTime[availableServers.front()] <= requestTime) {
            availableServers.pop();
        }

        if (availableServers.empty()) {
            // All servers are busy; drop the request
            result.push_back(0);
        } else {
            int assignedServer = availableServers.front();
            availableServers.pop();

            // Assign the request to the server
            result.push_back(assignedServer + 1); // Add 1 to convert to 1-based indexing
            serverEndTime[assignedServer] = requestTime + requestBurstTime;

            // Put the server back in the queue
            availableServers.push(assignedServer);
        }
    }

    return result;
}

int main() {
    int n = 3;  // Number of servers
    std::vector<int> arrival = {3,5,1,6,8};  // Arrival times of requests
    std::vector<int> burstTime = {9,2,10,4,5};  // Burst times of requests

    std::vector<int> serverAssignments = roundRobinLoadBalancer(n, arrival, burstTime);

    for (int server : serverAssignments) {
        std::cout << server << " ";  // This will print the assigned server indexes for each request
    }

    return 0;
}

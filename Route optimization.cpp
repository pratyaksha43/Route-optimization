/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int destination;
    int distance;
    int travelTime;
};


void dijkstra(vector<vector<Edge>>& graph, int start, int end) {
    int numNodes = graph.size();

   
    vector<int> distances(numNodes, INT_MAX);
    vector<int> travelTimes(numNodes, INT_MAX);
    distances[start] = 0;
    travelTimes[start] = 0;

    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        
        if (currentDistance > distances[currentNode])
            continue;

        
        for (Edge& neighbor : graph[currentNode]) {
            int neighborNode = neighbor.destination;

            
            cout << "Enter weight (distance) for edge " << currentNode << " -> " << neighborNode << ": ";
            cin >> neighbor.distance;
            cout << "Enter weight (travel time) for edge " << currentNode << " -> " << neighborNode << ": ";
            cin >> neighbor.travelTime;

            int distance = currentDistance + neighbor.distance;
            int totalTime = travelTimes[currentNode] + neighbor.travelTime;

            
            if (distance < distances[neighborNode]) {
                distances[neighborNode] = distance;
                travelTimes[neighborNode] = totalTime;
                pq.push({distance, neighborNode});
            }
        }
    }

   
    cout << "Shortest Distance: " << distances[end] << " units" << endl;
    cout << "Traveling Time: " << travelTimes[end] << " minutes" << endl;
}

int main() {
    int numNodes = 6;
    vector<vector<Edge>> graph(numNodes);

    
    graph[0].push_back({1, 0, 0}); 
    graph[0].push_back({2, 0, 0});
    graph[1].push_back({3, 0, 0});
    graph[1].push_back({4, 0, 0});
    graph[2].push_back({1, 0, 0});
    graph[2].push_back({4, 0, 0});
    graph[3].push_back({4, 0, 0});
    graph[3].push_back({5, 0, 0});
    graph[4].push_back({5, 0, 0});

    int startNode, endNode;

    
    cout << "Enter start node (0 to " << numNodes - 1 << "): ";
    cin >> startNode;
    cout << "Enter end node (0 to " << numNodes - 1 << "): ";
    cin >> endNode;

    
    if (startNode < 0 || startNode >= numNodes || endNode < 0 || endNode >= numNodes) {
        cout << "Invalid start or end node. Exiting." << endl;
        return 1;
    }


    dijkstra(graph, startNode, endNode);

    return 0;
}



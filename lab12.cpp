#include <iostream>
#include <vector>
#include <queue>


using namespace std;

#define INFINITY 9999

typedef pair<int, int> pii; // vertex, distance

vector<vector<pii>> adjList; // adjacency list
vector<int> dist; // shortest distance from source to each vertex
priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap priority queue

// Dijkstra's Algorithm
void dijkstra(int src)
{
    dist[src] = 0;
    pq.push({dist[src], src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto v : adjList[u])
        {
            if (dist[v.first] > dist[u] + v.second)
            {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int main()
{
    // initialize adjacency list
    adjList = {
        {{1, 10}, {4, 15}, {5,5}},
        {{0, 10}, {2, 10}, {3, 30}},
        {{1, 10}, {3, 12}, {4, 5}},
        {{1, 30}, {2, 12}, {5, 20}},
        {{0, 15}, {2, 5}},
        {{0, 5}, {3, 20}}
    };

    // initialize distances to infinity
    dist.resize(adjList.size(), INFINITY);

    // choose source vertex
    int src = 0;

    // run Dijkstra's Algorithm
    dijkstra(src);

    // print shortest distances from source vertex
    for (int i = 0; i < adjList.size(); i++)
    {
        if (i == src){
            continue;
        }
        cout << "Shortest distance from City " << src << " to City " << i << ": ";
        if (dist[i] == INFINITY)
            cout << "INFINITY" << endl;
        else
            cout << dist[i] << endl;
    }


    
    return 0;
}

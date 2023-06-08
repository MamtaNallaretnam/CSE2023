#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int INF = 1e9;
const int MAXN = 6;

vector<pair<int, int>> adj[MAXN];
bool vis[MAXN];

int prim() {
  int mst_cost = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    int u = pq.top().second, w = pq.top().first;
    pq.pop();
    if (vis[u]) continue;
    vis[u] = true;
    mst_cost += w;
    for (auto e : adj[u]) {
      int v = e.first, w = e.second;
      if (!vis[v])
        pq.push({w, v});
    }
  }
  return mst_cost;
}

int main() {
  adj[0].push_back({1, 3});
  adj[0].push_back({5, 1});
  adj[1].push_back({0, 3});
  adj[1].push_back({2, 2});
  adj[1].push_back({3, 1});
  adj[1].push_back({4, 10});
  adj[2].push_back({1, 2});
  adj[2].push_back({3, 3});
  adj[2].push_back({5, 5});
  adj[3].push_back({1, 1});
  adj[3].push_back({2, 3});
  adj[3].push_back({4, 5});
  adj[4].push_back({1, 10});
  adj[4].push_back({3, 5});
  adj[4].push_back({5, 4});
  adj[5].push_back({0, 1});
  adj[5].push_back({2, 5});
  adj[5].push_back({4, 4});
  int mst_cost = prim();
  cout << "Minimum spanning tree cost: " << mst_cost << endl;
  return 0;
}

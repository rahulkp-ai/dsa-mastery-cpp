/**
 * Graph Algorithms - C++20
 * ==========================
 * BFS, DFS, Dijkstra, Topological Sort
 *
 * Time:  BFS/DFS O(V+E), Dijkstra O((V+E)logV)
 * Space: O(V+E)
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <limits>
#include <numeric>

namespace dsa
{

    class Graph
    {
        int V;
        std::vector<std::vector<std::pair<int, int>>> adj; // {neighbor, weight}
        bool directed;

    public:
        explicit Graph(int v, bool directed = false)
            : V(v), adj(v), directed(directed) {}

        void addEdge(int u, int v, int w = 1)
        {
            adj[u].push_back({v, w});
            if (!directed)
                adj[v].push_back({u, w});
        }

        // BFS - O(V+E)
        std::vector<int> bfs(int start)
        {
            std::vector<bool> visited(V, false);
            std::queue<int> q;
            std::vector<int> order;

            visited[start] = true;
            q.push(start);

            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                order.push_back(u);
                for (auto [v, w] : adj[u])
                {
                    if (!visited[v])
                    {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            return order;
        }

        // Dijkstra - O((V+E)logV)
        std::vector<int> dijkstra(int src)
        {
            std::vector<int> dist(V, std::numeric_limits<int>::max());
            std::priority_queue<std::pair<int, int>,
                                std::vector<std::pair<int, int>>,
                                std::greater<>>
                pq;
            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty())
            {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dist[u])
                    continue;
                for (auto [v, w] : adj[u])
                {
                    if (dist[u] + w < dist[v])
                    {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        }
    };

    // Union-Find (DSU)
    class UnionFind
    {
        std::vector<int> parent, rank_;

    public:
        int components;
        explicit UnionFind(int n) : parent(n), rank_(n, 0), components(n)
        {
            std::iota(parent.begin(), parent.end(), 0);
        }

        int find(int x)
        {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int x, int y)
        {
            int px = find(x), py = find(y);
            if (px == py)
                return false;
            if (rank_[px] < rank_[py])
                std::swap(px, py);
            parent[py] = px;
            if (rank_[px] == rank_[py])
                ++rank_[px];
            --components;
            return true;
        }

        bool connected(int x, int y) { return find(x) == find(y); }
    };

} // namespace dsa

int main()
{
    dsa::Graph g(5);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);

    auto bfsOrder = g.bfs(0);
    std::cout << "BFS: ";
    for (int v : bfsOrder)
        std::cout << v << " ";
    std::cout << "\n";

    auto dist = g.dijkstra(0);
    std::cout << "Dijkstra from 0: ";
    for (int d : dist)
        std::cout << d << " ";
    std::cout << "\n";

    return 0;
}

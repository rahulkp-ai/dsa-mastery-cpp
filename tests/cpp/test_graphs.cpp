#include "test_common.hpp"
#include "../../cpp/graphs/graph.cpp"

int main() {
    dsa::Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    CHECK_EQ(g.bfs(0), std::vector<int>{0, 1, 2, 3});
    CHECK_EQ(g.dijkstra(0), std::vector<int>{0, 1, 2, 3});
    dsa::UnionFind uf(3);
    CHECK(uf.unite(0, 1));
    CHECK(uf.connected(0, 1));
    return 0;
}

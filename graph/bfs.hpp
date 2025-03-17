#pragma once

#include <vector>
#include <queue>

//BFS
//重みなしグラフにおける最短経路問題
std::vector<int> bfs(const std::vector<std::vector<int>> &G, int start, int unreachable) {
    std::queue<int> Q;
    std::vector<int> dist((int)G.size(), unreachable);
    Q.push(start);
    dist[start] = 0;
    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
        for (int to : G[pos]) {
            if (dist[to] != unreachable) continue;
            Q.push(to);
            dist[to] = dist[pos]+1;
        }
    }
    return dist;
}
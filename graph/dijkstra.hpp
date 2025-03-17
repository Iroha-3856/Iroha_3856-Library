#pragma once

#include <vector>
#include <utility>
#include <queue>

#include "Edge.hpp"

//dijkstra
//重み付きグラフにおける最短経路問題
std::vector<long long> dijkstra(const std::vector<std::vector<Edge>>& G, int start, long long impossible) {
    int N = (int)G.size();
    std::vector<long long> dist(N, impossible);
    std::priority_queue<std::pair<long long, int>, 
                        std::vector<std::pair<long long, int>>, 
                        std::greater<std::pair<long long, int>>> Q;
    dist[start] = 0LL;
    Q.emplace(dist[start], start);
    while(!Q.empty()) {
        auto[d, v] = Q.top(); Q.pop();
        if (dist[v] != d) continue;
        for (Edge e : G[v]) {
            if (dist[e.to]==impossible || dist[e.to]>d+e.cost) {
                dist[e.to] = d+e.cost;
                Q.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}
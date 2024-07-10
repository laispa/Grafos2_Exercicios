

#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 };
vector<ii> adj[MAX];

vector<int> dijkstra(int s, int N, vector<int>& parent)
{
    const int oo { 1000000010 };

    vector<int> dist(N + 1, oo);
    dist[s] = 0;
    parent[s] = -1;

    set<ii> U;
    U.emplace(0, s);

    while (not U.empty())
    {
        auto [d, u] = *U.begin();
        U.erase(U.begin());

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > d + w)
            {
                if (U.count(ii(dist[v], v)))
                    U.erase(ii(dist[v], v));

                dist[v] = d + w;
                parent[v] = u;
                U.emplace(dist[v], v);
            }
        }
    }

    return dist;
}



int main(){

    return 0;
}

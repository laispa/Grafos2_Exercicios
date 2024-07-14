
#include <bits/stdc++.h>
#include <climits>

using namespace std;
using ii = pair<long long, long long>;

const long long  MAX { 100010 };
vector<ii> adj[MAX];
vector<long long> path;


vector<long long> dijkstra(long long s, long long  N, vector<long long>& parent)
{
    const long long  oo { LONG_LONG_MAX };

    vector<long long > dist(N + 1, oo);
    dist[s] = 0;
    parent[s] = -1;

    set<ii> U;
    U.emplace(0, s);

    while (!U.empty())
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
    long long  n, m;
    cin >> n >> m;

    for (int  i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(ii(b, w));
    }

    vector<long long> parent(n + 1, -1);
    auto dist = dijkstra(1, n, parent);

    for (int i=1; i<=n ; i++){
        if(dist[i]!=LONG_LONG_MAX)
            cout << dist[i] << ' ';

    }
        cout << '\n';
    
    return 0;
}

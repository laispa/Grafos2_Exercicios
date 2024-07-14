
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

void findPath( long long n, vector<long long>& parent) {
    std::vector<long long> temp;

    while (n != -1) {
        temp.push_back(n); 
        n = parent[n];
    }

    for (int i = temp.size() - 1; i >= 0; --i) {
        path.push_back(temp[i]);
    }

}

int main(){
    long long  n, m;
    cin >> n >> m;

    for (long long i = 0; i < m; i++) {
        long long a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(ii(b, w));
        adj[b].push_back(ii(a, w));
    }

    vector<long long> parent(n + 1, -1);
    auto dist = dijkstra(1, n, parent);

    if (dist[n] == LONG_LONG_MAX) {
        cout << -1 << '\n';
    } else {
        findPath(n, parent);
        for (long long  result : path)
            cout << result << ' ';
        cout << '\n';
    }

    return 0;
}

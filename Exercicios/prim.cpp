#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 100010 };

vector<ii> adj[MAX];

long long prim(int u, size_t N)
{
    vector<bool> visited(N + 1, false); 
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    pq.emplace(0, u);

    long long mst = 0;

    while (!pq.empty())
    {
        int v, w;

        tie(w, v) = pq.top();
        pq.pop();

        if (!visited[v]){
            mst += w;
            visited[v] = true;

            for (auto [s, p] : adj[v])
            {
                if (!visited[s])
                    pq.emplace(p, s);
            }

        }

       
    }

    for(int i = 1; i <=N; i++){
        if(!visited[i])
            return -1;
    }

    return mst;
}

int main()
{
    int n, m, a, b, c;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    auto result = prim(1, n);

    if (result == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << result << '\n';

    return 0;
}

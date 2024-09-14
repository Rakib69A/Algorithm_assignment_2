#include <bits/stdc++.h>
using namespace std;
long long int INF = 1e18;
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 1e3 + 5;
long long int dis[N];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    int s;
    cin >> s;
    dis[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INF && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        bool cycle = false;
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INF && dis[u] + c < dis[v])
            {
                cycle = true;
                break;
            }
        }
        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
        else
        {
            if (dis[d] == INF)
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }
    }
    // for (int i = 0; i < n; i++)
    //     cout << i << " -> " << dis[i] << endl;
    return 0;
}
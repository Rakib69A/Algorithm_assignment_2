#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;
const int N = 1005;

vector<pair<int, ll>> adj[N];  
ll dis[N];  


void dijkstra(int s) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dis[s] = 0;
    pq.push({0, s});  

    while (!pq.empty()) {
        pair<ll,int> par = pq.top();
        ll cost = par.first;
        int node = par.second;
        pq.pop();

        for (auto child : adj[node]) {      
            int childNode = child.first;
            ll childCost = child.second;

            if (cost + childCost < dis[childNode]) {
                dis[childNode] = cost + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;

    while(e--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        // bool flag = false;
        // for(auto edge: adj[u]){
        //     if(edge.first == v){
        //         flag = true;
        //         edge.second = min(edge.second,w);
        //     }
        // }
        // if(flag == false)
            // adj[u].push_back({v, w});  
        adj[u].push_back({v, w});  
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    int s;
    cin >> s;

    dijkstra(s);

    int q;
    cin >> q;

    while (q--) {
        int d;
        ll dw;
        cin >> d >> dw;
        if(s == d)
            cout<<"YES"<<endl;
        else if (dis[d] <= dw) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

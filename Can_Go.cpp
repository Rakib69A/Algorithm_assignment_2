#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
const long long int INF = 1e18;
vector<pair<int, int>> v[1005];
ll dis[1005];
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        int cost = parent.second;
        for (pair<int, int> child : v[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // v[a].push_back({b, c});
        bool flag = false;
        for(auto edge: v[a]){
            if(edge.first == b){
                flag = true;
                edge.second = min(edge.second,c);
            }
        }
        if(flag == false)
            v[a].push_back({b, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    int s;
    cin>>s;
    // single node
    if (n == 1) {
        int q;
        cin >> q;
        while (q--) {
            int d, dw;
            cin >> d >> dw;
            if (d == s && dw >= 0) {
                cout << "YES" << endl; // The same node with cost 0
            } else {
                cout << "NO" << endl; // No path if destination is not the source
            }
        }
        return 0;
    }
    dijkstra(s);
    int t;
    cin>>t;
    while(t--){
        ll d,dw;
        cin>>d>>dw;
        if(dis[d] <= dw)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}
/*
Constrains
1 <= Nodes <= 1000
1 <= Edges <= 1000
1 <= Source <= N
1 <= Testcase <= 1000
1 <= Distance <= N
0 <= Weight, DistanceWeight <= 10^9

*/
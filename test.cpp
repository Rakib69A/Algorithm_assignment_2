#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<ll,ll>> v[n+1];
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
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
    int mx = 0;
    for(int i=1;i<=n;i++){
        for(pair<int,int> child : v[i]){
        cout<<i<<" -> ";
        cout<<child.first<<" "<<child.second<<endl;
    }
    }
    return 0;
}
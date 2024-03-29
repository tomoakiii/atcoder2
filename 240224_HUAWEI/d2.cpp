#include <bits/stdc++.h>
#define xx first
#define yy second
#define ll long long
using namespace std;

int main(){
	ll n,m;
	cin>>n>>m;
	vector<vector<array<int,5>>> adj(n+10);
	
	for(int i =1;i<=m;i++){
		int l,d,k,c,a,b;
		cin>>l>>d>>k>>c>>a>>b;
		adj[b].push_back({a,l,d,k,c});
	}
	
	vector<ll> dis(n+10,-1);
	
	priority_queue<pair<ll,ll>> q;
	q.push({(ll)4e18,n});
	
	while(!q.empty()){
	
		auto [dx,x] = q.top();
		q.pop();
		
		if(dis[x]!=-1) continue;
		dis[x] = dx;
		
		for(auto [a,l,d,k,c]:adj[x]){
			ll m = dx-c;
			if(m>=l){
				 m = l + min((m-l)/d,1ll*(k-1))*d;
				 q.push({m,a});
			}
		}
	}
	  for (int i = 1; i <= n - 1; i++) {
        if (dis[i] == -1) {
             cout << "Unreachable\n";
        } else {
            cout << dis[i] << "\n";
        }
    }

	return 0;
}
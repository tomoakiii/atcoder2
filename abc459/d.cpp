#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

void solve(){
    string S; cin>>S;
    int N=S.size();
    map<char,ll> mp;
    ll mx=0;
    priority_queue<pair<ll,char>> que;
    for(auto c:S){
        mp[c]++;
        chmax(mx, mp[c]);
    }
    if(mx>(N+1)/2) {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    for(auto [c,v]:mp){
        que.push({v,c});
    }
    string str="";
    while(!que.empty()){
        auto [v,c]=que.top();
        que.pop();
        while(v--){
            str.push_back(c);
        }
    }
    string ans(N, 'x');
    int id=0;
    for(int i=0; i<N; i+=2) ans[i]=str[id++];
    for(int i=1; i<N; i+=2) ans[i]=str[id++];
    cout<<ans<<endl;
}


int main(){
    ll T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
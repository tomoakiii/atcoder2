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

int main(){
    ll N;
    cin >> N;
    map<ll,int> mp;
    int id = -1;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        if(!mp.contains(A[i])) {
            id++; mp[A[i]] = id;
        }
    }
    rep(i,N) A[i] = mp[A[i]];
    vector uv(id+1, vector<int>{});
    rep(i,N) {
        int j = N-i-1;
        uv[A[i]].push_back(A[j]);
    }
    vector<bool> visit(id+1);
    int ans = 0;
    auto f = [&](auto f, int cur)->void{
        visit[cur] = true;
        for(auto nx: uv[cur]) {
            if(visit[nx]) continue;
            ans++;
            f(f, nx);
        }
    };
    rep(i,id+1) {
        if(!visit[i]) f(f,i);
    }
    
    cout<<ans<<endl;
    return 0;
}
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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    map<int, int> mp;
    for(int i=1; i<=N; i++) {
        mp[2*i] = A[i-1];
        mp[2*i + 1] = A[i-1];
    }
    map<int, int> ans;
    ans[0] = 0; ans[1] = 0;
    for(int k=1; k<=2*N+1; k++) {
        
        auto f = [&](auto f, int p, int cnt) -> ll {
            if (p <= 1) return cnt;
            if (ans.count(p) == 0) ans[p] = f(f, mp[p], cnt+1);
            return cnt+ans[p];
            
        };
        cout << f(f, k, 0) << endl;
    }
    return 0;
}
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
    vector<int> f(N+1);
    rep(i,N+1) f[i] = i;
    for(int i=2; i<=N; i++) {
        int x = i*i;
        if(x>N) break;
        for(int j=i; j<=N; j+=i) while(f[j]%x == 0) f[j]/=x;
    }
    vector<ll> ans(N+1);
    ll out = 0;
    for(int i=1; i<=N; i++) ans[f[i]]++;
    for(int i=1; i<=N; i++) out += ans[i] * ans[i];
    cout << out << endl;

    return 0;
}
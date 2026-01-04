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
    ll N,a,b,K;
    cin >> N>>a>>b>>K;
    a--,b--;
    vector<ll> visit(N);
    visit[a] = visit[b] = true;
    rep(i,K) {
        ll p; cin>>p; p--;
        if(visit[p]){
            cout << "NO"<<endl;
            return 0;
        }
        visit[p] = true;
    }
    cout << "YES" << endl;
    return 0;
}
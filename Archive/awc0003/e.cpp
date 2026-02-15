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
    ll N,M;
    cin >> N >> M;
    vector<ll> W(N),C(M);
    ll wsm = 0, csm = 0;
    rep(i,N) {
        cin>>W[i];
        wsm += W[i];
    }
    rep(i,M) {
        cin>>C[i];
        csm += C[i];
    }
    if(csm < wsm) {
        cout<<"No"<<endl;
        return 0;
    }
    sort(W.rbegin(),W.rend());
    sort(C.rbegin(),C.rend());
    
    bool flg = false;
    auto func = [&](auto func, int cur)->void{
        if(cur == N) {
            flg = true;
            return;
        }
        rep(i,M) {
            if(flg) return;
            if(C[i] >= W[cur]) {
                C[i] -= W[cur];
                func(func, cur+1);
                C[i] += W[cur];
            }
        }
    };
    func(func, 0);
    if(flg) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
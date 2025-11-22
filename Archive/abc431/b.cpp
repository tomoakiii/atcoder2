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
    ll X,N; cin>>X>>N;
    vector<ll> W(N);
    rep(i,N) cin>>W[i];
    int Q; cin>>Q;
    vector<bool> equip(N);
    while(Q--) {
        int p; cin>>p; p--;
        if(!equip[p]) {
            equip[p] = true;
            X += W[p];
        } else {
            equip[p] = false;
            X -= W[p];
        }
        cout<<X<<endl;
    }

    return 0;
}
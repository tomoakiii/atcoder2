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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        A[i]--;
    }
    ll M = 40;
    vector to(M, vector<pair<ll,ll>>(N));
    rep(i,N) {
        to[0][i] = {i,0};
        to[1][i] = {A[i],i+1};
   }

    for(int m=2; m<M; m++) {
        rep(i,N) {
            ll one = to[m-1][i].first; // 1回目、誰までついた
            ll two = to[m-1][one].first; // 2回め
            to[m][i].first = two;
            to[m][i].second = to[m-1][i].second + to[m-1][one].second;
        }
    }

    while(Q--) {
        ll t,b; cin>>t>>b; b--;
        int id = 1;
        int nx = b;
        ll w = 0;
        while(t){
            if(t%2 == 1) {
                w += to[id][nx].second;
                nx = to[id][nx].first;
            }
            id++;
            t /= 2;
        }
        cout << w << endl;
    }
    return 0;
}
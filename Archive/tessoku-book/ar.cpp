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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll N,Q;
    cin>>N>>Q;
    bool turn = false;
    vector<int> A(N);
    rep(i,N) A[i] = i+1;
    while(Q--){
        int q; cin>>q;
        if(q==1) {
            ll x,y; cin>>x>>y;
            x--;
            if(turn) x = N-x-1;
            A[x] = y;
        } else if (q == 2) {
            turn = !turn;
        } else {
            ll x; cin>>x;
            x--;
            if(turn) x = N-x-1;
            cout << A[x] << endl;
        }
    }
    return 0;
}
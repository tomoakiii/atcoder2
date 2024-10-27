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
    vector<ll> A(N, 0);
    rep(i,N) cin>>A[i];
    ll Q;
    cin >> Q;
    while(Q--){
        int p;
        cin >> p;
        if (p == 1) {
            int k, x;
            cin >> k >> x;
            k--;
            A[k] = x;
        } else {
            int k;
            cin >> k;
            k--;
            cout << A[k] << endl;
        }
    }    
    return 0;
}
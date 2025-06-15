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
    rep(i,N) A[i]=i+1;
    ll st = 0;
    while(Q--){
        ll q;
        cin>>q;
        if(q==1) {
            ll p; ll x;
            cin>>p>>x;
            p--;
            A[(st + p) % N] = x;
        } else if(q==2) {
            ll p; cin>>p;
            p--;
            cout << A[(st + p) % N] << endl;
        } else {
            ll p; cin>>p;
            st+=p;
            st%=N;
        }
    }
    
    return 0;
}
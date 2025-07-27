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
    ll T; cin>>T;
    while(T--) {
        ll N,M; cin>>N>>M;
        vector<ll> A(N), B(N);
        multiset<ll> stA;
        rep(i,N) {
            cin>>A[i];
            A[i] %= M;
            stA.insert(A[i]);
        }
        rep(i,N) {
            cin>>B[i];
            B[i] %= M;
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        ll id = lower_bound(A.begin(), A.end(), M-B[0]) - A.begin();
        if(id == N) {
            id = 0;
        }
        ll sm = 0; 
        rep(i,N) {
            ll b = B[i];
            auto s = stA.lower_bound(M-B[i]);
            if(s==stA.end()) {
                sm += B[i]; 
            } else {
                sm += (b + *s)%M;
                stA.erase(s);
            }            
        }
        for(auto s: stA) sm += s;
        cout << sm << endl;
    

    }
    return 0;
}
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
    ll sm = 0;

    vector<ll> g2{}, g1{};
    rep(i,N) {
        ll a = A[i];
        if(a%2==0) g2.push_back(i);
        else g1.push_back(i);
        while(a) {
            a/=2;
        }
        sm += a;
    }
    ll sm1 = 0;
    for(auto g:g1) {
        sm1 += g;
    }
    for(auto g:g2) {
        sm += (g + sm1);
    }
    
    cout << sm << endl;


    return 0;
}
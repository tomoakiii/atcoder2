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
    vector<ll> C(N-1),S(N-1),F(N-1);
    rep(i,N-1) cin>>C[i]>>S[i]>>F[i];
    rep(k,N) {
        ll ss = k;
        ll st = 0;
        for(int i=ss; i<N-1; i++){
            if(S[i] > st) st = S[i];
            st = ((st + F[i] - 1) / F[i]) * F[i];
            st += C[i];
        }
        cout<<st<<endl;
    }

    return 0;
}
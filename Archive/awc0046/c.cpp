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
    int last=0;
    ll ans=0;
    rep(i,N) {
        if(A[i]==1) last++;
        else {
            if(last==2) {
                last=0;
            } else if(i<N-1 && last==1 && A[i+1]==1) {
                last=0;
            } else if(i<N-2 && A[i+1]==1 && A[i+2]==1) {
                last=0;
            } else {
                ans++;
                last++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
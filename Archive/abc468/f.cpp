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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> Y(N+1,INF);
    Y[0]=0;
    ll mx=0;
    ll ans=0;
    rep(i,N){
        if(A[i]>mx) {
            mx=A[i];
            ans++;
        } else {
            auto it = lower_bound(Y.begin(), Y.end(), A[i])-Y.begin();
            Y[it]=A[i];
        }
    }

    for(int i=N;i>=0;i--){
        if(Y[i]<INF){
            ans += i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N-1);
    ll last; cin>>last;
    ll total=0;
    rep(i,N-1) {
        ll a; cin>>a;
        A[i] = abs(a-last);
        total += A[i];
        last = a;
    }
    if(total<K) {
        cout<<-1<<endl;
        return 0;
    }
    ll r=0;
    ll sm=0;
    ll ans=INF;
    rep(i,N-1){
        while(r<N-1 && sm<K) {
            sm+=A[r];
            r++;
        }
        if(sm>=K) chmin(ans, r-i+1);
        sm -= A[i];
    }
    cout<<ans<<endl;
    return 0;
}
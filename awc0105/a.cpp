#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
<<<<<<< HEAD
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ans=0;
    int st = 0;
    string S; cin>>S;
    for(auto c:S){
        if(c=='R') {
            st++;
        } else {
            st+=N;
            st--;
        }
        st%=N;
        ans += A[st];
    }
=======
    ll N;
    cin >> N;
    ll ans=0;
>>>>>>> 762c96cd907c5c0e9074087b1e61f9c27f58aeb4
    cout<<ans<<endl;
    return 0;
}
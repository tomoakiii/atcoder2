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
    ll N,T,K;
    cin >> N >> T >> K;
    if(N==K){
        cout << 0 << endl;
        return 0;
    }
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<bool> ord(N,true);
    rep(i,K)ord[i]=false;
    ll ans = INF;
    do{
        ll last = INF;
        int lasti = -1;
        ll cnt = 0;
        rep(i,N) {
            if(!ord[i])continue;
            ll gap = abs(A[i]-last);
            ll len = i-lasti;
            if(gap > len * T) cnt++;
            last = A[i];
            lasti = i;
        }
        chmin(ans,cnt);
    }while(next_permutation(ord.begin(),ord.end()));
    cout << ans-1 << endl;
    return 0;
}

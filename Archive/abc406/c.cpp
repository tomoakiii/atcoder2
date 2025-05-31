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
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    ll ld1 = 0, ld2 = -1, lu1 = 0, lu2 = -1;
    ll ans = 0; 
    bool flg = false;
    for(int i=1; i<N; i++) {
        if(i<N-1){
            if(P[i-1] < P[i] && P[i] > P[i+1]) {
                lu2 = max((ll)0, lu1);
                lu1 = i;
            }
            if(P[i-1] > P[i] && P[i] < P[i+1]) {
                ld2 = max((ll)0, ld1);
                ld1 = i;
            }
        }        
        if(!flg) {
            if(lu1 == 0 || ld1 == 0) {                
            } else {
                flg = true;                
            }
            continue;
        }
        if(P[i] < P[i-1]) continue;
        if(lu2==0 && ld2 == 0) {
            ans += lu1;
        } else if (lu1 == i) {
            ans += lu2 - ld2;
        } else {
            ans += lu1 - ld2;
        }
    }
    cout << ans << endl;

    return 0;
}
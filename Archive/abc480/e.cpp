#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef __uint128_t ut;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    ll ans = 0;
    for(ut beg=1; beg<=1e7 ; beg++){
        ut p = beg*(beg+1)*(beg+2);
        if(p > N) break;
        ut k;
        for(ll length=3, k=beg+2; ; length++){
            ut ok=1, ng=1e18;
            while(ng-ok>1){
                ut c = (ok+ng)/2;
                ut q=1;
                for(ut i=0; i<length; i++){
                    q*=(beg + c*i);
                }
                if(q<=N)ok=c;
                else ng=c;
            }
            ans += ok;
            k++;
            p*=k;
            if(p>N)break;

        }
    }
    cout << ans << endl;
    return 0;
}

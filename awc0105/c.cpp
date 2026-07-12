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
    ll N; string S;
    cin >> N >> S;
    ll ans=0;
    auto getXOR = [](string S)->ll{
        ll p1=0;
        for(auto c:S){
            p1 = p1 ^ c;
        }
        return p1;
    };
    for(int k=1;k<=N-1;k++){
        string S1 = S.substr(0,k);
        string S2 = S.substr(k,N-k);
        ll p1 = getXOR(S1);
        ll p2 = getXOR(S2);
        ll D = INF;
        bool flg=true;
        rep(i,N){
            ll a = S[i];
            if(i<k) a^=p2;
            else a^=p1;
            ll dl = 97-a;
            ll dr = 122-a;
            if(dr < 0) {
                flg = false;
                break;
            }
            if(D<dl) {
                flg=false;
                break;
            }
            chmin(D,dr);
        }
        if(flg) {
            // cerr << S1 << " " << S2 << endl;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
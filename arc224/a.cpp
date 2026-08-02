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
    ll T;
    cin >> T;
    while(T--){
        ll N; cin>>N;
        rep(i,101){
            ll x = N*(i+1);
            ll cnt=0;
            bool flg=false;
            while(x){
                if(x%10==0)cnt++;
                else cnt=0;
                x/=10;
                if(cnt==2){
                    flg=true;
                    break;
                }
            }
            if(flg){
                cout<<N*(i+1)<<endl;
                break;
            }
        }
    }
    return 0;
}
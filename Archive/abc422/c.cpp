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
    ll T;
    cin >> T;
    while(T--) {
        long a,b,c;
        cin>>a>>b>>c;
        long ans = 0;
        ans = min(a,min(b,c));
        a-=ans, b-=ans, c-=ans;
        if(a==0 || c==0) {
            cout<<ans<<endl;
            continue;
        }
        if(c<a) swap(a,c);
        if(a < c-a) {
            ans += a;
            cout<<ans<<endl;
            continue;
        }
        ans += c-a;
        a -= (c-a);
        ans += a*2/3;
        cout << ans << endl;
    }
    return 0;
}
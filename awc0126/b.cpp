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
typedef modint1000000007 mint;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string Ns;
    ll K,R;
    cin >> Ns >> K >> R;
    if(K>1){
        cout<<0<<endl;
        return 0;
    }
    mint ans=0;
    for(auto c:Ns){
        ans*=10;
        ans+=c-'0';
    }
    ans-=2;
    cout<<ans.val()<<endl;
    return 0;
}
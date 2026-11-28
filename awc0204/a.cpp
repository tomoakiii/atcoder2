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
    ll N;
    cin >> N;
<<<<<<< HEAD
    string S; cin>>S;
    for(auto c:S)if(c=='x'){
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;
=======
    ll ans=0;
    cout<<ans<<endl;
>>>>>>> 48f498569788a15edf75f47ebe405de0ad692429
    return 0;
}
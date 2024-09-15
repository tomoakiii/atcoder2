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
    ll N, M;
    cin >> N >> M;
    vector<bool> family(N+1, false);
    rep(i, M) {
        int a;
        char b;
        cin>>a>>b;
        if (b != 'M') {
            cout<<"No"<<endl;
            continue;
        }

        if(!family[a]){
            family[a] = true;
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}
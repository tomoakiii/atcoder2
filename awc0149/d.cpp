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
    ll N,P;
    cin >> N >> P;
    vector<int> jdg(N+1);
    rep(i,N){
        ll h,g; cin>>h>>g;
        ll p = (P-h)/g;
        if(h>P){
            cout<<"No"<<endl;
            return 0;
        }
        if(p>N)continue;
        jdg[p]++;
    }
    rep(i,N){
        jdg[i+1]+=jdg[i];
        if(jdg[i]-1 > i){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
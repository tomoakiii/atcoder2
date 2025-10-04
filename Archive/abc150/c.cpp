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
    vector<ll> P(N),Q(N);
    rep(i,N) cin>>P[i];
    rep(i,N) cin>>Q[i];
    vector<ll> O(N);
    rep(i,N) O[i] = i+1;
    int a, b;
    int i=0;
    do{
        bool f = true;
        rep(i,N) if(O[i]!=P[i]) f=false;
        if(f) a=i;
        f=true;
        rep(i,N) if(O[i]!=Q[i]) f=false;
        if(f) b=i;
        i++;
    }while(next_permutation(O.begin(), O.end()));
    cout<<abs(a-b)<<endl;
    return 0;
}
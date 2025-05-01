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
typedef modint998244353 mint;

int main(){
    int N;
    cin>>N;
    vector<ll> X(N), Y(N);
    rep(i,N) cin>>X[i]>>Y[i];
    map<ll, ll> mpl;
    map<ll, ll> mpr;
    string S;
    cin>>S;
    rep(i,N){
        char c=S[i];
        if(c=='L'){
            if(mpl.count(Y[i])) {
                if(mpl[Y[i]]<X[i]) mpl[Y[i]]=X[i];
            } else {
                mpl[Y[i]]=X[i];
            }
        } else {
            if(mpr.count(Y[i])) {
                if(mpr[Y[i]]>X[i]) mpr[Y[i]]=X[i];
            } else {
                mpr[Y[i]]=X[i];
            }
        }
    }
    for(auto m: mpl) {
        if(mpr.count(m.first) && mpr[m.first] <= m.second) {
            cout << "Yes" << endl;
            return 0;
        }
//        cout<<m.second<<endl;
    }
    cout << "No" << endl;
    return 0;
}
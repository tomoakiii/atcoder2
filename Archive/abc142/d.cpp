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
    vector<ll> A(2);
    cin>>A[0]>>A[1];
    vector<unordered_set<ll>> v(2);
    rep(k,2){
        for(ll i = 2; i*i <= A[k]; i++) {
            if(A[k]%i != 0) continue;
            while(A[k]%i == 0) {
                A[k]/=i;
            }
            v[k].insert(i);
        }
        if(A[k]!=1) v[k].insert(A[k]);
    }

    int cnt = 1;
    for(auto s: v[0]) {
        if(v[1].contains(s)) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
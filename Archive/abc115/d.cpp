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

vector<ll> np(51, -1);
vector<ll> nt(51, -1);

void fnc(ll x){
    if(x==0) {
        np[0] = 1;
        nt[0] = 1;
    } else {
        fnc(x-1);
        np[x] = 2*np[x-1] + 1;
        nt[x] = 2*nt[x-1] + 3;
    }
}

ll fnc2(ll x, ll p){
    if(nt[x] == p) return np[x];
    else if(2*nt[x-1] + 2 <= p) {
        return 2*np[x-1]+1;
    } else if(nt[x-1] + 2 <= p) {
        return np[x-1] + 1 + fnc2(x-1, p-2-nt[x-1]);
    } else if(nt[x-1] + 1 <= p) {
        return np[x-1];
    } else if(1 <= p) {
        return fnc2(x-1, p-1);
    } else {
        return 0;
    }
}


int main(){
    ll N, X;
    cin >> N >> X;
    fnc(50);
    cout<<fnc2(N, X)<<endl;
    return 0;
}
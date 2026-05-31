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
    ll Top;
    cin >> Top;
    while(Top--){
        ll N,S,K;
        cin>>N>>S>>K;
        S %= N;
        K %= N;
        S = N - (S%N);
        ll g = gcd(K,N);
        if(S%g != 0) {
            cout<<-1<<endl;
            continue;
        }
        S/=g; K/=g; N/=g;
        modint mi;
        mi.set_mod(N);
        mi = S;
        mi = mi / K;
        cout<< mi.val() << endl;
    }
    return 0;
}
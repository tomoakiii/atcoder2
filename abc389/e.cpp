#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef pair<ll, int> pli;
int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    sort(P.begin(), P.end());        

    auto judge = [&](ll q)-> bool {        
        ll sm = q;
        rep(i,N) {
            ll t = (ll)sqrt((double)q/(double)P[i]);
            sm += t * t * P[i];
        }
        if(sm <= M) return true;
        else return false;
    };

    ll l = 0, r = M+1;
    while(r - l > 1){
        ll c = (r + l)/2;
        if(judge(c)) {
            l = c;
        } else {
            r = c;
        }
    }

    vector<ll> Num(N, 0);
    ll ans = 0;    
    ll sm = 0;
    rep(i,N) {
        ll t = (ll)sqrt((double)l/(double)P[i]);
        sm += t * t * P[i];
        Num[i] = t;
        ans += t;
    }

    vector<ll> lst(N);
    rep(i, N) {
        lst[i] = ((Num[i]+1)*(Num[i]+1) - Num[i]*Num[i]) * P[i];        
    }

    sort(lst.begin(), lst.end());
    for(ll t: lst) {
        if(sm + t > M) {
            cout <<  ans << endl;
            return 0;
        } else {
            sm += t;
            ans++;
        }
    }

    return 0;
}
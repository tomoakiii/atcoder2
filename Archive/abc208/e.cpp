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
    ll N, K; cin>>N>>K;
    vector<int> digit;
    while(N) {
        digit.push_back(N%10);
        N/=10;
    }
    reverse(digit.begin(), digit.end());
    map<ll,ll> mp1;
    ll tp = digit[0];
    for(ll i=1; i<digit[0]; i++) {
        mp1[i] = 1;
    }
    for(ll i = 1; i < digit.size(); i++) {
        ll d = digit[i];
        map<ll,ll> mp2;        
        for(ll j=1; j<=9; j++) {
            mp2[j]++;
        }
        for(auto [x, c] : mp1) {            
            for(ll j=0; j<=9; j++) {
                mp2[j*x] += c;
            }
        }
        for(ll j=0; j<d; j++) {
            mp2[j*tp]++;            
        }
        swap(mp2, mp1);
        tp *= d;
    }
    mp1[tp]++;
    ll ans = 0;
    for(auto [m, c]: mp1) if(m <= K) ans+=c;    
    cout<<ans<<endl;
    return 0;
}
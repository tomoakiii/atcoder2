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
    if(N==0 || N==1) {
        cout<<N<<endl;
        return 0;
    }

    ll mn=0, mx=1;
    ll p = 1;
    ll k = 1;
    string S;
    vector<pair<ll,ll>> mm;
    mm.push_back({0,1});
    while(true) {
        p *= 2;
        k *= -1;
        chmin(mn, mn + p*k);
        chmax(mx, mx + p*k);
        if(mn <= N && N <= mx) {
            S.push_back('1');
            N -= p*k;
            p /= 2;
            k *= -1;
            break;
        }
        mm.push_back({mn,mx});
    }
    while(mm.size() > 0) {
        auto [mn, mx] = mm.back();
        if(mm.size() >= 2) {
            auto [nmn, nmx] = mm[mm.size() - 2];
            if(nmn <= N && N <= nmx) {
                S.push_back('0');
            } else {
                S.push_back('1');
                N -= p*k;
            }
        } else {
            if(N == 1) {
                S.push_back('1');
            } else {
                S.push_back('0');
            }
        }
        mm.pop_back();
        p /= 2;
        k *= -1;
    }
    cout<<S<<endl;
    return 0;
}
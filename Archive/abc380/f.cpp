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
typedef tuple<vector<ll>, vector<ll>, vector<ll>> tvv;
int main(){
    ll N, M, L;
    cin >> N >> M >> L;
    vector<ll> A(N), B(M), C(L);    
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];
    rep(i,L) cin>>C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    map<tvv, bool> mp;

    auto func = [&](auto func, tvv intvv)->bool{
        if(mp.count(intvv)) return mp[intvv];
        auto [a,b,c] = intvv;        
        bool flg = false;
        rep(i, a.size()){
            auto na = a, nc = c;
            nc.push_back(a[i]);
            na.erase(na.begin() + i);            
            sort(nc.begin(), nc.end());
            flg |= (!func(func, tvv(b,na,nc)));
            rep(j, c.size()) {
                if(c[j] < a[i]) {
                    auto nc2 = nc, na2 = na;
                    nc2.erase(nc2.begin() + j);
                    na2.push_back(nc[j]);
                    sort(na2.begin(), na2.end());
                    flg |= (!func(func, tvv(b,na2,nc2)));
                }
            }            
        }    
        mp[intvv] = flg;
        return mp[intvv];
    };    
    if(func(func, tvv(A,B,C))) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}
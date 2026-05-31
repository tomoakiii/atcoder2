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
    ll Rt,Ct,Ra,Ca; cin>>Rt>>Ct>>Ra>>Ca;
    ll N,M,L; cin >> N >> M >> L;
    vector<char> Dt(M), Da(L);
    vector<ll> Nt(M), Na(L);
    map<char,int> dmp;
    dmp['U'] = 0;
    dmp['R'] = 1;
    dmp['D'] = 2;
    dmp['L'] = 3;
    
    rep(i,M) {        
        cin >> Dt[i] >> Nt[i];        
    }
    rep(i,L) {
        cin >> Da[i] >> Na[i];
    }
    int l = 0, r = 0;
    ll Rt2, Ct2, Ra2, Ca2;
    ll ans = 0;
    while(l<M || r<L) {
        auto mov = [](char d, ll y, ll x, ll nm) -> pair<ll,ll> {
            if(d == 'D') y += nm;
            if(d == 'U') y -= nm;
            if(d == 'R') x += nm;
            if(d == 'L') x -= nm;
            return {y,x};
        };
        
        auto step = [&](ll nm)->void{
            Na[r] -= nm;
            Nt[l] -= nm;
            auto mret = mov(Dt[l], Rt, Ct, nm);
            Rt2 = mret.first, Ct2 = mret.second;
            mret = mov(Da[r], Ra, Ca, nm);
            Ra2 = mret.first, Ca2 = mret.second;
            if(Na[r] == 0) {
                r++;
            }
            if(Nt[l] == 0) {
                l++;
            }
        };
        
        char dt = Dt[l], da = Da[r];
        bool issame = (Rt==Ra && Ct==Ca);
        bool issamed = (Dt[l]==Da[r]);
        bool isopd = ( (dmp[Dt[l]] + 2)%4 == dmp[Da[r]] ); 
        ll nm;
        if(l == N) {
            nm = Na[r];
        } else if (r == N) {
            nm = Nt[l];
        } else {
            nm = min(Nt[l], Na[r]);
        }
        step(nm);
        if(issamed) {
            if(issame) ans += nm;
        } else if (isopd) {
            if ( (Ra == Rt && Ct > Ca && Ct2 <= Ca2 && (Ct-Ca)%2 == 0) || 
                (Ra == Rt && Ct < Ca && Ct2 >= Ca2 && (Ca-Ct)%2 == 0) || 
                (Ca == Ct && Rt > Ra && Rt2 <= Ra2 && (Rt-Ra)%2 == 0) || 
                (Ca == Ct && Rt < Ra && Rt2 >= Ra2 && (Ra-Rt)%2 == 0) ) {
                ans++;
            }
        } else if (!issame) {
            ll mv = (dt == 'U' || dt == 'D') ? abs(Rt - Ra) : abs(Ct - Ca);
            chmin(mv, nm);
            auto [Rxt, Cxt] = mov(dt, Rt, Ct, mv);
            auto [Rxa, Cxa] = mov(da, Ra, Ca, mv);
            if(Rxt == Rxa && Cxt == Cxa) {
                ans++;
            }
        }
        swap(Ra, Ra2); swap(Ca, Ca2);
        swap(Rt, Rt2); swap(Ct, Ct2);
    }
    cout << ans << endl;
    return 0;
}
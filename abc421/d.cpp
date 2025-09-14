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
    rep(i,M) {        
        cin >> Dt[i] >> Nt[i];        
    }
    rep(i,L) {
        cin >> Da[i] >> Na[i];
    }
    ll ans = 0;
    ll cnt = 0;
    int l = 0, r = 0;
    ll Rt2, Ct2, Ra2, Ca2;
    ll cl=0, cr=0;
    while(l<N && r<N) {
        if(cl < cr) {
            if(Dt[l] == 'D') Rt2 = Rt + Nt[l];
            if(Dt[l] == 'U') Rt2 = Rt - Nt[l];
            if(Dt[l] == 'R') Ct2 = Ct + Nt[l];
            if(Dt[l] == 'L') Ct2 = Ct - Nt[l];
            
            if(Dt[l] == 'D' && (Rt < Ra && Ra <= Rt2)) ans++;
            if(Dt[l] == 'U' && (Rt2 <= Ra && Ra < Rt)) ans++;
            if(Dt[l] == 'R' && (Ct < Ca && Ca <= Ct2)) ans++;
            if(Dt[l] == 'L' && (Ct2 <= Ca && Ca < Ct)) ans++;
            swap(Rt, Rt2); swap(Ct, Ct2);
            cl += Nt[l]; l++;
        } else {
            if(Da[l] == 'D') Ra2 = Ra + Na[r];
            if(Da[l] == 'U') Rt2 = Rt - Na[r];
            if(Da[l] == 'R') Ca2 = Ca + Na[r];
            if(Da[l] == 'L') Ca2 = Ca - Na[r];
            
            if(Da[l] == 'D' && (Ra < Rt && Rt <= Ra2)) ans++;
            if(Da[l] == 'U' && (Ra2 <= Rt && Rt < Ra)) ans++;
            if(Da[l] == 'R' && (Ca < Ct && Ct <= Ca2)) ans++;
            if(Da[l] == 'L' && (Ca2 <= Ct && Ct < Ca)) ans++;
            swap(Ra, Ra2); swap(Ca, Ca2);
            cr += Na[r]; r++;
        }
    }
    cout << ans << endl;
    return 0;
}
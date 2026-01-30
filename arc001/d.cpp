#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
typedef long double ld;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    ld st, gl;
    ld ans = 0;
    cin >> N >> st >> gl;

    auto dist = [&](ld dx, ld dy) -> ld {
        return sqrtl(dx*dx+dy*dy);
    };
    if(N==1) {
        cout << abs(gl - st) << endl;
        return 0;
    } else if(N==2) {
        printf("%.20Lf\n", dist(1, gl-st));
        return 0;
    }
    ld L(N), R(N);
    ld l,r; cin>>l>>r;
    rep(i,N) cin>>L[i]>>R[i];
    L[N-1] = R[N-1] = gl;
    ld la = -INF, ra = INF;
    ld bx = 0;
    ld x = 0;
    rep(i,N) {
        ld l = L[i], r = R[i];
        x += 1;
        ld dx = x - bx;
        ld y0 = st + la*dx, y1 = st + ra*dx;
        ld nla = (l-st)/dx, nra = (r-st)/dx;
        if(i==N-1) {

        }
        if(nla >= ra) {
            ld nst = st + ra * (dx-1);
            ans += dist(dx-1, nst - st);
            st = nst;
            bx = x-1;
            la = l-st, ra = r-st;
        } else if (nra <= la) {
            ld nst = st + la * (dx-1);
            ans += dist(dx-1, nst - st);
            st = nst;
            bx = x-1;
            la = l-st, ra = r-st;
        } else {
            if(la <= nla) la = nla;
            if(nra <= ra) ra = nra;
        }
    }

    printf("%.20Lf\n", ans);
    return 0;
}
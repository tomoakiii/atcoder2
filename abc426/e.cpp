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
typedef long double ld;
int main(){
    ll T; cin>>T;
    while(T--) {
        ld tsx, tsy, tgx, tgy;
        cin>>tsx>>tsy>>tgx>>tgy;
        ld asx, asy, agx, agy;
        cin>>asx>>asy>>agx>>agy;
        auto dist = [](ld x1, ld x2, ld y1, ld y2)->ld{
            return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        };
        ld ans = dist(tsx, asx, tsy, asy);
        chmin(ans, dist(tgx, agx, tgy, agy));

        ld tl = dist(tsx, tgx, tsy, tgy);
        ld al = dist(asx, agx, asy, agy);
        if(al<tl) {
            swap(tsx,asx);
            swap(tsy,asy);
            swap(tgx,agx);
            swap(tgy,agy);
            swap(tl,al);
        }            
        ld tdy = (tgy - tsy) / tl;
        ld tdx = (tgx - tsx) / tl;

        ld ady = (agy - asy) / al;
        ld adx = (agx - asx) / al;
    
        ld dy = (ady-tdy);
        ld dx = (adx-tdx);

        ld A = dy*dy + dx*dx;
        ld B = 2*(asy-tsy)*dy + 2*(asx-tsx)*dx;
        ld t = -B/2/A;        

        if(t<=tl && t>=0) {
            ld tny = tsy + tdy * t;
            ld tnx = tsx + tdx * t;
            ld any = asy + ady * t;
            ld anx = asx + adx * t;
            chmin(ans, dist(tnx, anx, tny, any));            
        }
        ld any = asy + ady * tl;
        ld anx = asx + adx * tl;        
        chmin(ans, dist(tgx, anx, tgy, any));

        ld A2 = sqrt(adx*adx + ady*ady);
        ld B2 = 2*adx*(anx-tgx) + 2*ady*(any-tgy);
        ld t2 = -B2/2/A2;        

        if (t2 + tl <= al && t2 >= 0) {
            ld any2 = any + ady * t2;
            ld anx2 = anx + adx * t2;
            chmin(ans, dist(tgx, anx2, tgy, any2));            
        }        
        printf("%.10Lf\n", ans);
        continue;
    }
    return 0;
}
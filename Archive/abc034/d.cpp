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
typedef pair<double, pair<double,double>> pil;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<pil> A(N);
    rep(i,N) {
        double w,p,s;
        cin>>w>>p;
        p/=100;
        s = p * w;
        A[i].second.second = s;
        A[i].second.first = w - s;
        A[i].first = p;
    }
    vector<bool> visit(N);
    pil cur = {0,{0,0}};
    pil ncur;
    while(K--) {
        double mx = 0;
        int j = 0;
        rep(i,N) {
            if(visit[i]) continue;
            auto [ad, ap] = A[i];
            auto [aw, as] = ap;
            auto [d, p] = cur;
            auto [w, s] = p;
            double nw = aw + w;
            double ns = as + s;
            double nd = (ns) / (nw + ns);
            if(chmax(mx, nd)) {
                j = i;
                ncur = {nd, {nw,ns}};
            }
        }
        visit[j] = true;
        cur = ncur;
    }
    printf("%.10f\n", cur.first*100);
    return 0;
}
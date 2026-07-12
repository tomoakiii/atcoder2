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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    vector<pair<ll,int>> A(N+Q);
    vector<ll> B(N);
    rep(i,N) {
        cin>>A[i].first>>B[i];
        A[i].second=i;
    }
    rep(j,Q) {
        ll x; cin>>x;
        A[j+N].first = x;
        A[j+N].second = -(j+N);
    }
    sort(A.rbegin(),A.rend());
    vector<ll> ans(Q);
    vector<bool> visit(N);

    dsu UF(N);
    ll tmp = 0;
    auto rpr = B;
    for(auto [x,i]:A){
        if(i<0){
            i*=-1;
            ans[i-N]=tmp;
        } else {
            auto upd=[&](int cur, int nx)->void{
                ll v = rpr[UF.leader(nx)];
                tmp -= v;
                int nc = UF.leader(cur);
                ll nv = max(v, rpr[nc]);
                int nl = UF.merge(cur,nx);
                rpr[nl] = nv;
            };
            if(i>0 && visit[i-1]) {
                upd(i, i-1);
            }
            if(i<N-1 && visit[i+1]) {
                upd(i, i+1);
            }
            visit[i]=true;
            tmp += rpr[UF.leader(i)];
        }
    }
    for(auto a:ans)cout<<a<<endl;
    return 0;
}
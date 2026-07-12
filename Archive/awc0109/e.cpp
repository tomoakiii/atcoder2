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
    ll N,K,Q;
    cin >> N >> K >> Q;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i]>>B[i];
    vector<vector<ll>> Cb(K), Gb(K);
    auto get = [&](int l, int r, ll g)->pair<ll,ll>{
        ll cnt=0;
        for(int s=l; s<=r; s++){
            g+=A[s]-B[s];
            if(g<0) g=0;
            if(g>=K){
                cnt++;
                g=0;
            }
        }
        return {cnt,g};
    };
    ll sq = sqrt(N);
    vector<pair<int,int>> ind;
    int st = 0;
    while(st<N){
        int ed = st + sq;
        if(ed >= N) ed=N-1;
        ind.push_back({st, ed});
        rep(k,K){
            auto gt = get(st, ed, k);
            Cb[k].push_back(gt.first);
            Gb[k].push_back(gt.second);
        }
        st = ed + 1;
    }

    rep(i,Q) {
        int l, r; cin>>l>>r; l--, r--;
        ll cnt=0, g=0;
        rep(k, ind.size()){
            auto [st, ed] = ind[k];
            if(ed < l){
                continue;
            } else if(l<=st && ed<=r) {
                cnt += Cb[g][k];
                g = Gb[g][k];
                continue;
            } else if(st<=l && l<=ed){
                int r2 = min(r, ed);
                auto [c2,g2] = get(l, r2, 0);
                g = g2;
                cnt += c2;
                continue;
            } else if(r <= ed) {
                auto [c2,g2] = get(st, r, g);
                g = g2;
                cnt += c2;
                break;
            } else {
                break;
            }
        }
        cout<<cnt<<" "<<g<<endl;
    }

    return 0;
}
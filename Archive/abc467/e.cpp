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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N), B(N-1);
    rep(i,N) cin>>A[i];
    rep(i,N-1) cin>>B[i];
    vector<ll> C(N);
    C[0] = 0;
    for(int i=1; i<N; i++){
        C[i] = (B[i-1] - C[i-1] + M) % M;
    }
    deque<pair<ll,bool>> V(N);
    ll ne = 0, no = 0;
    rep(i,N){
        if(i%2==0) {
            ll v = (A[i] - C[i] + M)%M;
            V[i] = {v, false};
            ne++;
        } else {
            ll v = (C[i] - A[i] + M)%M;
            V[i] = {v, true};
            no++;
        }
    }
    sort(V.begin(),V.end());

    ll sme = 0, smo = 0;
    for(auto [v, flg]: V) {
        if(!flg){
            sme += M-v;
        } else {
            smo += v;
        }
    }

    ll ans = sme + smo;
    ll last = 0;
    bool lasto = false;
    for(auto [v, flg]: V){
        ll gap = v - last;
        sme += ne * gap;
        smo -= no * gap;
        if(lasto) {
            smo += M;
        }
        lasto = false;
        if(!flg){
            sme -= M;
        } else {
            lasto = true;
        }
        chmin(ans, sme + smo);
        last = v;
    }

    cout<<ans<<endl;
    return 0;
}
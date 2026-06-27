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
    ll N,K;
    cin >> N>>K;
    vector A(2*N, vector<ll>{});
    ll sm=0;
    vector<ll> msm(2*N);
    rep(i,2*N) {
        ll a,b; cin>>b>>a;
        b--;
        A[b].push_back(a);
        sm+=a;
        msm[b]++;
    }
    rep(i,2*N) sort(A[i].rbegin(),A[i].rend());
    if(sm<K){
        cout<<-1<<endl;
        return 0;
    }
    ll ok=2*N, ng=0;
    while(ok-ng>1){
        ll c=(ok+ng)/2;

        vector B(2*N, vector<ll>{});
        ll tsz = INF, msz = 0;
        int ind;
        rep(i,2*N){
            for(int j=0; j<A[i].size(); j+=c){
                B[i].push_back(0);
                int sz=B[i].size()-1;
                for(int k=0; k<c && j+k<A[i].size(); k++){
                    B[i][sz]+=A[i][j+k];
                }
            }
            if(msz < (ll)B[i].size()) {
                msz = (ll)B[i].size();
                tsz = (ll)A[i].size();
            } else if(msz == (ll)B[i].size()) {
                chmin(tsz, (ll)A[i].size());
            }
            sort(B[i].rbegin(),B[i].rend());
        }
        ll rsz = 2*N-tsz;
        ll smk = 0;
        rep(i,2*N){
            rep(j, min((ll)B[i].size(), rsz+1)){
                smk += B[i][j];
            }
        }
        if(smk >= K) ok=c;
        else ng=c;
    }
    cout<<ok<<endl;
    return 0;
}
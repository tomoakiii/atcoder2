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
    ll N,M; cin>>N>>M;
    vector<pair<ll, pair<int,int>>> score{};
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector pow(N, vector<ll>(100));
    rep(i,N) {
        pow[i][0]=1;
        pow[i][1]=A[i]%M;
        for(int j=2; j<100; j++){
            pow[i][j] = pow[i][j-1]*pow[i][j-1];
            pow[i][j]%=M;
        }
    }
    auto calc = [&](int i, ll y)->ll{
        int id = 1;
        ll ret = 1;
        while(y){
            if(y%2) {
                ret*=pow[i][id];
                ret%=M;
            }
            y/=2;
            id++;
        }
        return ret;
    };
    rep(i,N) {
        for(int j=i+1;j<N;j++) {
            ll x = calc(i, A[j]) + calc(j, A[i]);
            x%=M;
            score.push_back({x,{i,j}});
        }
    }
    sort(score.rbegin(),score.rend());
    dsu UF(N);
    ll ans = 0;
    for(auto [x, ij]:score){
        auto [i,j]=ij;
        if(UF.same(i,j))continue;
        UF.merge(i,j);
        ans+=x;
//        cerr<<A[i]<<" "<<A[j]<<" "<<x<<endl; 
    }
    cout<<ans<<endl;
    return 0;
}
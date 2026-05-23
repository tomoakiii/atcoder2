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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N,-1);
    dsu UF(N);
    rep(i,M) {
        int u,v; ll c;
        cin>>u>>v>>c;
        u--, v--;
        int l = UF.merge(u,v);
        A[l]=c;
    }
    set<ll>st;
    rep(i,N){
        ll c = A[UF.leader(i)];
        if(c==-1)continue;
        st.insert(c);
    }
    cout<<st.size()<<endl;
    return 0;
}
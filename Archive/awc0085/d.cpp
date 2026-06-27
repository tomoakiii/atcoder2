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
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(),A.end());
    struct node{
        ll l,r,s,e;
    };
    node nd(1,M,0,N);
    vector<node> nodes(Q+1, nd);

    rep(q,Q){
        ll p, d; char c;
        cin>>p>>c>>d;
        node nd=nodes[p];
        if(c=='R'){
            nd.l-=d;
            nd.r-=d;
        }else{
            nd.l+=d;
            nd.r+=d;
        }
        ll x=lower_bound(A.begin(), A.end(), nd.l) - A.begin();
        chmax(nd.s, x);
        ll y=upper_bound(A.begin(), A.end(), nd.r) - A.begin();
        chmin(nd.e, y);
        ll rm = max(0ll, nd.e-nd.s);
        cout<<N-rm<<endl;
        nodes[q+1]=nd;
    }
    return 0;
}
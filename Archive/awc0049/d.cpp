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
typedef pair<ll,pair<int,int>> pli;
int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N),B(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    priority_queue<pli> que;
    que.push({A[0]*B[0],{0,0}});
    set<pair<int,int>> st;
    st.insert({0,0});
    ll cnt=0;
    ll ans=0;
    while(!que.empty()){
        auto [v, ij]=que.top();
        que.pop();
        auto [i,j]=ij;
        // cerr<<i<<" "<<j<<endl;
        ans+=v;
        cnt++;
        if(cnt==K) break;
        auto push=[&](int i, int j)->void{
            if(i>=N) return;
            if(j>=M) return;
            if(st.contains({i,j})) return;
            st.insert({i,j});
            que.push({A[i]*B[j], {i,j}});
        };
        push(i,j+1);
        push(i+1,j);
    };
    cout<<ans<<endl;
    return 0;
}
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
    cin >> N;
    vector<ll> H(N);
    typedef pair<ll,ll> pll;
    priority_queue<pll, vector<pll>, greater<pll>> que;
    multiset<ll> st;
    rep(i,N) {
        ll t;
        cin>>H[i]>>t;
        que.push({t, i});
        st.insert(-H[i]);
    }
    cin >> Q;
    rep(i,Q) {
        ll t; cin>>t;
        que.push({t, N+i});
    }
    vector<ll> ans(Q);
    while(!que.empty()){
        auto [t,i] = que.top();
        que.pop();
        if(i>=N){
            auto it = st.begin();
            ans[i-N] = -1 * (*it);
        } else {
            st.erase(st.find(-H[i]));
        }
    }
    for(auto a:ans) {
        cout<<a<<endl;
    }
    return 0;
}
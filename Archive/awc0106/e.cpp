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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    deque<tuple<ll,ll,int>> RL(Q);
    rep(i,Q){
        ll l,r; cin>>l>>r;
        l--,r--;
        RL[i] = make_tuple(r,l,i);
    }
    sort(RL.begin(), RL.end());
    stack<pair<ll,ll>> st;
    st.push({-INF, -1});
    ll sm=0;
    fenwick_tree<ll> FT(N);
    fenwick_tree<ll> FT2(N);
    fenwick_tree<ll> FT3(N);
    vector<ll> ans(Q);
    rep(i,N) {
        auto [a, j] = st.top();
        while( a > A[i] ) {
            FT2.add(j,-j);
            FT3.add(j,-1);
            FT.add(j, i-j);
            st.pop();
            auto [a2, j2] = st.top();
            swap(a,a2); swap(j,j2);
        }
        sm += i;
        st.push({A[i], i});
        FT2.add(i,i);
        FT3.add(i,1);
        auto [r,l,s] = RL.front();
        while(r == i){
            ans[s] = FT.sum(l, i);
            ll sm = FT2.sum(l, i+1);
            ll sz = FT3.sum(l, i+1);
            ans[s] += (sz * (i+1) - sm);
            RL.pop_front();
            if(RL.empty()) break;
            auto [r2,l2,s2] = RL.front();
            swap(r,r2); swap(l,l2); swap(s,s2);
        }
    }
    for(auto a:ans) cout<<a<<endl;
    return 0;
}
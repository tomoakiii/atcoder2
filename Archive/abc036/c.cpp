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
    ll N;
    cin >> N;
    set<ll> st;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        st.insert(A[i]);
    }
    int ind = 0;
    map<ll,int> mp;
    for(auto s:st) mp[s] = ind++;
    for(auto a:A) cout<<mp[a]<<endl;
    return 0;
}
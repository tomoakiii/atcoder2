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
    ll N,K,T;
    cin >> N >> K >> T; T--;
    ll mx= -INF;
    vector<ll> S(N);
    rep(i,N) cin>>S[i];
    S[T] = 0;
    multiset<ll> st;
    rep(i,K-1) {
        st.insert(S[i]);
    }
    for(int i=K-1; i<N; i++){
        st.insert(S[i]);
        int s = i-(K-1);
        if(s<=T && T<=i){
            auto mn = *st.begin();
            chmax(mx, mn);
        }
        st.erase(st.find(S[s]));
    }
    cout<<mx<<endl;
    return 0;
}
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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    ll ans=0;
    set<ll> st;
    while(Q--){
        int quer; cin>>quer;
        if(quer==1){
            ll x; cin>>x; x--;
            ans ^= A[x];
            A[x]++;
            ans ^= A[x];
            st.insert(x);
        } else {
            auto it = st.begin();
            while(it != st.end()){
                int x = *it;
                ans ^= A[x];
                A[x]--;
                ans ^= A[x];
                if(A[x] == 0) it = st.erase(it);
                else it++;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}
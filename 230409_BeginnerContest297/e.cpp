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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    sort(A.begin(), A.end());
    rep(i,N) cin>>A[i];
    priority_queue<ll, vector<ll>, greater<ll>> que;
    que.push(0);
    set<ll> st, st2;
    while(!que.empty()) {
        ll q = que.top();
        que.pop();
        st.insert(q);
        rep(i,N) {
            ll q2 = q + A[i];
            if (st2.count(q2) != 0) continue;
            que.push(q2);
            st2.insert(q2);
        }
        if (st.size() > K) break; 
    }
    auto it = st.begin();

    rep(i,K) it++;
    cout << *it << endl;
    
    return 0;
}
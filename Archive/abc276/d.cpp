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
    vector<ll> A(N, 0);
    rep(i,N) cin>>A[i];
    vector<ll> c2(N), c3(N);
    ll mn2=INF, mn3=INF;
    set<ll> st;
    rep(i, N) {
        while(A[i] % 2 == 0) {
            A[i] /= 2;
            c2[i]++;
        }
        while(A[i] % 3 == 0) {
            A[i] /= 3;
            c3[i]++;
        }
        chmin(mn2, c2[i]);
        chmin(mn3, c3[i]);
        st.insert(A[i]);
        if (st.size() >= 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll sm = 0;
    rep(i, N) {
        sm += c2[i] - mn2;
        sm += c3[i] - mn3;
    }
    
    cout << sm << endl;
    return 0;
}
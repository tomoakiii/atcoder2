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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    set<int> st;
    for(int a=1; a<=1001; a++) {
        for(int b = 1; 4*a*b+3*a+3*b <= 1000; b++) {
            st.insert(4*a*b+3*a+3*b);
        }
    }
    int cnt = 0;
    rep(i,N) {
        if(!st.contains(A[i])) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
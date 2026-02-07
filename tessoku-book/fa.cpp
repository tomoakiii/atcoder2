//https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bp
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

int main() {
    ll D,X; cin>>D>>X;
    vector<int> A(D);
    A[0] = X;
    rep(i,D-1) {
        ll a; cin>>a;
        A[i+1] = A[i] + a;
    }
    int Q; cin>>Q;
    while(Q--) {
        int s, t; cin>>s>>t; s--,t--;
        if(A[s] == A[t]) cout << "Same" << endl;
        else if(A[s] > A[t]) cout<<s+1 <<endl;
        else cout<<t+1<<endl;
    }

    return 0;
}
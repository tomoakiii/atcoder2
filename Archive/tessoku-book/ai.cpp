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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll N; cin>>N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    rep(i,N-1) {
        vector<ll> B;
        if(i%2 == N%2) {
            rep(k, A.size()-1) {
                B.push_back(max(A[k],A[k+1]));
            }
        } else {
            rep(k, A.size()-1) {
                B.push_back(min(A[k],A[k+1]));
            }
        }
        swap(A,B);
    }
    cout << A[0] << endl;
    return 0;
}
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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N+2); 
    int ans = 0;   
    while(Q--) {
        int a;
        cin >> a;
        if(A[a] == 0) {
            A[a] = 1;
            if(A[a-1] == 0 && A[a+1] == 0) {
                ans++;
            } else if (A[a-1] == 0 && A[a+1] == 1) {

            } else if (A[a-1] == 1 && A[a+1] == 0) {

            } else {
                ans--;
            }
        }  else {
            A[a] = 0;
            if(A[a-1] == 0 && A[a+1] == 0) {
                ans--;
            } else if (A[a-1] == 0 && A[a+1] == 1) {

            } else if (A[a-1] == 1 && A[a+1] == 0) {

            } else {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
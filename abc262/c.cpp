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
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) {
        cin>>A[i];
        A[i]--;
    }
    ll c1=0, c2=0;
    rep(i,N) {
        if(A[i] == i) c1++;
        else if(A[A[i]] == i) c2++;
    }
    ll ans = c1 * (c1-1) / 2;
    ans += (c2)/2;
    cout << ans << endl;
    return 0;
}
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

    vector<pair<ll, int>> A(N);
    rep(i,N) {
        cin>>A[i].first;
        A[i].second = i;
    }
    sort(A.rbegin(), A.rend());
    vector<ll> ans(N);
    ll last = INF;
    int r = 0, k = 1;
    rep(i,N) {
        if(A[i].first < last) {
            r += k;
            k=1;
        } else {
            k++;            
        }
        last = A[i].first;
        ans[A[i].second] = r;
    }
    rep(i,N) {
        cout << ans[i] << endl;
    }
    return 0;
}
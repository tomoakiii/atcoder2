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

/** https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/lis **//

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin>>A[i];
    vector<int> uc(N), dc(N); // Count which order number each index is assigned
    vector<int> up, dn; // Storage table which number is temporally stored, like as dp
    rep(i,N) {
        auto it = lower_bound(up.begin(), up.end(), A[i]);
        if(it == up.end()) {
            up.push_back(A[i]);
            uc[i] = up.size();
        } else {
            *it = A[i];
            uc[i] = it - up.begin() + 1;
        }
    }


    reverse(A.begin(), A.end());
    rep(i,N) {
        auto it = lower_bound(dn.begin(), dn.end(), A[i]);
        if(it == dn.end()) {
            dn.push_back(A[i]);
            dc[i] = dn.size();
        } else {
            *it = A[i];
            dc[i] = it - dn.begin() + 1;
        }        
    }


    reverse(dc.begin(), dc.end());
    int ans = 0;
    rep(i,N) {
        chmax(ans, uc[i]+dc[i]-1);
    }
    cout << ans << endl;
    return 0;
}
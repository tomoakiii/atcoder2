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
    string S;
    cin >> S;
    string T1, T2;
    rep(i, S.size()) {
        if(i%2==0) {
            T1.push_back('A');
            T2.push_back('B');
        } else {
            T2.push_back('A');
            T1.push_back('B');
        }
    }
    ll ans = INF;
    rep(k,2) {
        int l1 = 0, l2 = 0;
        ll ans2 = 0;
        rep(i, N) {
            while(T1[l1] != 'A') l1++;
            while(S[l2] != 'A') l2++;
            ans2 += abs(l1-l2);
            l1++, l2++;
        }
        chmin(ans, ans2);
        swap(T1,T2);
    }
    cout << ans << endl;
    return 0;
}
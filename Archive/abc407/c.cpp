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
    string S;
    cin >> S;
    // reverse(S.begin(), S.end());
    vector<int> num(S.size());
    rep(i,S.size()) {
        num[i] = S[i]- '0';
    }
    const int N = S.size();
    ll cnt = 1; // t=0;
    int cntB = 0;    
    for(int i=1; i<N; i++) {
        cnt++;
        cntB += (num[i-1] + 10 - num[i]) % 10;
    }
    int s = (cntB) % 10;
    cntB += (num[0] + 10 - s)%10;
    cout << cnt + cntB << endl;
    return 0;
}
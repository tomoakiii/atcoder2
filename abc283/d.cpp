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
    vector<map<int, >> flr('Z'-'A'+1, vector<int>{});
    int f = 1;
    rep(i, S.size()) {
        if (S[i] == '(') f++;
        else if (S[i] == ')') f--;
        else {
            int c = S[i] - 'a';
            if (flr[c].size() < f) {
                flr[c].push_back(1);
            } else {
                if (flr[c][f-1] =
            }
            flr[c].push_back
        }
    }
    
    cout << sm << endl;
    return 0;
}
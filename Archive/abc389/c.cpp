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
    ll Q;
    cin >> Q;
    vector<ll> L{};
    L.push_back(0);
    int top = 0;

    while(Q--){
        int k;
        cin >> k;
        if(k == 1) {
            int len;
            cin >> len;
            L.push_back(len);
            L[L.size() - 1] += L[L.size() - 2];
        } else if (k == 2) {
            top++;
        } else {
            int p;
            cin >> p;
            cout << L[p+top-1] - L[top] << endl;
        }
    }
    return 0;
}
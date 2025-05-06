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
    int Q;
    cin >> S >> Q;
    map<char, vector<char>> mp;
    vector<char> v(2);
    v[0] = 'B'; v[1] = 'C'; mp['A'] = v;
    v[0] = 'C'; v[1] = 'A'; mp['B'] = v;
    v[0] = 'A'; v[1] = 'B'; mp['C'] = v;
    
    
    while(Q--) {
        ll t, k;
        cin >> t >> k;
        k--;        
        ll q = popcount(t);
        q += S[k]-'a';
        int v = S[k]
        cout << v << endl;
    }
    return 0;
}
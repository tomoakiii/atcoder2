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
    string stN;
    vector<char> sN{};
    int K;
    cin >> stN >> K;
    if(stN == "0") {
        cout << 0 << endl;
        return 0;
    }
    for(auto c:stN) sN.push_back(c);
    reverse(sN.begin(), sN.end());
    while(K--) {
        ll N = 0;
        ll p = 1;
        rep(i, sN.size()) {
            N += (sN[i] - '0') * p;
            p*=8;
        }
        vector<char> out{};
        while(N > 0) {
            char c;
            c = ((N%9) + '0');
            if(c == '8') c = '5';
            out.push_back(c);
            N /= 9;
        }
        swap(out, sN);
    }
    reverse(sN.begin(), sN.end());
    for(auto c:sN) cout<<c;
    cout << endl;
    return 0;
}
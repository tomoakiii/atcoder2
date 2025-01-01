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
    vector<int> si{};
    rep(i,N) {
        if(S[i] == '/') si.emplace_back(i);
    }
    int mx = 0;
    for(auto i: si) {
        chmax(mx, 1);
        int tmx = 1;
        int n1=i-1, n2 = i+1;
        while(n1 >= 0 &&  n2 < N && S[n1] == '1' && S[n2] == '2') {
            n1--, n2++;
            tmx += 2;
            chmax(mx, tmx);
        }
    }
    cout<<mx<<endl;
    return 0;
}
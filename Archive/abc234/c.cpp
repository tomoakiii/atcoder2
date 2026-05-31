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
    ll K;
    cin >> K;
    vector<int> out{};
    while(K){
        out.push_back(K%2);
        K/=2;
    }
    reverse(out.begin(), out.end());
    for(auto c: out) {
        if(c) printf("2");
        else printf("0");
    }
    printf("\n");    
    return 0;
}
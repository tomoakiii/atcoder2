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



deque<pair<char, int>> encode_str(string str) {
    deque<pair<char, int>> ret;
    int n = (int)str.size();
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

string decode_str(const deque<pair<char, int>>& code) {
    string ret;
    for (auto p : code) {
        for (int i = 0; i < p.second; i++) {
            ret.push_back(p.first);
        }
    }
    return ret;
}


int main(){
    string S; int K; cin>>S>>K;
    auto ret = encode_str(S);
    for(auto [c,i]:ret){
        if(i<K)rep(j,i)cout<<c;
        else cout<<c<<i;
    }
    cout<<endl;
    return 0;
}
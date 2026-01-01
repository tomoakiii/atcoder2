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
    string S; cin>>S;
    int T; cin>>T;
    map<char, pair<int,int>> mp;
    mp['U'] = {1,0};
    mp['D'] = {-1,0};
    mp['R'] = {0,1};
    mp['L'] = {0,-1};
    pair<int,int> cd = {0,0};
    int qc = 0;
    for(auto c:S) {
        if(c == '?') qc++;
        cd.first += mp[c].first;
        cd.second += mp[c].second;
    }
    ll dist = abs(cd.first) + abs(cd.second);
    if(T == 1) {
        cout << dist + qc << endl;
        return 0;
    }
    if(qc <= dist) {
        dist -= qc;
        cout << dist << endl;
        return 0;
    }
    qc -= dist;
    cout << (qc % 2) << endl;
    return 0;
}
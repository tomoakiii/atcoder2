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
    string S, T;
    cin >> S >> T;
    vector<pair<char,int>> Sa{}, Ta{};
    char last = 0;
    for(char c: S){
        if(c == last) {
            Sa.back().second++;
        } else {
            Sa.push_back({c, 1});
        }
        last = c;
    }
    for(char c: T){
        if(c == last) {
            Ta.back().second++;
        } else {
            Ta.push_back({c, 1});
        }
        last = c;
    }
    if (Sa.size() != Ta.size()) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, Sa.size()) {
        if(Sa[i].second > Ta[i].second || Sa[i].first != Ta[i].first) {
            cout << "No" << endl;
            return 0;
        }
        if(Sa[i].second == 1 && Ta[i].second > 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
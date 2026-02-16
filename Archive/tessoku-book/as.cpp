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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll N; char C;
    cin>>N>>C;
    string S; cin>>S;
    map<pair<char,char>, char> mp;
    mp[{'W','W'}] = 'W';
    mp[{'B','B'}] = 'R';
    mp[{'R','R'}] = 'B';
    mp[{'W','B'}] = 'B';
    mp[{'W','R'}] = 'R';
    mp[{'B','R'}] = 'W';

    while(S.size() > 1) {
        char c1 = S.back();
        S.pop_back();
        char c2 = S.back();
        S.pop_back();
        if(mp.contains({c1,c2})) S.push_back(mp[{c1,c2}]);
        else S.push_back(mp[{c2,c1}]);
    }
    if(C == S[0]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
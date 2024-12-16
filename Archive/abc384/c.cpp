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
    ll score[5];
    string let = "ABCDE";
    rep(i,5) cin>>score[i];
    map<ll, vector<string>> mp;

    for(int k=1; k<(1<<5); k++) {
        ll sc = 0;
        string s = "";
        rep(i, 5) {
            if(((k >> i) & 1)>0) {
                sc += score[i];
                s = s + let[i];
            }            
        }
        mp[sc].push_back(s);
    }
    
    auto it = mp.end();
    it--;

    while(true){
        sort(it->second.begin(), it->second.end());
        for (auto b: it->second) {
            cout<<b<<endl;        
        }
        if(it == mp.begin()) break;
        it--;
    }

    return 0;
}
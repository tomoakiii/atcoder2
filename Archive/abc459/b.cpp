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
    map<char,int> mp;
    mp['a']=2;
    mp['b']=2;
    mp['c']=2;
    mp['d']=3;
    mp['e']=3;
    mp['f']=3;
    mp['g']=4;
    mp['h']=4;
    mp['i']=4;
    mp['j']=5;
    mp['k']=5;
    mp['l']=5;
    mp['m']=6;
    mp['n']=6;
    mp['o']=6;
    mp['p']=7;
    mp['q']=7;
    mp['r']=7;
    mp['s']=7;
    mp['t']=8;
    mp['u']=8;
    mp['v']=8;
    mp['w']=9;
    mp['x']=9;
    mp['y']=9;
    mp['z']=9;




    rep(i,N) {
        string s;cin>>s;
        cout<<mp[s[0]];
    }
    cout<<endl;
    return 0;
}
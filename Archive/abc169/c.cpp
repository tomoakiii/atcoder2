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
    ll A;
    string T;  
    cin>>A>>T;
    
    string T2;
    T2.push_back(T[T.size()-2]);
    T2.push_back(T[T.size()-1]);

    T.pop_back(); T.pop_back(); T.pop_back();

    ll Bs = stoi(T2);    
    ll Bl = stoi(T);    
    
    ll ans = A*Bl;
    ll C = Bs*A;
    C/=100;
    cout << ans + C << endl;
    return 0;
}
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
    map<char,int> mp1;
    map<int,string> mp2;
    mp1['S']=0,mp1['C']=1,mp1['R']=2;
    mp2[0]="Sunny",mp2[1]="Cloudy",mp2[2]="Rainy";
    string S;
    cin >> S;
    cout<<mp2[(mp1[S[0]]+1)%3]<<endl;
    return 0;
}
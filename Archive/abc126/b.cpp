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
    int Y = (S[0]-'0')*10 + (S[1]-'0');
    int M = (S[2]-'0')*10 + (S[3]-'0');
    if(Y==0 || Y>12) {
        if(1<=M && M<=12) cout<<"YYMM"<<endl;
        else cout<<"NA"<<endl;
    } else if (M==0 || M>12) {
        if(1<=Y && Y<=12) cout<<"MMYY"<<endl;
        else cout<<"NA"<<endl;
    } else {
        cout<<"AMBIGUOUS"<<endl;
    }
    return 0;
}
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
    string S;
    cin>>S;
    int N=S.size();
    if(S[0]==S.back()){
        if(N%2==1) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    } else {
        if(N%2==0) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
    return 0;
}

/*
ababa 0
abacba 
a-a-a -1
a-a -3

*/
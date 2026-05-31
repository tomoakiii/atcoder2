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
    string S,T; cin>>S>>T;
    set<char> st;
    for(auto c: T) st.insert(c);
    for(int i=1; i<S.size(); i++) {
        if(S[i] >= 'A' && S[i] <= 'Z') {
            if(!st.contains(S[i-1])){
                 cout<<"No"<<endl;
                 return 0;
            } 
        }
    }
     cout<<"Yes"<<endl;
    return 0;
} 
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S; cin>>S;
    vector<char> v;
    for(auto c:S){
        if(v.empty())v.push_back(c);
        else{
            if(v.back() == c) v.pop_back();
            else v.push_back(c);
        }
    }
    cout<<v.size()<<endl;
    return 0;
}
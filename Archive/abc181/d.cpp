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
typedef pair<pair<int,int>,pair<int,int>> pii;
int main(){
    string S;
    cin>>S;
    if(S.size()<=3){
      sort(S.begin(),S.end());
       do{
             ll d=stoi(S);
             if(d%8==0){
                 cout<<"Yes"<<endl;
                 return 0;
             }
}while(next_permutation(S.begin(),S.end()));
         cout<<"No"<<endl;
         return 0;
    }
    vector<int> cnt(10);
    for(auto c:S) {
         cnt[c-'0']++;
    }
    for(int d=112;d<999;d+=8){
          string T=to_string(d);
          vector<int> cnt2(10);
          for(auto c:T) {
               cnt2[c-'0']++;
          }
          bool b=true;
          rep(i,10) if(cnt[i]<cnt2[i]) b=false;
           if(b) {
               cout<<"Yes"<<endl;
                 return 0;
           }
    }
    
    cout<<"No"<<endl;
    return 0;
}
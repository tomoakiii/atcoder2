#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string X; cin>>X;
    int N; cin>>N;
    vector<string> name(N);
    map<string,int> vs;
    rep(i,N)cin>>name[i];
    
    vector<int> mp(30);
    for(int c = 0; c<='z'-'a'; c++){
        int c2 = X[c] - 'a';
        mp[c2] = c;
    }
    
    rep(i,N) {        
        string s = name[i];
        rep(j, name[i].size()) {
            s[j] = (char)('a' + mp[name[i][j]-'a']);
        }
        vs[s] = i;
    }    
    for(auto [s,i]: vs) cout<<name[i]<<endl;
    return 0;
}
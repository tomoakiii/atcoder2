#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define X swap(S[i],S[i+1])
#define CO(p) cout<<(p)<<endl
int main(){
    string S, T; cin>>S>>T;
    if(S==T) {CO("Yes");return 0;}
    rep(i,S.size()-1){X;if(S==T){CO("Yes");return 0;}X;}
    CO("No");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string S; cin>>S;
    rep(i,S.size()-1)cout<<S[i+1];cout<<S[0]<<endl;
    return 0;
}
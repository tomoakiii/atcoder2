#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    bool f=false;
    for(char c: S){
        if (c=='*') {
            if (!f) cout<<"out"<<endl;
            else cout << "in" << endl;
        }
        if(c=='|') f=!f;
    }
    return 0;
}
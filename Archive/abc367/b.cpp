#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    string X;
    cin >> X;
    int len = X.size();
    int end = len;
    for(int c = len-1 ; c >= len-3 ; c--) {
        if (X[c]=='0') end = c;
        else break;
    }
    if(end == len-3) end--;
    rep(i, end) {
        cout<<X[i];
    }
    cout << endl;
    return 0;
}
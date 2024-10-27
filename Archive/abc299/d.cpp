#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    // cout << "?" << endl;
    ll N;
    cin >> N;
    int l = 1, r = N;
    int c, v;
    while(r-l > 1) {
        int c = (r+l)/2;
        cout << "? " << c << endl;        
        cin >> v;
        if (v==1) r = c;
        else l = c;
    }
    cout << "! " << l << endl;
    return 0;
}
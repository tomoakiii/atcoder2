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

    ll h, h1;
    cin >> h1;
    for(int i=1; i<N; i++) {
        cin >> h;
        if(h > h1) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;    
    return 0;
}
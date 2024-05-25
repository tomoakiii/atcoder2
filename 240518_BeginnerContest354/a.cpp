#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll H;
    cin >> H;
    ll h = 1;
    ll total = 0;
    int i=0;
    while(total <= H) {
        i++;        
        total += h;
        if (total > H){
            break;
        }
        h*=2;
    }    
    cout << i << endl;
    return 0;
}
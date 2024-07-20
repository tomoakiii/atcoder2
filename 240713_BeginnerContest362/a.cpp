#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll R, G, B;
    string C;
    cin >> R >> G >> B;
    cin >> C;
    
    if(C=="Red") R=500;
    if(C=="Green") G=500;
    if(C=="Blue") B=500;
    
    ll mn = min(min(R, G), B);
   
    cout << mn << endl;
    return 0;
}
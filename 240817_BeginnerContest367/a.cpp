#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    if(C<B) C+=24;
    if(A<B) A+=24;
    if(B<A && A<C) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}
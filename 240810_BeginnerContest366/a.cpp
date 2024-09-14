#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, T, A;
    cin >> N >> T >> A;
    if(T<A) swap(T,A);
    ll last = N-T-A;
    if (A+last < T) cout<< "Yes"<<endl;
    else cout << "No" << endl;
    return 0;
}
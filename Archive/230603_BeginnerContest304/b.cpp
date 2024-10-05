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
    ll a=1, b=1000;
    for(int i=3; i<=9; i++){
        if(N/b == 0){
            N=N/a;
            N=N*a;
            cout<<N<<endl;
            return 0;
        }
        a*=10;
        b*=10;
    }

    return 0;
}
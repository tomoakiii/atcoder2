#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int A, B;
    cin >> A >> B;
    int sa=0, sb=0;
    rep(i, 3){
        sa+=A%10;
        sb+=B%10;
        A/=10;
        B/=10;
    }
    cout << max(sa,sb) << endl;
    return 0;
}


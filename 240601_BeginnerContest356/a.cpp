#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N, L, R;
    cin >> N >> L >> R;
    for(int i=1; i<=L-1; i++) cout << i << " ";
    for(int i=R; i>=L; i--) cout << i << " ";
    for(int i=R+1; i<=N; i++) cout << i << " ";    
    cout << endl;
    return 0;
}
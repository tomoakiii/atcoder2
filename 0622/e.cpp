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
    vector<ll> H(N+1, INF);
    vector<ll> pH(N+1, 0);

    for(int i=1; i<=N; i++) {
        cin >> H[i];
    }
    int lasti = 0;
    ll lash = INF;
    for(int i = 1; i<=N; i++) {
        if (H[i] < lash) {
            pH[i] = i-1;
        } else {
            int j = i-1;
            while(j>=0){
                if (H[j] < H[i]) {
                    j--;
                } else {
                    pH[i] = j;
                    break;
                }
            }
        }
        lash = H[i];
    }
    
    vector<ll> sm(N+1, 0);
    for(int i = 0; i<N; i++) {
        sm[i+1] = sm[i] + H[i+1];
    }

    for(int i = 0; i<N; i++) {
        cout << sm[i+1] - sm[pH[i+1]] << " ";
    }
    return 0;
}
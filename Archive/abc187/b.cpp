#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N;
    cin >> N;
    vector<int> x(N),y(N);
    rep(i,N) cin>>x[i]>>y[i];
    int c=0;
    rep(i,N-1) for(int j=i+1; j<N; j++){
        if (abs(x[i]-x[j]) >= abs(y[i]-y[j])){
            // cout << (x[i]-x[j]) << " " << (y[i]-y[j]) << endl;
            c++;
        }
    }
    cout << c << endl;
    return 0;
}


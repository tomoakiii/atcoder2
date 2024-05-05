#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, D;
    cin >> N >> D;
    vector<string> sh(N);
    ll mx = 0, cnt = 0;
    for(int i=0; i<N;i++) {        
        cin >> sh[i];
    }
    for(int i=0; i<D;i++) {        
        bool any = true;
        for (int j= 0; j < N; j++){
            if (sh[j][i] == 'x'){
                any = false;
            }
        }
        if(any) {
            cnt++;
            mx = max(mx, cnt);
        } else {
            cnt=0;
        }
    }
    cout << mx << endl;
    return 0;
}
#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int SG[N];
void slove(){
    SG[1] = 0;
    for(int i=2;i<=100000;i++){
        int x = i;
        int cnt = 0;
        for(int j=2;j<=x/j;j++){
            while(x % j == 0){
                cnt++;
                x /= j;
            }
        }
        if(x > 1) cnt++;
        SG[i] = cnt;
    }
    int n; cin >> n;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        ans = ans ^ SG[x];
    }
    if(ans == 0) cout << "Bruno" << endl;
    else cout << "Anna" << endl;
}
int main(){
    ios;
    int t; t = 1;
    while(t--){
        slove();
    }
    return 0;
}
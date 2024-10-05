#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
int main(){
    int N, M, P;
    cin >> N >> M >> P;
    int cnt = 0;
    for (int i=M; i<=N; i++){
        if((i-M)%P == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
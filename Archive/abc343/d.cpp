#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N, T;
    cin >> N >> T;
    map<ll, int> mp;
    vector<ll> score(N, 0);
    int a;
    ll b;
    mp[0] = N;
    int cnt=1;
    for (int i=0; i < T; i++) {
        cin >> a >> b;
        a--;
        if (mp[score[a]] == 1) cnt--;
        mp[score[a]]--;
        score[a] += b;
        if (mp.find(score[a]) == mp.end()) {
            cnt++;
        } else if (mp[score[a]] == 0){
            cnt++;
        }
        mp[score[a]]++;
        cout << cnt << endl;
    }
    return 0;
}


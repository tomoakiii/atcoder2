#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<pair<int, bool>>> ptime(N+1);
    vector<int> pickdrop(N+1, 0);
    vector<int> pind(N+1, -1);
    
    
    for (int i=1; i<=N; ++i){
        int t, xtmp;
        cin >> t >> xtmp;
        if(t==1){
            pickdrop[i] = 0;
            pind[xtmp]++;
            if (pind[xtmp] > (int)ptime[xtmp].size()-1){
                ptime[xtmp].push_back({i, false});
            } else {                
                ptime[xtmp][pind[xtmp]] = {i, false};
            }
        } else {
            pickdrop[i] = -1;
            if (pind[xtmp] < 0){
                cout << -1 << endl;
                return 0;
            }
            ptime[xtmp][pind[xtmp]].second = true;
            pickdrop[ptime[xtmp][pind[xtmp]].first] = 1;
            pind[xtmp]--;
        }
    }

    int ktmp = 0, kmin = 0;
    for (int i=1; i<=N; ++i){
        ktmp += pickdrop[i];
        kmin = max(kmin, ktmp);
    }
    cout << kmin << endl;
    for (int i=1; i<=N; ++i){
        if (pickdrop[i] > -1){
            cout << pickdrop[i] << " ";
        }
    }


    return 0;
}
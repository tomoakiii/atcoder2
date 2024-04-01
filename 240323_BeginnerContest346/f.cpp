#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
int N;
string S, T;
vector<vector<int>> AtoZ;

int key = 0;
int cnt = 0;
bool check(string T2){
    for (int i=0; i<T2.size(); i++){
        auto iter_lower = lower_bound(AtoZ[T2[i]].begin(), AtoZ[T2[i]].end(), key);
        if (iter_lower == AtoZ[T2[i]].end()) {
            key = 0;
            cnt++; 
            continue;
        }
        key = distance(AtoZ[T2[i]].begin(), iter_lower) + 1;
    }

}



int main(){
    AtoZ.resize('z'-'a'+1);
    cin >> N >> S >> T;
    for (int i=0; i<S.size(); i++){
        AtoZ[S[i]-'a'].push_back(i);
    }
    for (int i=0; i<T2.size(); i++){
        if (AtoZ[T2[i]].size() == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    

    return 0;
}
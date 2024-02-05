#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<long long> R, Rsum;

// index が条件を満たすかどうか
template<typename T>
bool isOK(int index, T key) {
    if (Rsum[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
template<typename T>
int binary_search(T key) {
    int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int right = (int)R.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (isOK(mid, key)) right = mid;
        else left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}


int main(){
    cin >> N >> Q;
    R.resize(N), Rsum.resize(N, 0);
    for (auto &r : R) cin >>r;
    sort(R.begin(), R.end());
    Rsum[0]=R[0];
    for (int i=1; i<N; i++){
        Rsum[i] = Rsum[i-1]+R[i];
    }
    while(Q>0){
        Q--;
        long long q;
        cin >> q;
        long long a = binary_search(q);
        if (Rsum[a]==q) a++; 
        cout << a << endl;
    }

    return 0;
}
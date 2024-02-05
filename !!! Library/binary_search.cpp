#include <bits/stdc++.h>
using namespace std;

vector<long long> R, Rsum;

// index が条件を満たすかどうか
template<typename T>
bool isOK(int index, T key) {
    if (R[index] >= key) return true;
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
    R.resize(10), Rsum.resize(10, 0);
    R = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    sort(R.begin(), R.end());

    cout << binary_search(1) << endl;
    cout << binary_search(2) << endl;
    cout << binary_search(3) << endl;
    cout << binary_search(4) << endl;
    cout << binary_search(19) << endl;
    return 0;
}
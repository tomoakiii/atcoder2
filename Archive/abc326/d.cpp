#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

void PrintStringPermutations(string &str) {
    int cnt = 0;

}


int main()
{
    int N;
    cin >> N;
    string sv, sh;
    cin >> sv >> sh;
    string oneline;
    if (N==3){
        oneline = "ABC";
    } else if (N==4){
        oneline = ".ABC";
    }  else{
        oneline = "..ABC";
    }

    vector<vector<string>> linepermutation(3);
    do {
        for (int n = 0; n < 3; n++){
            if (oneline[n] != '.'){
                linepermutation[oneline[n]-'A'].push_back(oneline);
                break;
            }
        }
    } while (std::next_permutation(oneline.begin(), oneline.end()));
    bool success;
    long totaltrial = 1;
    long linenum = linepermutation[0].size();
    for (int n = 0; n < N; n++) totaltrial *= linenum;
    vector<string> out(N);
    for (long i = 0; i < totaltrial; i++){
        long tmp=i;
        for (int n = N - 1; n >= 0; n--){
            int initial = sv[n] - 'A';
            out[n] = linepermutation[initial][tmp%linenum];
            tmp /= linenum;
        }
        success = true;

        for (int j = 0; j < N; j++){ // left to right
            bool checkABC[3] = {false, false, false};
            bool firstcheck = true;
            for (int k = 0; k < N; k++){ // top tp bottom
                if  (out[k][j] == '.'){
                    continue;
                }
                if (firstcheck && sh[j] != out[k][j]){
                    success = false;
                    break;
                }
                firstcheck = false;
                if (checkABC[out[k][j] - 'A']){
                    success = false;
                    break;
                } else {
                    checkABC[out[k][j] - 'A'] = true;
                }
            }
            if (checkABC[0] == false || checkABC[1] == false || checkABC[2] == false){
                success = false;
            }
            if (!success){
                break;
            }
        }
        if (success){
            break;
        }
    }
    if (success){
        cout << "Yes" << endl;
        for (int i = 0; i < N ; i++){
            cout << out[i] << endl;
        }
    } else {
        cout << "No" << endl;
    }
    return 0;
}
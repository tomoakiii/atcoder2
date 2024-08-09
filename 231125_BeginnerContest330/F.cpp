#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    long long K;
    cin >> N >> K;
    map<long long, long long> mpX;
    map<long long, long long> mpY;
    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        mpX[x]++;
        mpY[y]++;
    }

    struct numcnt{
        long long num;
        long long cnt=0;
    };
    vector<numcnt> vX, vY;
    for (auto mX: mpX){
        vX.push_back({mX.first, mX.second});
    }
    for (auto mX: mpY){
        vY.push_back({mX.first, mX.second});
    }

    int indYl=0, indYr=vY.size()-1, indXl=0, indXr=vX.size()-1;    
    long long cstK = K;
    long long yNext, xNext;
    long long yLen;
    long long xLen;
    while (cstK > 0){
        yLen = vY[indYr].num - vY[indYl].num;
        xLen = vX[indXr].num - vX[indXl].num;
        if (yLen==0 && xLen==0){
            break;
        }

        bool ySmaller=false, xSmaller=false;
        numcnt yg, xg;
        if (vY[indYr].cnt > vY[indYl].cnt) {
            // move left
            ySmaller = true;
            yNext = vY[indYl+1].num - vY[indYl].num;
            yg = vY[indYl];
        } else { // move right
            yNext = vY[indYr].num - vY[indYr-1].num;
            yg = vY[indYr];
        }

        if (vX[indXr].cnt > vX[indXl].cnt) {
            // move left
            xSmaller = true;
            xNext = vX[indXl+1].num - vX[indXl].num;
            xg = vY[indXl];
        } else { // move right
            xNext = vX[indXr].num - vX[indXr-1].num;
            xg = vY[indXr];
        }

        if (yLen > xLen){
            // shorten Y
            long long dist = min({yNext, yLen-xLen, cstK/yg.cnt, yLen});
            if (dist == yNext){
                if (ySmaller){
                    vY[indYl+1].cnt += vY[indYl].cnt;
                    indYl++;
                }
                else {
                    vY[indYr-1].cnt += vY[indYr].cnt;
                    indYr--;
                }
            } else {
                if (ySmaller){
                    vY[indYl].num += dist;
                } else {
                    vY[indYr].num -= dist;
                }
            }
            cstK -= yg.cnt * dist;
        } else if (yLen < xLen) {
            // shorten X
            long long dist = min({xNext, yLen-xLen, cstK/xg.cnt, xLen});
            if (dist == xNext){
                if (xSmaller){
                    vX[indXl+1].cnt += vX[indXl].cnt;
                    indXl++;
                }
                else {
                    vX[indXr-1].cnt += vX[indXr].cnt;
                    indXr--;
                }
            } else {
                if (xSmaller){
                    vX[indXl].num += dist;
                } else {
                    vX[indXr].num -= dist;
                }
            }
            cstK -= xg.cnt * dist;
        } else { // shorten both X and Y
            long long dist = min({xNext, yNext, cstK/(yg.cnt+xg.cnt), xLen});
            if (dist == xNext){
                if (xSmaller){
                    vX[indXl+1].cnt += vX[indXl].cnt;
                    indXl++;
                }
                else {
                    vX[indXr-1].cnt += vX[indXr].cnt;
                    indXr--;
                }
            } else {
                if (xSmaller){
                    vX[indXl].num += dist;
                } else {
                    vX[indXr].num -= dist;
                }
            }
            if (dist == yNext){
                if (ySmaller){
                    vY[indYl+1].cnt += vY[indYl].cnt;
                    indYl++;
                }
                else {
                    vY[indYr-1].cnt += vY[indYr].cnt;
                    indYr--;
                }
            } else {
                if (ySmaller){
                    vY[indYl].num += dist;
                } else {
                    vY[indYr].num -= dist;
                }
            }
            cstK -= xg.cnt * dist;
            cstK -= yg.cnt * dist;
        }
        long long yLen2 = vY[indYr].num - vY[indYl].num;
        long long xLen2 = vX[indXr].num - vX[indXl].num;
        if (xLen2 == xLen && yLen2 == yLen){
            break;
        } else {
            xLen = xLen2;
            yLen = yLen2;
        }

    }

    cout << max(xLen, yLen) << endl;
    return 0;
}
#include<cstdio>
#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; (i) < (n); (i)++)
using namespace std;

//比較関数（を返す関数）
template<class T>
auto comp_idx(T* ptr){
  return [ptr](int l_idx, int r_idx){
    return ptr[l_idx] < ptr[r_idx];
  };
}

int main(){
  char str[] = "bcad";
  int l = strlen(str);

  //インデックスの配列を準備
  int idx[l];
  REP(i,l){
    idx[i] = i;
  }

  //ソート前
  cout << "before:" << endl;
  REP(i,l){
    cout << idx[i];
  }
  cout << endl;

  REP(i,l){
    cout << str[idx[i]];
  }
  cout << endl << endl;

  //インデックスソート
  sort(idx, idx+l, comp_idx(str));

  //ソート後
  cout << "after:" << endl;
  REP(i,l){
    cout << idx[i];
  }
  cout << endl;

  REP(i,l){
    cout << str[idx[i]];
  }
  cout << endl << endl;

  //元の配列
  cout << "original:" << endl;
  cout << str << endl;

  return 0;
}

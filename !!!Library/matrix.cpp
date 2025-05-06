#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


class Ma{
  private:
    vector<double> get_column(vector<vector<double>> x, int n);
    double dot(vector<double> x, vector<double> y);
    vector<vector<double>> vec;
    vector<double> div(vector<double> x, double y);
    double pow(double x, int n);
  public:
    Ma(vector<vector<double>> x){vec=x;};//変換コンストラクタ
    void show();
    static void show(Ma x);
    Ma operator+(Ma x);
    friend Ma operator+(Ma X, double y);
    friend Ma operator+(double y, Ma X);
    Ma operator*(Ma x);
    friend Ma operator*(Ma X, double y);
    friend Ma operator*(double y, Ma X);
    Ma operator-(Ma x);
    friend Ma operator-(Ma X, double y);
    friend Ma operator-(double y, Ma X);
    Ma operator/(double x);
    Ma operator-();
    Ma T();
    operator vector<vector<double>>(){return vec;};//変換関数
    double operator()(int x, int y){return vec[x][y];};
    int size();
    vector<int> shape();
    Ma inv(); //逆行列
    double det(); //行列式
};


double Ma::pow(double x, int n){
  int r = 1;
  for(int i=0;i<n;i++){
    r *= x;
  }
  return r;
}
int Ma::size(){
  return vec.size() * vec[0].size();
}
vector<int> Ma::shape(){
  vector<int> a = {(int)vec.size(),(int)vec[0].size()};
  return a;
}
Ma Ma::operator-(Ma x){
  vector<vector<double>> A=vec;
  vector<vector<double>> B=x.vec;
  vector<vector<double>> C;
  C = A;

  try{
    if(A.size()!=B.size() || A[0].size()!=B[0].size())
      throw "Invalid matrix size! in Ma Ma::operator-(Ma x)";
  }catch(const char* err){
    cout << "Error:" << err << "\n";
    exit(1);
  }

  for(int i=0; i < A.size(); i++){
    for(int j=0; j < A[i].size(); j++){
      C[i][j] = A[i][j] - B[i][j];
    }
  }
  Ma y(C);
  return y;
}
Ma Ma::operator+(Ma x){
  vector<vector<double>> A=vec;
  vector<vector<double>> B=x.vec;
  vector<vector<double>> C;
  C = A;
  
  try{
    if(A.size()!=B.size() || A[0].size()!=B[0].size())
      throw "Invalid matrix size! in Ma Ma::operator+(Ma x)";
  }catch(const char* err){
    cout << "Error:" << err << "\n";
    exit(1);
  }

  for(int i=0; i < A.size(); i++){
    for(int j=0; j < A[i].size(); j++){
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  Ma y(C);
  return y;
}
Ma Ma::operator*(Ma x){
  vector<vector<double>> A=vec;
  vector<vector<double>> B=x.vec;
  vector<vector<double>> C(A.size(), vector<double>(B[0].size(),0));
  try{
    if(A[0].size()!=B.size()){
      cout << "The number of columns in first operand:" << A[0].size() << "\n";
      cout << "The number of rows in second operand:" << B.size() << "\n";
      throw "Invalid matrix size! in Ma Ma::operator*(Ma x)";
    }
  }catch(const char* err){
    cout << "Error:" << err << "\n";
    exit(1);
  }

  for(int i=0; i < A.size(); i++){
    for(int s=0;s<B[0].size();s++){
      C[i][s] = dot(A[i],get_column(B,s));
    }
  }
  Ma y(C);
  return y;
}
Ma Ma::operator/(double x){
  vector<vector<double>> A=vec;
  for(int i=0;i < A.size();i++){
    for(int j=0;j<A[0].size();j++){
      A[i][j] = vec[i][j] / x;
    }
  }
  return A;
}


vector<double> Ma::get_column(vector<vector<double>> x,int n){
  vector<double> y(x.size());
  for(int i=0;i<x.size();i++){
    y[i] = x[i][n];
  }
  return y;
}
double Ma::dot(vector<double> x, vector<double> y){
  double z = 0;
  for(int i=0;i<x.size();i++){
    z += x[i] * y[i];
  }
  return z;
}
void Ma::show(){
  vector<vector<double>> A=this->vec;
  cout << "\n";
  for(int i=0; i < A.size(); i++){
    for(int j=0; j < A[i].size(); j++){
      cout << A[i][j] << " ";
    }
    cout << "\n";
  }
}

void Ma::show(Ma x){
  x.show();
}

Ma Ma::T(){
  vector<vector<double>> A=this->vec;
  vector<vector<double>> C(A[0].size(), vector<double>(A.size()));
  for(int i=0;i<A.size();i++){
    for(int j=0;j<A[0].size();j++){
      C[j][i] = A[i][j];
    }
  }
  Ma y(C);
  return y;
}
vector<double> Ma::div(vector<double> x, double y){
  for(int i=0;i<x.size();i++){
    x[i] = x[i] / y;
  }
  return x;
}
Ma Ma::inv(){
  vector<vector<double>> A(vec.size(), vector<double>(vec[0].size()*2,0));
  try{
    if(vec.size()!=vec[0].size())
      throw "Invalid matrix size. inv() can only be called by square matrix!";
  }catch(const char* err){
    cout << "Error:" << err << "\n";
    exit(1);
  }
  int n = vec.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      A[i][j] = vec[i][j];
      A[i][j+n] = (i==j)? 1:0;
    }
  }

  for(int i=0;i<n;i++){
    A[i] = div(A[i],A[i][i]);
    for(int j=0;j<n;j++){
      if(i==j)
        continue;
      double t = A[j][i];
      for(int k=0;k<n*2;k++){
        A[j][k] = A[j][k] - A[i][k] * t;
      }
    }
  }
  
  vector<vector<double>> B(n, vector<double>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      B[i][j] = A[i][j+n];
    }
  }
  return (Ma)B;
}

double Ma::det(){
  vector<vector<double>> A(vec.size(), vector<double>(vec[0].size()));
  A = vec;
  int n=A.size();
  if(n==1)
    return A[0][0];
  else if(n==2)
    return A[0][0] * A[1][1] - A[0][1] * A[1][0];
  try{
    if(vec.size()!=vec[0].size())
      throw "Invalid matrix size. det() can only be called by square matrix!";
  }catch(const char* err){
    cout << "Error:" << err << "\n";
    exit(1);
  }
  //0行目で余因子展開する
  int sum = 0;
  for(int i=0;i<n;i++){
    vector<vector<double>> B(A.size(), vector<double>(A[0].size()));
    B = A;
    for(int j=0;j<n;j++){
      B[j].erase(B[j].begin()+i);
    }
    B.erase(B.begin()); //1行目は最後に消す
    sum += A[0][i] * pow(-1,i+2) * ((Ma)B).det();
  }
  return sum;
}


Ma Ma::operator-(){//前置-
  vector<vector<double>> A=vec;
  vector<vector<double>> C = A;
  for(int i=0;i<A.size();i++){
    for(int j=0;j<A[0].size();j++){
      C[i][j] = -A[i][j];
    }
  }
  this->vec = C;
  return *this;
}
Ma operator+(Ma X, double y){
  vector<vector<double>> x = X.vec;
  vector<vector<double>> A(x.size(), vector<double>(x[0].size(),y));
  Ma Y(A);
  return X + Y;
}
Ma operator+(double y, Ma X){
  return X + y;
}
Ma operator*(Ma X, double y){
  vector<vector<double>> x = X.vec;
  vector<vector<double>> A(x.size(), vector<double>(x[0].size(),y));
  for(int i=0;i<x.size();i++){
    for(int j=0;j<x[0].size();j++){
      A[i][j] = x[i][j] * y;
    }
  }
  return (Ma)A;
}
Ma operator*(double y, Ma X){
  return X * y;
}
Ma operator-(Ma X, double y){
  vector<vector<double>> x = X.vec;
  vector<vector<double>> A(x.size(), vector<double>(x[0].size(),y));
  Ma Y(A);
  return X - Y;
}
Ma operator-(double y, Ma X){
  return -X + y;
}

int main(){
    vector A(3, vector<double>(3)); A = {{1,1,-1}, {-2,0,1}, {0,2,1}};
    vector B(3, vector<double>(3, 2));
    
    Ma Am(A), Bm(B);
    (Am+Bm).show();
    (Am*Bm).show();
    (Am.inv()).show();

    return 0;
}

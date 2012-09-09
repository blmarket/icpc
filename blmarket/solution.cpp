#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define li        long long int
#define rep(i,to) for(li i=0;i<((li)(to));++i)
#define pb        push_back
#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second
 
 
 
 
 
//  p.180
//
#define MAT_MOD  1234567891
//check mod is not long long int
//
li mod = MAT_MOD;
 
template <class T> class MAT
{
public:
  int n,m;
  int mod;
  long long int mod2;
  vector<vector<T> > a;
  
  MAT();
  MAT(int N,int M,long long int num);
  void print();
  void setMod(long long int next_mod);
  long long int size();
  MAT<T> operator+(MAT<T> mat);
  MAT<T> operator-(MAT<T> mat);
  MAT<T> operator*(MAT<T> mat);
  MAT<T> operator*(T num);
  vector<T>& operator[](int num){ return a[num]; }
  MAT<T> transpose();
  MAT<T> pow(long long int m);
};
 
template <class T> long long int MAT<T>::size(){ return n; }
 
 
template <class T> void MAT<T>::print()
{
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) printf("%d ",a[i][j]);
    printf("\n");
  }
}
 
template <> void MAT<double>::print()
{
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) printf("%0.6lf ",(double)a[i][j]);
    printf("\n");
  }
}
 
template <class T> void MAT<T>::setMod(long long int next_mod)
{
  mod=next_mod;
  mod2=(long long int)mod*mod;
}
 
template <class T> MAT<T> MAT<T>::transpose()
{
  MAT res(m,n,0);
  for(int i=0;i<n;i++)for(int j=0;j<m;j++) res[j][i]=a[i][j];
  return res;
}
 
 
template <class T> MAT<T> MAT<T>::pow(long long int a)
{
  MAT<T> res(n,n,0);
  for(int i=0;i<n;i++) res[i][i]=1;
  MAT<T> base=*this;
  for(;a;a>>=1){
    if(a&1) res=res*base;
    base=base*base;
  }
  return res;
}
 
template <class T> MAT<T>::MAT()
{
  n=m=0;
  setMod(MAT_MOD);
}
 
template <class T> MAT<T>::MAT(int N,int M,long long int num)
{
  n=N; m=M;
  setMod(MAT_MOD);
  if(mod<=abs(num)) num%=mod;
  if(num<0) num+=mod;
  a=vector<vector<T> >(n,vector<T>(m,num));
}
 
template <class T> MAT<T> MAT<T>::operator+(MAT<T> mat)
{
  MAT<T> res=*this;
  for(int i=0;i<n;i++)for(int j=0;j<m;j++){
    res[i][j]=res[i][j]+mat[i][j];
    if(mod<=res[i][j]) res[i][j]-=mod;
  }
  return res;
}
 
template <> MAT<double> MAT<double>::operator+(MAT<double> mat)
{
  MAT<double> res=*this;
  for(int i=0;i<n;i++)for(int j=0;j<m;j++) res[i][j]=res[i][j]+mat[i][j];
  return res;
}
 
template <class T> MAT<T> MAT<T>::operator-(MAT<T> mat)
{
  MAT<T> res=*this;
  for(int i=0;i<n;i++)for(int j=0;j<m;j++){
    res[i][j]=res[i][j]-mat[i][j];
    if(res[i][j]<0) res[i][j]+=mod;
  }
  return res;
}
 
template <> MAT<double> MAT<double>::operator-(MAT<double> mat)
{
  MAT<double> res=*this;
  for(int i=0;i<n;i++)for(int j=0;j<m;j++) res[i][j]=res[i][j]-mat[i][j];
  return res;
}
 
template <class T> MAT<T> MAT<T>::operator*(MAT<T> mat)
{
  MAT<T> res=MAT<T>(n,mat.m,0);
  vector<long long int> b(mat.m);
  for(int i=0;i<n;i++){
    for(int j=0;j<mat.m;j++) b[j]=0;
    for(int j=0;j<m;j++){
      if(a[i][j]==0) continue;
      for(int k=0;k<mat.m;k++){
        b[k]+=(long long int)a[i][j]*mat[j][k];
        if(mod2<=b[k]) b[k]-=mod2;
      }
    }
    for(int j=0;j<mat.m;j++) res[i][j]=b[j]%mod;
  }
  return res;
}
 
template <> MAT<double> MAT<double>::operator*(MAT<double> mat)
{
  MAT<double> res=MAT<double>(n,mat.m,0);
  for(int i=0;i<n;i++)for(int j=0;j<m;j++){
    if(a[i][j]==0) continue;
    for(int k=0;k<mat.m;k++) res[i][k]+=a[i][j]*mat[j][k];
  }
  return res;
}
 
 
 
 
 
class TheBrickTowerHardDivOne {
public:
 
  #define MAX 24
  li N;
  li C, K, H;
  vector<li> state[MAX];
  li INDEX[4][4][4][4];
 
  void reform(vector<li> &v)
  {
    if(sz(v) != 4) cout << "Erorr : " << __LINE__ << endl;
    map<li, li> mp;
    rep(i, 4){
      if(mp.find(v[i]) == mp.end()){
        li t = sz(mp);
        mp[v[i]] = t;
      }
      v[i] = mp[v[i]];
    }
  }
  
  void make(vector<li> v)
  {
    if(sz(v) == 4){
      INDEX[v[0]][v[1]][v[2]][v[3]] = N;
      state[N++] = v;
      return;
    }
 
    li maxi = 0;
    rep(i, sz(v)) maxi = max(maxi, v[i]);
    
    for(li i = 0; i <= maxi + 1; i++){
      v.pb(i);
      make(v);
      v.pop_back();
    }
 
  }
  
  li cnt[MAX][10];
  vector<li> base;
  bool debug;
  
  void recur(vector<li> v, li maxi, li way)
  {
    if(debug){
      rep(i, sz(v)) cout << v[i] << " "; cout << endl;
      cout << maxi << " " << way << endl;
      cout << endl;
    }
    
    if(sz(v) == 4){
      li sum = 0;
      rep(i, 4)if(v[i] == base[i]) sum++;
      if(v[0] == v[1]) sum++;
      if(v[0] == v[2]) sum++;
      if(v[1] == v[3]) sum++;
      if(v[2] == v[3]) sum++;
      reform(v);
      if(debug){
        cout << sum << endl;
      }
      li &t = cnt[INDEX[v[0]][v[1]][v[2]][v[3]]][sum];
      t = (t + way) % mod;
      return;
    }
 
    for(li i = 0; i <= maxi + 1; i++){
      v.pb(i);
      if(i == maxi + 1) recur(v, maxi + 1, way * (C - maxi - 1) % mod);
      else recur(v, maxi, way);
      v.pop_back();
    }
  }
  
  int find(int _C, int _K, long long _H){
    N = 0;
    C = _C;
    K = _K;
    H = _H;
    
    make(vector<li>(1, 0));
    MAT<li> left(N * 8 + 1, N * 8 + 1, 0); 
    MAT<li> right(N * 8 + 1, 1, 0);
    rep(i, N)rep(j, K + 1) left[N * 8][i + j * N] = 1;
    left[N * 8][N * 8] = 1;
    
    debug = false;
    rep(i, N){
      memset(cnt, 0, sizeof(cnt));
      base = state[i];
      li maxi = 0;
      rep(j, 4) maxi = max(maxi, base[j]);
      recur(vector<li>(), maxi, 1);
      rep(j, 8)rep(k, N){
        for(li l = 0; l + j < 8; l++){
          left[k + (j + l) * N][i + j * N] = cnt[k][l];
        }
      }
    }
    
//    debug = true;
//    left.print();
    memset(cnt, 0, sizeof(cnt));
    base = vector<li>(4, -1);
    recur(vector<li>(), -1, 1);
    rep(i, N)rep(j, 8) right[i + j * N][0] = cnt[i][j];
//    right.print();
    
//    cout << "  " << H << endl;
    left = left.pow(H);
    
    
    right = left * right;
    return right[8 * N][0];
  }
};

int main(void) {
    TheBrickTowerHardDivOne test;
    cout << test.find(2027, 6, 133181695103836835LL) << endl;
}

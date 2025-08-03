/* https://codeforces.com/gym/105297/problem/D */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

double x, y, z;
double a, b, c;
double r;

double distancia(double x1, double y1, double z1){
  double dx = (a-x1);
  double dy = (b-y1);
  double dz = (c-z1);
  return sqrt(dx*dx + dy*dy + dz*dz);
}

double dif = 1e-7;
double busca_binaria(){
  double pl=0, pr=min(x, min(y, z))/2;

  double menor = 0;

  while (pr-pl > dif){
    double R = (pl+pr)/2;

    double w=R, h=R, d=R;
    double nX=x-R, nY=y-R, nZ=z-R;

    vector<double> A = {w, nX};
    vector<double> B = {h, nY};
    vector<double> C = {d, nZ};
    vector<vector<double>> matriz = {A, B, C};

    bool pode=false;

    for(int i=0; i<2; i++){
      for(int j=0; j<2; j++){
        for(int k=0; k<2; k++){
          double dist = distancia(matriz[0][i], matriz[1][j], matriz[2][k]);

          if(dist >= R+r){
            pode=true;
            break;
          }
        }
      }
    }

    if(pode){
      menor = max(menor, R);
      pl = R;
    }
    else{
      pr = R;
    }
  }
  
  return menor;
}

int32_t main(){  
  cin >> x >> y >> z;
  cin >> a >> b >> c;
  cin >> r;

  double resultado = busca_binaria();
  printf("%.15Lf\n", resultado);

  return 0;
}
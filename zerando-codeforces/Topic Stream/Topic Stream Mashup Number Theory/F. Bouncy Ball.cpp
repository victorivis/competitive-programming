/* https://codeforces.com/contest/1807/problem/F */

#include <bits/stdc++.h>
using namespace std;

int startI;
int startJ;

int endI;
int endJ;

int width;
int height;

void inverterY(string& s){
    s[0] = (s[0]=='U' ? 'D' : 'U');
}

void inverterX(string& s){
    s[1] = (s[1]=='L' ? 'R' : 'L');
}

void somarDirecao(int& i, int& j, string& s, int& colisoes){
    int somarI = (s[0]=='U' ? -1 : 1);
    int somarJ = (s[1]=='L' ? -1 : 1);
    
    bool colidiu=false;
    if(i+somarI>height || i+somarI<=0){
        somarI*=-1;
        inverterY(s);
        colidiu = true;
    }
    
    if(j+somarJ>width || j+somarJ<=0){
        somarJ*=-1;
        inverterX(s);
        colidiu = true;
    }
    
    i+=somarI;
    j+=somarJ;
    
    if(colidiu){
        colisoes++;
    }
}

int bounce(string& direcao){
    int i=startI;
    int j=startJ;
    
    int colisoes=0;
    int passouPeloInicio=0;
    
    while(i!=endI || j!=endJ){
        somarDirecao(i, j, direcao, colisoes);
        
        if(i==startI && j==startJ){
            passouPeloInicio++;
        }
        
        if(passouPeloInicio==5){
            return -1;
        }
    }
    
    return colisoes;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        cin >> height >> width >> startI >> startJ >> endI >> endJ;
        string s; cin >> s;
        
        int total = bounce(s);
        cout << total << "\n";
    }

    return 0;
}
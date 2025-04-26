/* https://codeforces.com/contest/1950/problem/D */

#include <bits/stdc++.h>

using namespace std;

bool is_binary(string& x){
    for(int i=0; i<x.size(); i++){
        if(!(x[i]=='0' || x[i]=='1')){
            return false;
        }
    }
    
    return true;
}

bool eh_binario(long long x){
    while(x>0){
        if(!((x%10==1) || (x%10==0))){
            return false;
        }
        x/=10;
    }
    return true;
}

int total_digitos(string& x){
    int total=0;
    for(int i=0; i<x.size(); i++){
        total += (int) x[i] - '0';
    }
    return total;
}

int eh_divisivel(vector<int>& x, long long& num){
    for(int i=0; i<x.size(); i++){
        if(num % x[i] == 0){
            return x[i];
        }
    }
    return 0;
}

int main(){
    vector<int> x(31, 10);
    x[1]=10;
    x[2]=11;
    x[3]=100;
    x[4]=101;
    x[5]=110;
    x[6]=111;
    x[7]=1000;
    x[8]=1001;
    x[9]=1010;
    x[10]=1011;
    x[11]=1100;
    x[12]=1101;
    x[13]=1110;
    x[14]=1111;
    x[15]=10000;
    x[16]=10001;
    x[17]=10010;
    x[18]=10011;
    x[19]=10100;
    x[20]=10101;
    x[21]=10110;
    x[22]=10111;
    x[23]=11000;
    x[24]=11001;
    x[25]=11010;
    x[26]=11011;
    x[27]=11100;
    x[28]=11101;
    x[29]=11110;
    x[30]=11111;
    
    int quantidade; cin >> quantidade;
    while(quantidade--){
        long long num; cin >> num;
        bool saida;
        
        if(eh_binario(num)){
            printf("YES\n");
        }
        else{
            int a = eh_divisivel(x, num);
            while(a!=0){
                num = num/a;
                a = eh_divisivel(x, num);
            }
            
            if(num==1){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }

    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
typedef struct Matrix Matrix;
 
struct Matrix{
    int mx[2][2];
 
    void Out() {
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 2; ++j)
                printf("%d ",mx[i][j]);
            puts("");
        }
    }
 
    void Init() {
        mx[0][0] = mx[0][1] = mx[1][0] = 1;
        mx[1][1] = 0;
    }
 
    void Emp() {
        mx[0][0] = mx[1][1] = 1;
        mx[0][1] = mx[1][0] = 0;
    }
 
    Matrix operator * (const Matrix a)const {
        Matrix x;
        memset(x.mx,0,sizeof(x.mx));
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 2; ++k)
                    x.mx[i][j] = (x.mx[i][j]+mx[i][k]*a.mx[k][j])%3;
        return x;
    }
};
 
bool pow(int n) {
    Matrix a,b;
    a.Emp();
    b.Init();
    while(n) {
        if(n&1) a = a*b;
        b = b*b;
        n >>= 1;
    }
    return !((a.mx[0][0]*7+a.mx[0][1])%3);
}
 
int main() {
    int n;
    while(cin >> n && n) {
		cout << (pow(n) ? "yes" : "no") << endl;
    }
    return 0;
}

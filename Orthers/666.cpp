#include <iostream>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1007;

void Nhap(int a[maxn][maxn], int &n){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
}

void solve(int a[maxn][maxn], int n){
    int res = -inf;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            for (int ii=i; ii<=n; ii++){
                for (int jj=j; jj<=ii; jj++){
                    if (a[j][i - j + 1] > a[jj][ii - jj + 1]){
                        swap(a[j][i - j + 1], a[jj][ii - jj + 1]);
                    }
                }
            }
        }
    }
    for (int i=2; i<=n; i++){
        for (int j=i; j<=n; j++){
            for (int ii=i; ii<=n; ii++){
                for (int jj=ii; jj <= n; jj++){
                    if (a[n + i - j][j] > a[n + ii - jj][jj]){
                        swap(a[n + i - j][j], a[n + ii - jj][jj]);
                    }
                }
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){   
    int n;
    int a[maxn][maxn];
    Nhap(a, n);
    solve(a, n);
}

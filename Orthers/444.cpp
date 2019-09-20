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
        res = -inf;
        for (int j=1; j<=i; j++){
            res = max(res, a[j][i - j + 1]);
        }
        cout << res << "\n";
    }
    for (int i=2; i<=n; i++){
        res = -inf;
        for (int j=i; j<=n; j++){
            res = max(res, a[n + i - j][j]);
        }
        cout << res << "\n";
    }
}

int main(){   
    int n;
    int a[maxn][maxn];
    Nhap(a, n);
    solve(a, n);
}

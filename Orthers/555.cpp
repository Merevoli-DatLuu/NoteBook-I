#include <iostream>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000007;

void Nhap(int a[maxn], int &n, int&m){
    cin >> n >> m;
    for (int i=1; i<=n*m; i++){
            cin >> a[i];
    }
}

void solve(int a[maxn], int n, int m){
    for (int i=1; i < n*m; i++){
        for (int j=i+1; j<=n*m; j++){
            if (a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << a[(i - 1)*m + j] << ' ';
        }
        cout << "\n";
    }
}

int main(){   
    int n, m;
    int a[maxn];
    Nhap(a, n, m);
    solve(a, n, m);
}

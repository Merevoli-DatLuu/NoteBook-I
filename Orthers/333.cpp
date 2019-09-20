#include <iostream>

using namespace std;
const int maxn = 100007;

void Nhap(int a[], int &n){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
}

bool Check(int a){
    if (a < 2){
        return false;
    }
    else{
        for (int i=2; i*i<=a; i++){
            if (a%i == 0){
                return false;
            }
        }
        return true;
    }
}

void Sort(int a[], int n){
    for (int i=1; i < n; i++){
        for (int j=i+1; j<=n; j++){
            if (a[i] > a[j] && Check(a[i]) && Check(a[j])){
                swap(a[i], a[j]);
            }
        }
    }
}

void Print(int a[], int n){
    for (int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
}

int main(){   
    int n;
    int a[maxn];
    Nhap(a, n);
    Sort(a, n);
    Print(a, n);
}

#include <iostream>

using namespace std;
const int maxn = 1000007;

void Nhap(int a[], int &n){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
}

void Print(int a[], int n){
    for (int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

void Selection_Sort(int a[], int n){
    for (int i=1; i<n; i++){
        int temp = i;
        for (int j=i+1; j<=n; j++){
            if (a[temp] > a[j]){
                temp = j;
            }
        }
        swap(a[temp], a[i]);
    }
}

void Interchange_Sort(int a[], int n){
    for (int i=1; i<n; i++){
        for (int j= i + 1; j<=n; j++){
            if (a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}

int main(){
    int a[maxn];
    int n;
    Nhap(a, n);
    //Selection Sort
    cout << "Selection Sort\n";
    Selection_Sort(a, n);
    Print(a, n);
    cout << "\n";

    //Interchange Sort
    cout << "Interchange Sort\n";
    Interchange_Sort(a, n);
    Print(a, n);
    cout << "\n";
}

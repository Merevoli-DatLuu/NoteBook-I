#include <iostream>

using namespace std;
const int maxn = 100007;

int Binary_Search(int a[], int n, int x){
    int l = 1;
    int r = n;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (x > a[mid]){
            l = mid + 1;
        }
        else if (x < a[mid]){
            r = mid - 1;
        }
        else{
            int res = mid;
            while (x == a[res] && res >= 1){
                res--; 
            }
            res++;
            return res;
        }
    }
    return -1;
}

void Sort(int a[], int n){
    for (int i=1; i < n; i++){
        for (int j=i+1; j<=n; j++){
            if (a[i] < a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}

int main(){
    // Cau b
    int a[maxn] = {0, 1, 2, 4, 4, 4, 9, 10};
    int n = 7;
    int x = 4;
    cout << Binary_Search(a, n, x) << '\n';

    // Cau c
    cout << "n: ";
    cin >> n;
    cout << "a[]: ";
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    cout << "k: ";
    int k;
    cin >> k;
    Sort(a, n);
    for (int i=1; i<=k; i++){
        cout << a[i] << " ";
    }
}

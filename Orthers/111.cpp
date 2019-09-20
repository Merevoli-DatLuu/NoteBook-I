#include <iostream>

using namespace std;

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
        Print(a, n);
    }
}

void Interchange_Sort(int a[], int n){
    for (int i=1; i<n; i++){
        for (int j= i + 1; j<=n; j++){
            if (a[i] > a[j]){
                swap(a[i], a[j]);
                Print(a, n);
            }
        }
    }
}

void Bubble_Sort(int a[], int n){
    for (int i=1; i<n; i++){
        for (int j = n; j >= i + 1; j--){
            if (a[i] > a[j]){
                swap(a[i], a[j]);
                Print(a, n);
            }
        }
    }
}

void Insert_Sort(int a[], int n){
    for (int i=2; i<=n; i++){
        int temp = a[i];
        int j = i;
        while (a[j-1] > temp && j >= 2){
            a[j] = a[j-1];
            j--;
            Print(a, n);
        }
        a[j] = temp;
        Print(a, n);
    }
}

int main(){
    int a1[8] = {0, 84, 32, 13, 64, 1, 55, 48};
    int a2[8] = {0, 84, 32, 13, 64, 1, 55, 48};
    int a3[8] = {0, 84, 32, 13, 64, 1, 55, 48};
    int a4[8] = {0, 84, 32, 13, 64, 1, 55, 48};
    int n = 7;
    //Selection Sort
    cout << "Selection Sort\n";
    Print(a1, 7);
    Selection_Sort(a1, 7);
    cout << "\n";

    //Interchange Sort
    cout << "Interchange Sort\n";
    Print(a2, 7);
    Interchange_Sort(a2, 7);
    cout << "\n";

    //Bubble Sort
    cout << "Bubble Sort\n";
    Print(a3, 7);
    Bubble_Sort(a3, 7);
    cout << "\n";

    //Insert Sort
    cout << "Insert Sort\n";
    Print(a4, 7);
    Insert_Sort(a4, 7);
    cout << "\n";
}

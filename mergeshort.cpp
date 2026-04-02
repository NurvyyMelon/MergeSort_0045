#include <iostream>
using namespace std;

// create main array & temporary array
int arr[20], B[20];
// n is array input size
int n;
void input() {
    while (true) {
        cout << "Masukkan Panjang element array : ";
        cin >> n;

        if (n <= 20) {
            break;
        } else {
            cout << "\nMaksimal panjang array adalah 20" << endl;
        }
    }
}
    cout << "\n-----------------------" << endl;
    cout << "Inputkan Isi element array" << endl;
    cout << "-----------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Array index ke-" << i << " : ";
        cin >> arr[i];
    }
    void mergeSort(int low, int high) {
    if (low >= high) {
        return;
    }
}
// Di dalam mergeSort
    int mid = (low + high) / 2;

    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    // Di dalam mergeSort (step 4)
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            B[k] = arr[i];
            i++;
        } else {
            B[k] = arr[j];
            j++;
        }
        k++;
    }
    while (j <= high) {
        B[k] = arr[j];
        j++;
        k++;
    }
    while (i <= mid) {
        B[k] = arr[i];
        i++;
        k++;
    }
    for (int x = low; x <= high; x++) {
        arr[x] = B[x];
    }
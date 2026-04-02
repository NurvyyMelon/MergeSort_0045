#include <iostream>
using namespace std;

// [COMMIT 1]: Setup global variables
int arr[20], B[20];
int n;

// [COMMIT 2 & 3]: Input function with validation and element loop
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

    cout << "\n-----------------------" << endl;
    cout << "Inputkan Isi element array" << endl;
    cout << "-----------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Array index ke-" << i << " : ";
        cin >> arr[i];
    }
}

// [COMMIT 4-9]: Merge Sort core logic (Recursive & Merging)
void mergeSort(int low, int high) {
    // Base case: jika elemen hanya satu
    if (low >= high) {
        return;
    }

    // Mencari titik tengah dan membagi array
    int mid = (low + high) / 2;

    mergeSort(low, mid);
    mergeSort(mid + 1, high);

    // Proses Merging (Penggabungan)
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

    // Memasukkan sisa elemen dari sisi kanan
    while (j <= high) {
        B[k] = arr[j];
        j++;
        k++;
    }

    // Memasukkan sisa elemen dari sisi kiri
    while (i <= mid) {
        B[k] = arr[i];
        i++;
        k++;
    }

    // Menyalin data dari array sementara (B) balik ke array utama (arr)
    for (int x = low; x <= high; x++) {
        arr[x] = B[x];
    }
}

// [COMMIT 10]: Output and Main Orchestration
void output() {
    cout << "\nData setelah diurutkan (Merge Sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    input();
    if (n > 0) {
        mergeSort(0, n - 1);
    }
    output();
    return 0;
}
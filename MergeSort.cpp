#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) { // corrected from n1 to n2
        b[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            k++;
            i++;
        } else {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1) {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2) {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2; // safer way to calculate mid to avoid overflow
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int arr[] = {0, 2, 4, 2, 1, 4, 3, 3};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, arr_size - 1);
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

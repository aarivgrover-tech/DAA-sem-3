#include <iostream>
#include <vector>

using namespace std;
// Aariv Grover 25/DA/001
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortRecursive(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortRecursive(arr, left, mid);
    mergeSortRecursive(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSortIterative(vector<int>& arr) {
    int n = arr.size();
    for (int curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = (left_start + curr_size - 1 < n - 1) ? (left_start + curr_size - 1) : (n - 1);
            int right_end = (left_start + 2 * curr_size - 1 < n - 1) ? (left_start + 2 * curr_size - 1) : (n - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    if (!(cin >> n)) return 0;
    
    vector<int> arr1(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    
    vector<int> arr2 = arr1;
    
    mergeSortRecursive(arr1, 0, n - 1);
    cout << "Recursive Merge Sort result: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    mergeSortIterative(arr2);
    cout << "Iterative Merge Sort result: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}
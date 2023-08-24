#include <bits/stdc++.h>
using namespace std;

long long cnt = 0;
int a[500010];
// int nums[] = {5, 4, 2, 6, 3, 1};

// void print(int * a, int len) {
//     for (int i = 0; i < len; i++) {
//         cout << a[i] << " ";
//     }
//     cout << "\n";
// }
void mergeSort(int * arr, int left, int mid, int right) {
    int * temp = new int[right - left + 1];

    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) //较小的先存入temp中
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            cnt += mid - i + 1;
        }
    }
    // for (; i <= mid && j <= right; i++, j++, k++) {
    //     if (arr[i] <= arr[j]) {
    //         temp[k] = arr[i];
    //     } else {
    //         temp[k] = arr[j];
    //     }
    // }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    // print(temp, right - left + 1);
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
    delete[] temp;
}

void merge(int * a, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + ((right - left) >> 1);
    merge(a, left, mid);
    merge(a, mid + 1, right);
    mergeSort(a, left, mid, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;
    cin >> n;
    // int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    merge(a, 0, n - 1);

    // print(nums, 6);
    cout << cnt << endl;
    return 0;
}

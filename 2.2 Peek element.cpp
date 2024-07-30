#include <stdio.h>
int findPeakUtil(int arr[], int low, int high, int n) {
    int mid = low + (high-low) / 2;
    if ((mid == 0 || arr[mid-1]<=arr[mid]) &&
        (mid == n - 1 || arr[mid+1]<=arr[mid])) {
        return mid;
    }
    if (mid > 0 && arr[mid-1]>arr[mid]) {
        return findPeakUtil(arr, low, mid - 1, n);
    } else {
        return findPeakUtil(arr, mid + 1, high, n);
    }
}
int findPeak(int arr[], int n) {
    return findPeakUtil(arr,0,n-1,n);
}
int main() {
    int arr[] = {1,3,20,45,1,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int peakIndex = findPeak(arr, n);
    printf("peak element is %d -> index %d\n", arr[peakIndex], peakIndex);
    return 0;
}


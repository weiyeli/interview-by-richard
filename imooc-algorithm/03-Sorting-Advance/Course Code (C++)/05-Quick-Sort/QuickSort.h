//
// Created by ricardooli on 2023/1/19.
//

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int __partition(int arr[], int l, int r) {
    int pivot = arr[l];
    int j = l;
    for (int i = l + 1; i <= r; ++i) {
        if (arr[i] < pivot) {
            j++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void __quickSort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int p = __partition(arr, l , r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

void __quickSortNoRecursive(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    stack<int> s;
    int index = __partition(arr, l , r);
    if (index - 1 > l) {
        s.push(l);
        s.push(index-1);
    }
    if (index + 1 < r) {
        s.push(index+1);
        s.push(r);
    }
    while (!s.empty()) {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();
        index = __partition(arr, left, right);
        if (index - 1 > left) {
            s.push(left);
            s.push(index-1);
        }
        if (index + 1 < right) {
            s.push(index+1);
            s.push(right);
        }
    }
}

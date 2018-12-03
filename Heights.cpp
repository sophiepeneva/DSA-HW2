# DSA-HW2

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int*& arr, int left, int middle, int right, long long& inversionCounter)
{
    int leftIndex = left;
    int rightIndex = middle + 1;
    int totalInLeftArr = middle - left + 1;
    int index = 0;
    int* temp = new int[right - left + 1];
    while (leftIndex <= middle && rightIndex <= right) 
    {
        if (arr[leftIndex] <= arr[rightIndex]) 
        {
            temp[index++] = arr[leftIndex++];
            totalInLeftArr--;
        }
        else
        {
            temp[index++] = arr[rightIndex++];
            inversionCounter+=(long long)totalInLeftArr;
        }
    }
    if (leftIndex > middle)for (int i = index;i < right - left + 1;i++)temp[i] = arr[rightIndex++];
    else { for (int i = index;i < right - left + 1;i++)temp[i] = arr[leftIndex++]; }
    int counter = 0;
    for (int i = left;i < right + 1;i++)arr[i] = temp[counter++];
}


void mergeSort(int*& arr, int left, int right, long long &counter) 
{
    if (left >= right)return;
    int middle = (left + right) / 2;
    mergeSort(arr, left, middle, counter);
    mergeSort(arr, middle + 1, right, counter);
    merge(arr, left, middle, right, counter);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int q;
    cin>>q;
    while(q>0){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0;i < n;i++)cin >> arr[i];
    long long inversions = 0;
    mergeSort(arr, 0, n - 1,inversions);
    cout << inversions<<endl;
    q--;
    }
    return 0;
}

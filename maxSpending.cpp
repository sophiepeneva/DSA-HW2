# DSA-HW2

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int pivot = arr[(left + right) / 2];
      while (i < j) {
            while (arr[i] < pivot)i++;
            while (arr[j] > pivot)j--;
            if (i <= j) 
            {
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
      }
      if (left < j)quickSort(arr, left, j);
      if (i < right)quickSort(arr, i, right);
}

int countMaxPresents(int* arr, int n, int k)
{
    int sum = 0;
    int gifts = 0;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i]<=k)
        {
            sum+=arr[i];
            gifts++;
        }
        else{return gifts;}
    }
    return gifts;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin>>n>>k;
    int* arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    quickSort(arr, 0, n-1);
    cout<<countMaxPresents(arr,n,k);
    return 0;
}

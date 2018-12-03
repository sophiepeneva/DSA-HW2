# DSA-HW2

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool bigger(int a, int b)
{
    string aString = to_string(a);
    string bString = to_string(b);
    string ab = aString + bString;
    string ba = bString + aString;
    int aB = atoi(ab.c_str());
    int bA = atoi(ba.c_str());
    return aB > bA;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool compare(int a, int b) 
{
    if(a==0)return false;
    if(b==0)return true;
    int index = 1;
    int digitsFirst = log10(float(a)) + 1;
    int digitsSecond = log10(float(b)) + 1;
    if (digitsFirst == digitsSecond)return a > b;
    if (digitsFirst > digitsSecond) 
    {
        int tempA = a / pow(10, digitsFirst - digitsSecond);
        if (tempA == b) 
        {
            tempA = a / pow(10, digitsFirst - digitsSecond - 1);
            tempA = tempA % 10;
        }
        return tempA > b;
    }
    if (digitsFirst < digitsSecond)
    {
        int tempB = b / pow(10, digitsSecond - digitsFirst);
        if (tempB == a)
        {
            tempB = b / pow(10, digitsSecond - digitsFirst - 1);
            tempB = tempB % 10;
        }
        return a > tempB;
    }
    return false;

}

int* sort(int* arr, int n) 
{
    int index = 1;
    for (int i = 0;i < n - 1; i++) 
    {
        for (int j = i + 1;j < n; j++) 
        {
            if(arr[i]!=arr[j]){
                if (bigger(arr[j], arr[i]) == true)swap(arr[i], arr[j]);
            }
        }
    }
    return arr;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    int* arr = new int[n];
    bool onlyZeros = true;
    for (int i = 0;i < n;i++)
    {
        cin >> arr[i];
        if (arr[i] != 0)onlyZeros = false;
    }
    if (onlyZeros == false) {
        arr = sort(arr, n);
        for (int i = 0;i < n;i++)cout << arr[i];
    }
    else { cout << 0; }
    
    return 0;
}

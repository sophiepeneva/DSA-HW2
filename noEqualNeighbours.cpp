# DSA-HW2

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int occurancesOfMostCommon(string str) 
{
    int max = 0;
    for (int i = 0;i < str.length();i++) 
    {
        char curr = str[i];
        int numberOfCurr = 1;
        for (int j = 0;j < str.length();j++) 
        {
            if (curr == str[j] && i != j)numberOfCurr++;
        }
        if (numberOfCurr > max)max = numberOfCurr;
    }
    return max;
}

string isSortable(string myStr)
{
    if (myStr.length() == 0)return "Yes";
    int initialLength = myStr.length();
    string newString = myStr.substr(0, 1);
    myStr = myStr.substr(1, myStr.length() - 1);
    for (int i = 0; i < myStr.length();i++)
    {
        if (myStr[i] != newString[newString.length() - 1])
        {
            newString = newString + myStr[i];
            myStr = myStr.substr(0, i) + myStr.substr(i + 1, myStr.length() - i);
            i = -1;
        }
        else if (myStr[i] != newString[0])
        {
            newString = myStr[i] + newString;
            myStr = myStr.substr(0, i) + myStr.substr(i + 1, myStr.length() - i);
            i = -1;
        }
    }
    if (initialLength != newString.length())return "No";
    return "Yes";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    string myStr;
    cin>>myStr;
    if(occurancesOfMostCommon(myStr)-1<=myStr.length() - occurancesOfMostCommon(myStr))cout<<"Yes";
    else{cout<<"No";}
    return 0;
}

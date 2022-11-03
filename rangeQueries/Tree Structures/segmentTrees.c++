//Range sum query :- O(log(n))
//Updating a value :- O(log(n))

// 0-indexed
// SUM, MIN, MAX, GCD, BIT operations, OR, XOR QUERIES

#include<bits/stdc++.h>
using namespace std;

#define MAX 10000

int seg[4*MAX];

void update(int* arr, int index, int low, int high, int U, int val) //same logic as preprocess
{
    if(U<low or U>high) return;
    if(low == U and high == U)
    {
        arr[low] = val;
        seg[index] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    update(arr, 2 * index + 1, low, mid, U, val);
    update(arr, 2 * index + 2, mid+1, high, U, val);
    seg[index] = seg[2*index+1] + seg[2*index+2];
}

void preprocess(int* arr, int index, int low, int high)
{
    if(low == high)
    {
        seg[index] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    preprocess(arr, 2 * index + 1, low, mid);
    preprocess(arr, 2 * index + 2, mid+1, high);
    seg[index] = seg[2*index+1] + seg[2*index+2];
}

int query(int index, int low, int high, int l, int r)
{
    
    if(l<=low and r>=high) 
    {
        return seg[index];
    }
    if(l>high or r<low)
    {
        return 0;
    }
    int mid = (low+high)/2;
    int left = query(2*index+1, low, mid, l, r);
    int right = query(2*index+2, mid+1, high, l, r);
    return left+right;
}

int main()
{
    int arr[] = {1,3,6,8,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    preprocess(arr, 0, 0, n-1);
    update(arr, 0, 0, n-1, 3, 0);
    cout<<query(0, 0, n-1, 0, n-1);
    return 0;
}
//binaryIndexedTrees or fenwickTrees

//Dynamic version of prefix sum array
//Range sum query :- O(log(n))
//Updating a value :- O(log(n))
//Usually trees stored in array

// 1-indexed
// ONLY SUM QUERIES

#include<bits/stdc++.h>
using namespace std;

#define MAX 10000

int fen[MAX];

int update(int index, int add, int n)
{
    while(index <= n)
    {
        fen[index] += add;
        index += index & (-index);
    }
}

// Return sum from (1, index) -> both ends included
int sum(int index) 
{
    if(index < 1) return 0;
    int s = 0;
    while(index>0)
    {
        s += fen[index];
        index -= index & (-index);
    }
    return s;
}

int preprocess(int* arr, int n)
{
    for(int i=0; i<n; i++)
    {
        update(i+1, arr[i], n);
    }
}

int query(int L, int R)
{
    if(L>R || L<1 || R<1) return -1e5;

    return sum(R) - sum(L-1);
}

int main()
{
    int arr[] = {1,3,6,8,4,3,6,8,-12,3,2,54,98,3,6,8,5,3,5,8,9,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    preprocess(arr, n);
    cout<<query(1, n);
    return 0;
}
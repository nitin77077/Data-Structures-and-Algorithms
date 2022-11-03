//Sparse Table Algorithm (Space :- O(nlog(n)), Query :- O(1))

#include<bits/stdc++.h>
using namespace std;

#define MAX 500

vector<vector<int>> lookup(MAX, vector<int> (MAX, 0));

// O(nlog(n))
void preprocess(int* arr, int n)
{
    for(int i=0; i<n; i++)
    {
        lookup[i][0] = arr[i];
    }

    for(int j=1; (1<<j)<n; j++)
    {
        for(int i=0; i<=n-(1<<j); i++)
        {
            lookup[i][j] = min(lookup[i][j-1], lookup[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int* arr, int n, int L, int R)
{
    if(L >= n || R >= n || L > R)
    {
        return -1;
    }
    int x = (int)log2(R-L+1);

    return min(lookup[L][x], lookup[R-(1<<x)+1][x]);
}

int main()
{
    int arr[] = {1,3,6,8,4,3,6,8,-12,3,2,54,98,3,6,8,5,3,5,8,9,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    preprocess(arr, n);
    cout<<query(arr, n, 0, n-1);
}
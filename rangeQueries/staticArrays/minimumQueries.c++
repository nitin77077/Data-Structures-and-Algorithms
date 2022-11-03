//Sparse Table Algorithm

#include<bits/stdc++.h>
using namespace std;

#define MAX 500

vector<vector<int>> lookup(MAX, vector<int> (MAX, 0));

void preprocess(vector<int> arr, int n)
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

int query(vector<int> arr, int L, int R)
{
    int x = (int)log2(R-L+1);

    return min(lookup[L][x], lookup[R-(1<<x)+1][x]);
}

int main()
{
    
}
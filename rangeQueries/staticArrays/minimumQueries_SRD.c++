//Square Root Decomposition (Space :- O(log(n)), Query :- O(log(n)))

#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define SQRT_SIZE 100

int block[SQRT_SIZE];

// O(n)
void preprocess(int *arr, int n)
{
    int k = (int)sqrt(n);
    int block_index = -1;

    for(int i=0; i<n; i++)
    {
        block[i] = 1e9;                                      //inefficient step
        if(i%k == 0) block_index++;
        block[block_index] = min(block[block_index], arr[i]);
    }
}

int query(int* arr, int n, int L, int R)
{
    int k = (int)sqrt(n);
    int ans = 1e9;                                            //inefficient step

    while(L<R and L%k != 0)
    {
        ans = min(ans, arr[L++]);
    }
    while(L+k-1 <= R)
    {
        ans = min(ans, block[L/k]);
        L += k;
    }
    while(L<=R)
    {
        ans = min(ans, arr[L++]);
    }

    return ans;
}

int main()
{
    int arr[] = {1,3,6,8,4,3,6,8,-12,3,2,54,98,3,-123,8,5,3,5,8,9,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    preprocess(arr, n);
    cout<<query(arr, n, 0, n-1);
}

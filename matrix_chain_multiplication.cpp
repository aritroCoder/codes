// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;
int m[100][100];

// Function for matrix chain multiplication
// p = array containing matrix dimentions
int matrixChainMemoised(int *p, int i, int j)
{
    if (i == j)  //only one dimention given
    {
        return 0;
    }
    if (m[i][j] != -1)
    {
        return m[i][j];
    }
    m[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        m[i][j] = min(m[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return m[i][j];
}

int Matrix_Chain_Order(int *p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(m, -1, sizeof m);

    cout << "Minimum number of multiplications is "
         << Matrix_Chain_Order(arr, n)<<endl;
}
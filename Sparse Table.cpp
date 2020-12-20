#include <bits/stdc++.h>
 #define MAX 500
using namespace std;

int table[MAX][MAX];
void buildSparseTable(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        table[i][0] = arr[i];

   for (int j = 1; j <= n; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
}


int query(int L, int R)
{
    int j = (int)log2(R - L + 1);
    return __gcd(table[L][j], table[R - (1 << j) + 1][j]);
}


int main()
{   cout<<"Enter the size of the array";
    int p;
    cin>>p;
    int a[p];
    cout<<"Enter the values of array";
    for(int i=0;i<p;i++)
        cin>>a[i];
    int n = sizeof(a) / sizeof(a[0]);
    buildSparseTable(a, n);
    cout<<"enter the range i.e L and R value";
    int L,R;
    cin>>L>>R;
    cout << query(L, R) << endl;
    return 0;
}


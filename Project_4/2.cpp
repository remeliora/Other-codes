#include <iostream>
using namespace std;


void countSort(int arr[], int n, int exp)
{
    int* output = new int[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n, int k)
{
    for (int exp = 1; k >= 0; exp *= 10)
    {
        countSort(arr, n, exp);
        k--;
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n, k;
    cin >> n >> k;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    radixsort(arr, n, k);
    print(arr, n);
    return 0;
}
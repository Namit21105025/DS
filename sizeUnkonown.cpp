#include<iostream>

using namespace std;

// Linear search

int linearSearch(int* arr, int x)
{
    for (int i = 0;; i++) // The loop will stop when the element is found.
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
}

// BINARY SEARCH

//this function is a simple binary search functio where left and right indexes are being provided.

int binarySearchHelper(int* arr,int l,int r,int x)
{
    int mid = (l+r) / 2;
    while(l<=r)
    {
        if(arr[mid]>x)
        {
            r = mid - 1;
            mid = (l+r) / 2;
        }
        else if(arr[mid]<x)
        {
            l = mid+1;
            mid = (l+r) / 2;
        }
        else
        {
            return mid;
        }
    }

}

//we try to reduce our work done to O(log(N)) time complexity, by increasing the range of our search exponentitaly by 2.

int binarySearch(int* arr, int x)
{
    int low = 0;
    int high = 1;

    while (arr[high] < x)//if element to be found is still at a higher index
    {
        low = high;//update the low value
        high = 2 * high;//double the range of search
    }

    return binarySearchHelper(arr,low,high,x);
}

int main(){
    int *arr = new int[10000];
    int n;
    cout << "Number of elements in an array : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "ENTER THE ELEMENT TO SEARCH FOR : ";
    cin >> x;
    cout << endl;

    cout << "Index of " << x << " from Linear Search is : " << linearSearch(arr, x) << endl;
    cout << "Index of " << x << " from Binary Search is : " << binarySearch(arr, x) << endl;
    delete[] arr;

    return 0;
}
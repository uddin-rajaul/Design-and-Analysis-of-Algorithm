#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

int counter=0;
void QuickSortedArray(int A[], int n)
{
    cout << "The sorted array for 'Quick Sort' is:\n" << endl;
    cout<<"-->";

    for (int i = 0; i < n; i++)
        cout << "|" << A[i];

    cout << "|" << endl;
}

int QuickPartition(int A[], int l, int r)
{
    int pivot = A[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);
    return i + 1;
}
int randPartition(int A[], int l, int r)
{
    srand(time(NULL));
    int k = l + rand() % (r - l + 1); // Generate a random index in the range [l, r]
    swap(A[l], A[k]);
    return QuickPartition(A,l,r);
}

int RandQuickSort(int A[], int l, int r)
{
    
    if (l < r)
    {
        counter++;
        int p = randPartition(A, l, r);
        RandQuickSort(A, l, p - 1);
        RandQuickSort(A, p + 1, r);
    }

    // return r - l + 1;
    return counter;
}

int main()
{
    int A1[20], num,quick_time,i;
    cout << "Enter the number of elements: ";
    cin >> num;
    cout<<endl;

    for (i = 0; i < num; i++)
    {
        cout << "Enter "<<i + 1 <<" element: ";
        cin >> A1[i];
    }

    cout << endl;
    quick_time = RandQuickSort(A1, 0, num - 1);
    QuickSortedArray(A1, num);
    cout<<"\nThe time complexity is: "<<quick_time<<endl<<endl;

    return 0;
}

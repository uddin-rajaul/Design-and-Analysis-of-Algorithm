#include <iostream>
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

int QuickSort(int A[], int l, int r)
{
    if (l < r)
    {
        counter++;
        int p = QuickPartition(A, l, r);
        QuickSort(A, l, p - 1);
        QuickSort(A, p + 1, r);
    }

    return counter;
}

void MergeSortedArray(int A[], int n)
{
    cout << "The sorted array for 'Merge Sort' is:\n" << endl;
    cout<<"-->";

    for (int i = 0; i < n; i++)
        cout << "|" << A[i];

    cout << "|" << endl;
}

void Merge(int A[],int m, int l, int r)
{
    int B[20],x,y,k,i;

    x = l;
    y = m + 1;
    k = l;

    while(x <= m && y <= r)
    {
        if(A[x] < A[y])
        {
            B[k] = A[x];
            x++;
            k++;
        }
        else
        {
            B[k] = A[y];
            y++;
            k++;
        }
    }

    while(x <= m)
    {
        B[k] = A[x];
        x++;
        k++;
    }
    while(y <= r)
    {
        B[k] = A[y];
        y++;
        k++;
    }

    for(i =0; i <= r; i++)
        A[i]=B[i];

}

int MergeSort(int A[], int l, int r)
{
    if (l < r)
    {
        int m;
        counter++;
        m = (l + r) / 2;
        MergeSort(A,l,m);
        MergeSort(A,m + 1,r);
        Merge(A, m, l, r);
    }

    return counter;
}

int main()
{
    int A1[20],A2[20], num,quick_time,i, merge_time;
    cout << "Enter the number of elements: ";
    cin >> num;
    cout<<endl;

    for (i = 0; i < num; i++)
    {
        cout << "Enter "<<i + 1 <<" element: ";
        cin >> A1[i];
    }

    for (i = 0; i < num; i++)
    {
        A2[i] = A1[i];
    }
    cout << endl;

    quick_time = QuickSort(A1, 0, num - 1);
    QuickSortedArray(A1, num);
    cout<<"\nThe time complexity is: "<<quick_time<<endl<<endl;

    merge_time = MergeSort(A2, 0, num - 1);
    MergeSortedArray(A2, num);
    cout<<"\nThe time complexity is: "<<merge_time<<endl;

    return 0;
}
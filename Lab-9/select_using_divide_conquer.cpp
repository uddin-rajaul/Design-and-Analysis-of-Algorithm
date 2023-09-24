#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

int counter=0, select_counter=0;

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

int randselect(int A[], int l,int r,int i, int &select_counter){
    int p,k;
    if(l<r){
        select_counter++;

        p = randPartition(A,l,r);
        k = p-l+1;

        if(i==k){
            return A[p];
        }
        else if(i<k){
            return randselect(A, l, p-1, i, select_counter);
        }
        else{
            return randselect(A, p+1, r,i-k, select_counter);
        }
    }
    return A[r];
}

int RandQuickSort(int A[], int l, int r, int &quick_counter)
{

    if (l < r)
    {
        counter++;
        int p = randPartition(A, l, r);
        RandQuickSort(A, l, p - 1, quick_counter);
        RandQuickSort(A, p + 1, r, quick_counter);
    }

    // return r - l + 1;
    return counter;
}

int main()
{
    int A1[20],A2[20], num,quick_time,i,x, select_time;
    int select_counter = 0;
    int quick_counter = 0;
    cout << "Enter the number of elements: ";
    cin >> num;
    cout<<endl;

    for (i = 0; i < num; i++)
    {
        cout << "Enter "<<i + 1 <<" element: ";
        cin >> A1[i];
    }
    // first array was having conflict while using randselect
    for(i=0;i<num;i++){
        A2[i]=A1[i];
    }
    cout<<"Enter the index you want to search at: ";
    cin>>x;

    cout << endl;
    
    quick_time = RandQuickSort(A1, 0, num - 1, quick_counter);
    QuickSortedArray(A1, num);

    select_time = randselect(A2, 0, num - 1, x, select_counter);

    cout << "\nElement at " << x << " index : " << select_time << endl << endl;
    cout << "Steps in QuickSort: " << quick_time << endl;
    cout << "Steps in Randomized Selection: " << select_counter << endl;

    return 0;
}

#include <iostream>
using namespace std;

int counter=0;

int recbinarySearch(int A[], int n, int l, int r, int key)
{
    int m, index=-1;
    if(l<=r)
    {
        counter++;
        m=(l+r)/2;
        if(A[m]==key)
        {
            return m;
        }
        else if(A[m]>key)
            return recbinarySearch(A,n,l, m-1,key);
        else
            return recbinarySearch(A, n, m+1, r, key);
    }
    return -1;
}

int main()
{
    int A[20], n, binary, key, i;

    cout<<"Enter the size of list: ";
    cin>>n;

    cout<<endl;

    for(i=0;i<n;i++)
    {
        cout<<"Enter item " <<i+1 <<" : " ;
        cin>> A[i];
    }

    cout<<"\nSearch What? : ";
    cin>> key;

    cout<<"\nBinary Search";
    binary = recbinarySearch(A,n,0,n-1,key);
    if (binary!=-1){
        cout<<"\nFound " <<key <<" At index : " <<binary+1;
        cout<< "\nCompleted in " <<counter <<" steps\n";
        }
    else
        cout<<key <<" Not found in the list";
    return 0;
}

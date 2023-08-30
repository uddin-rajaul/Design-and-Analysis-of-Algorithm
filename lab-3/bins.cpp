#include <iostream>
using namespace std;

int linearSearch(int A[], int n, int key)
{
    int i,index=-1,counter=0;
    for(i=0;i<n;i++)
    {
        counter++;
        if(A[i]==key)
        {
            index = i;
            break;
        }
    }
    if(index!=-1)
        cout<<"\nFound " <<key <<" At index : " <<index+1;
    else
        cout<<key <<" Not found in the list";
    return counter;
}

int binarySearch(int A[], int n, int key)
{
    int m, l=0, r=n-1, index=-1,counter=0;
    while(l<=r)
    {
        counter++;
        m=(l+r)/2;
        if(key==A[m])
        {
            index = m;
            break;
        }
        else if(key<A[m])
            r = m-1;
        else
            l=m+1;
    }

    if(index!=-1)
        cout<<"\nFound " <<key <<" at index : " <<index+1;
    else
        cout<<key <<" Not found in the list";
    return counter;
}

int main()
{
    int A[20], n, step_linear, step_binary, key, i;

    cout<<"Enter the size of list: ";
    cin>>n;

    cout<<endl;

    for(i=0;i<n;i++)
    {
        cout<<"Element " <<i+1 <<" : " ;
        cin>> A[i];
    }

    cout<<"\nWhat to search? : ";
    cin>> key;

    cout<<"\nLinear Search";
    step_linear = linearSearch(A,n,key);
    cout<< "\nCompleted in " <<step_linear <<" steps\n";

    cout<<"\nBinary Search";
    step_binary = binarySearch(A,n,key);
    cout<< "\nCompleted in " <<step_binary <<" steps\n";

    return 0;
}
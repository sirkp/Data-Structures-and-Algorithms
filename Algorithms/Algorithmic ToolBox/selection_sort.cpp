#include <bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    (*a)=(*a)+(*b);
    (*b)=(*a)-(*b);
    (*a)=(*a)-(*b);
}
int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    int low=0,high=n;
    for(int i=low;i<high;i++)
    {
        int min=i;

        for(int j=i+1;j<high;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        
        if(arr[min]!=arr[i])
        swap(&arr[min],&arr[i]);
    }
    for(int i=low;i<high;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
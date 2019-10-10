#include<iostream>
using namespace std;
int main()
{
    int arr[15];
    for(int i=0;i<15;i++)
        cin>>arr[i];
    int j=0;
    for(int i=1;i<15;i++)
    {
        int key=arr[i];
        //we have to insert into sorted list not in whole array thats why i=1
        //now we have to compare in sorted array and sorted array ends at i-1 so j=i-1;
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            //checking inside whole sorted array
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(int i=0;i<15;i++)
        cout<<arr[i]<<" ";
}

#include <bits/stdc++.h>
#include <math.h>
#define pb push_back
#define wi waste.insert
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        int max_ele=0;
        bool find[1000100]={0};
        for(int i=n-1;i>=0;i--)
        {
            cin>>arr[i];
            if(arr[i]>max_ele)
            max_ele=arr[i];
        }
        find[max_ele]=1;
        int count,max_count=0;
        for(int i=0;i<n-1;i++)
        {
            if(max_count>=(n-i))
            break;
            if(find[arr[i]]==0 && arr[i]<=(max_ele/2))
            {
                find[arr[i]]=1;
                count=0;
                int second_max=arr[i+1];
                for(int j=i+1;j<n;j++)
                {
                    if(arr[j]%arr[i]==0)
                    count++;
                    if(arr[j]>second_max)
                    second_max=arr[j];
                }
                find[second_max]=1;
                if(count>max_count)
                max_count=count;
            }
        }
        cout<<max_count<<endl;
    }
    return 0;
}


#include <iostream>


void selection (int nums[], int n)
{
    int i,j, smallest;

    for(i = 0; i<n; ++i)
    {
        smallest = i;

        for(j = i; j <n; ++j)
        {
            if(nums[j] < nums[smallest])
            {
                smallest = j;
            }
        }

        int temp = nums[smallest];
        nums[smallest] = nums[i];
        nums[i] = temp;
    }
}

using namespace std;

int main()
{
    cout<<"Enter the size of the array"<<endl;
    int siz;
    cin>>siz;
    cout<<"Enter numbers: "<<endl;
    int arr[siz];

    for(int i=0; i<siz; ++i)
    {
        cin>>arr[i];
    }

    selection(arr,siz);

    for(int i= 0; i < siz; ++i)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
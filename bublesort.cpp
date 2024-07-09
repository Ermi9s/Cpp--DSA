#include <iostream>

using namespace std;

void buble_sort(int arr[] , int size)
{
    for(int i = size - 1; i >= 0; --i)
    {
        int temp;
        for(int j = 0; j<i; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    cout<<"Enter the size of the array"<<endl;
    int siz;
    cin>>siz;
    cout<<"Enter numbers: "<<endl;
    int nums[siz];

    for(int i=0; i<siz; ++i)
    {
        cin>>nums[i];
    }

    buble_sort(nums,siz);

    for(int i= 0; i < siz; ++i)
    {
        cout<<nums[i]<<" ";
    }


    return 0;
}


#include<bits/stdc++.h>

using namespace std;

void swaper(int *arr , int ind1, int ind2)
{
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

int pivot(int arr[] , int start , int end)
{
    int piv = start;
    int swap = piv;

    for(int j = piv + 1;j <= end; ++j)
    {
        if(arr[j] < arr[piv])
        {
            swap += 1;
            swaper(arr , swap , j);
        }
    }
    swaper(arr , piv , swap);

    return swap;
}

void Quick_Sort(int *arr , int start , int end)
{
    if(start < end)
    {
        int piv_ind = pivot(arr , start , end);
        Quick_Sort(arr , start , piv_ind -1);
        Quick_Sort(arr , piv_ind + 1 , end);
    }

}


int main()
{
    int arr[10] = {43,6,15,81,2,1,5,8,233,8};

    Quick_Sort(arr , 0 , 9);

    for(int x: arr)
    {
        cout<<x<<" ";
    }
    return 0;
}
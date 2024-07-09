#include <iostream>

void insertion(int nums[], int n)
{

    for(int i = 1 ; i < n; ++i){
        int temp = nums[i];
        int j = i;
        while(j > 0 && nums[j] < nums[j-1]){
            nums[j] = nums[j-1];
            nums[j-1] = temp;
            j--;
        }
    }

}

using namespace std;

int main()
{
    
    int arr[5] = {4,6,1,7,10};

    insertion(arr,5);

    for(int i= 0; i < 5; ++i)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
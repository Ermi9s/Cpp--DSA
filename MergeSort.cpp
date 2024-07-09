#include<bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int>arr1 , vector<int>arr2){
    int i = 0;
    int j = 0;
    vector<int>combo;

    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] <= arr2[j]){
            combo.push_back(arr1[i]);
            i++;
        }
        else if (arr2[j] < arr1[i]){
            combo.push_back(arr2[j]);
            j++;
        }
    }

    while(i < arr1.size()){
        combo.push_back(arr1[i]);
        i ++;
    }
    while(j < arr2.size()){
        combo.push_back(arr2[j]);
        j++;
    }

    return combo;
}

vector<int> mergeSort(vector<int>nums){
    if (nums.size() == 1){
        return nums;
    }
    int mid = nums.size()/2;
    vector<int> l (nums.begin()+0 , nums.begin()+mid);
    vector<int> r (nums.begin()+mid , nums.end());
    vector<int> left = mergeSort(l);
    vector<int> right = mergeSort(r);

    return merge(left , right);
}

int main()
{
    vector<int> arr = {43,6,15,81,2,1,5,8,233,8};

   

    for(int x: mergeSort(arr))
    {
        cout<<x<<" ";
    }
    return 0;
}

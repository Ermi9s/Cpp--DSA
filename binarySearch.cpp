int search(int key, int nums[],int n)
{
    int left = 0;
    int right = n -1;
    int mid;
    bool found = false;
    int index = -1;

    do
    {
        mid = (left + right)/2;

        if(nums[mid] == key)
        {
            found = true;
        }

        else if(key < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }

    }while(!found && left >= mid);

    if(found)
    {
        index = mid;
    }

    return index;
}
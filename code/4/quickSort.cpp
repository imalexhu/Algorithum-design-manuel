#include <bits/stdc++.h>
using namespace std;
int pivotPartition(vector<int> &nums, int left, int right, int p)
{
    int l = left;
    int r = right;
    while (l <= r)
    {
        // cout << l << " : " << r << endl;
        while (nums[l] < p)
        {
            // cout << "left " << nums[l] << " : " << p << endl;

            l++;
        }

        while (nums[r] > p)
        {
            // cout << "right " << nums[r] << " : " << p << endl;

            r--;
        }
        // cout << nums[l] << " : " << nums[r] << endl;

        if (l <= r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
    return l;
}

void quickSortHelper(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = nums[(start + end) / 2];
    int index = pivotPartition(nums, start, end, pivot);
    cout << "index : " << index << endl;
    quickSortHelper(nums, start, index-1);
    quickSortHelper(nums, index , end);
}
void quickSort(vector<int> &nums)
{
    quickSortHelper(nums, 0, nums.size() - 1);
}

int main()
{

    vector<int> nums = {4,3,2,1,3,4,5,1,3,5,34,1,23,45,5,312,3, 2};

    quickSort(nums);

    cout << " Final array" << endl;
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
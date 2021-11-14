#include <bits/stdc++.h>
using namespace std;

void mergeTwoArrays(vector<int> &nums, int start, int end)
{
    int middle = (start + end) / 2;
    int rightStart = middle + 1;
    cout << "Left start  : " << start << " left end : " << middle << endl;
    cout << "rightStart  : " << middle + 1 << " right end : " << end << endl;

    int l = start;
    int r = rightStart;
    vector<int> temp;

    while (l <= middle && r <= end)
    {
        cout << " L : " << nums[l] << " R : " << nums[r] << endl;
        if (nums[l] <= nums[r])
        {
            temp.push_back(nums[l]);
            l++;
        }
        else
        {
            temp.push_back(nums[r]);
            r++;
        }
    }

    if (r > end)
    {
        while (l <= middle)
        {
            temp.push_back(nums[l]);
            l++;
        }
    }
    else
    {
        while (r <= end)
        {
            temp.push_back(nums[r]);
            r++;
        }
    }


    int index = 0;
    for (int i = start; i <= end; i++)
    {
        nums[i] = temp[index];
        index++;
    }
}

void mergeSortActual(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int middle = (start + end) / 2;

    mergeSortActual(nums, start, middle);
    mergeSortActual(nums, middle + 1, end);

    mergeTwoArrays(nums, start, end);
}

void mergeSort(vector<int> &nums)
{
    mergeSortActual(nums, 0, nums.size() - 1);
}

int main()
{

    vector<int> nums = {4, 2, 5, 7, 3, 1, 3, 5, 6, 9, 3, 1};

    mergeSort(nums);

    cout << " Final array" << endl;
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
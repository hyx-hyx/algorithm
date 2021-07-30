#include<iostream>
#include<vector>
using namespace std;
int binary_search(vector<int> nums,int target)
{
	int right = nums.size() - 1;
	int left = 0;
	while (left <= right)
	{
		int mid=(left+right)/2;
		if (nums[mid] == target)
			return mid;
		else
		{
			if (nums[mid] > target)
				right = mid - 1;
			if(nums[mid]<target)
				left = mid + 1;
		}
	}
	return -1;
}
int left_bound(vector<int> nums, int target)
{
	int right = nums.size();
	int left = 0;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			right = mid;
		else
		{
			if (nums[mid] < target)
				left = mid+1;
			else
				right = mid;
		}
	}
	if (left == nums.size()) return -1;
	return left;
}
int right_bound(vector<int> nums, int target)
{
	int right = nums.size();
	int left = 0;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			left = mid + 1;
		else
		{
			if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
	}
	if (left == 0) return -1;
	return left;

}
int main()
{
	vector<int>arrays={1,2,3,4,6,8,19,23,45,67};
	int n;
	cin >> n;
	//cout<<binary_search(arrays,n)<<endl;
	cout << left_bound(arrays, n) << endl;
	cout << right_bound(arrays,n);
	return 0;
}
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int index = searchIndex(nums, 0, nums.size() - 1, target);
		vector<int> result;
		cout << index << endl;
		if (index == -1) {
			result.push_back(-1);
			result.push_back(-1);
			return result;

		}
		int x = (searchforward(nums, 0, index, target));
		int y = (searchbackward(nums, index, nums.size() - 1, target));
		if (true) {
			result.push_back(x);
			result.push_back(y);
		}
		//cout<<result;
		return result;

	}
	int searchforward(vector<int>& nums, int start, int end, int target) {

		int mid;
		if (start == end)
			return start;
		if (end - start == 1)
			if (nums[start] == target)
				return start;
			else
				return end;

		while (true) {
			mid = (start + end) / 2;
			if (mid - 1 < 0)
				return mid;
			if (nums[mid] == target) {
				if (nums[mid - 1] < nums[mid])
					return mid;
				else
					end = mid;
			} else if (nums[mid] < target) {
				start = mid + 1;
			} else if (nums[mid] >= target) {
				end = mid - 1;
			}

		}
		return -1;

	}
	int searchbackward(vector<int>& nums, int start, int end, int target) {

		int mid;
		if (start == end)
			return start;
		while (true) {
			mid = (start + end) / 2;
			if (mid == end)
				return mid;
			if (nums[mid] == target) {
				if (nums[mid + 1] > nums[mid])
					return mid;
				else
					start = mid + 1;
			} else if (nums[mid] <= target) {
				start = mid + 1;
			} else if (nums[mid] > target) {
				end = mid - 1;
			}

		}
		return -1;

	}
	int searchIndex(vector<int>& nums, int start, int end, int target) {
		int mid;
		while (start <= end) {
			mid = (start + end) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target) {
				start = mid + 1;
			} else if (nums[mid] > target) {
				end = mid - 1;
			}

		}
		return -1;

	}
};

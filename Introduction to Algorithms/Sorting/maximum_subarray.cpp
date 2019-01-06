// Time Complexity: O(n * log n)
#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> maxCrossSubArray(int arr[], int left, int mid, int right)
{
	int left_sum = INT_MIN, sum = 0, max_left;
	for(int i = mid; i >= left; i--)
	{
		sum += arr[i];
		if(left_sum < sum)
			left_sum = sum,	max_left = i;
	}
	int right_sum = INT_MIN, max_right;
	sum = 0;
	for(int i = mid+1; i <= right; i++)
	{
		sum += arr[i];
		if(right_sum < sum)
			right_sum = sum, max_right = i;
	}
	return make_tuple(max_left, max_right, left_sum+right_sum);
}

tuple<int, int, int> maxSubArray(int arr[], int left, int right)
{
	if(left == right)
		return make_tuple(left, right, arr[left]);
	else
	{
		int mid = (left+right) / 2;
		int left_min, left_max, left_sum, right_min, right_max, right_sum, cross_min, cross_max, cross_sum;
		tie(left_min, left_max, left_sum) = maxSubArray(arr, left, mid);
		tie(right_min, right_max, right_sum) = maxSubArray(arr, mid+1, right);
		tie(cross_min, cross_max, cross_sum) = maxCrossSubArray(arr, left, mid, right);

		if(left_sum >= right_sum && left_sum >= cross_sum)
			return make_tuple(left_min, left_max, left_sum);
		else if(right_sum >= left_sum && right_sum >= cross_sum)
			return make_tuple(right_min, right_max, right_sum);
		return make_tuple(cross_min, cross_max, cross_sum);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int start, end, sum;
	tie(start, end, sum) = maxSubArray(arr, 0, n-1);
	cout << start << " " << end << " " << sum << endl;
}
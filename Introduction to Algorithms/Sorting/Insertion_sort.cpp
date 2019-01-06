// Time Complexity: O(n^2)
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// insertion sort
	for(int i = 1; i < n; i++)
	{
		int key = arr[i], j;
		for(j = i-1; j >= 0; j--)
			if(arr[j] > key)
				arr[j+1] = arr[j];
		arr[j+1] = key;
	}

	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

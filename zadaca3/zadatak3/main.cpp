#include <iostream>
#include <vector>
#include <cstdlib>

// int lis(const std::vector<int>& nums) {
// // Binary search approach
// 	int n = nums.size();
// 	std::vector<int> ans;

// 	ans.reserve(nums.size());

// // Initialize the answer vector with the
// // first element of nums
// 	ans.push_back(nums[0]);

// 	for (int i = 1; i < n; i++) {
// 		if (nums[i] > ans.back()) {

// 			// If the current number is greater
// 			// than the last element of the answer
// 			// vector, it means we have found a
// 			// longer increasing subsequence.
// 			// Hence, we append the current number
// 			// to the answer vector.
// 			ans.push_back(nums[i]);
// 		} else {

// 			// If the current number is not
// 			// greater than the last element of
// 			// the answer vector, we perform
// 			// a binary search to find the smallest
// 			// element in the answer vector that
// 			// is greater than or equal to the
// 			// current number.

// 			// The lower_bound function returns
// 			// an iterator pointing to the first
// 			// element that is not less than
// 			// the current number.
// 			auto low = std::lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

// 			// We update the element at the
// 			// found position with the current number.
// 			// By doing this, we are maintaining
// 			// a sorted order in the answer vector.
// 			ans[low] = nums[i];
// 		}
// 	}

// 	for (const auto& el : ans) {
// 		std::cout << el << ' ';
// 	}

// 	std::cout << std::endl;

// // The length of the answer vector
// // represents the length of the
// // longest increasing subsequence.
// 	return ans.size();
// }

int lis(const std::vector<int>& v) {
	int n = v.size();
	std::vector<int> lis;
	lis.resize(n);
}

int main() {
	srand(time(NULL));
	std::vector<int> v;
	v.reserve(20);
	for (auto i = 0; i < 20; ++i) {
		v.push_back(rand() % 100 + 1);
	}

	for (const auto& el : v) {
		std::cout << el << ' ';
	}

	std::cout << std::endl;

	auto Lis = lis(v);

	std::cout << std::endl << "Najduza rastuca sekvenca iznosi: " << Lis << std::endl;

	return 0;
}
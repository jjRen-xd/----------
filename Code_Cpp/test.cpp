// 找出给定数组满足区间和大于等于给定值的最小子数组长度

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 暴力解法
int minSubArrayLen1(int s, vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += nums[j];
            if (sum >= s) {
                ans = min(ans, j - i + 1);
                break;
            }
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

// 双指针解法
int minSubArrayLen2(int s, vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    int ans = INT_MAX;
    int start = 0, end = 0;
    int sum = 0;
    while (end < n) {
        sum += nums[end];
        while (sum >= s) {
            ans = min(ans, end - start + 1);
            sum -= nums[start];
            start++;
        }
        end++;
    }
    return ans == INT_MAX ? 0 : ans;
}

int main() {
    int s = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen1(s, nums) << endl;
    cout << minSubArrayLen2(s, nums) << endl;
    return 0;
}
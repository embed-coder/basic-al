#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            unordered_map<int, int>::iterator it = map.find(nums[i]);
            if (it != map.end())
                return {it->second, i};
            else
                map.insert({target - nums[i], i});
        }
        return {};
    }
};

#ifndef RunTests
int main ()
{
    vector<int> test{2,7,11,15};
    // vector<int> test{3,2,4};
    // vector<int> test{3,3};
    int target = 9;

    Solution *sol = new Solution();
    vector<int> res = sol->twoSum(test, target);

    if (res.size() > 1)
        cout << "Result: " << res[0] << ", " << res[1] << endl;
    
    return 0;
}
#endif
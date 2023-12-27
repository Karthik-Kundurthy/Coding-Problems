class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        ret.push_back(-1);
        ret.push_back(-1);
        
        bool flag = false;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == target && !flag) {
                flag = true;
                ret[0] = i;
                ret[1] = i;
            } else if (nums[i] == target && flag) {
                ret[1] = i;
            }
        }
        
        return ret;
    }
};
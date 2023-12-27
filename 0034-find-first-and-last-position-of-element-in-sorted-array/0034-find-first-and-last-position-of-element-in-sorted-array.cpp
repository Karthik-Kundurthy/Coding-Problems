// practicing binary search and recursion in C++
class Solution {
public:
    
    //binary search solution
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = binarySearch(nums, target, 0, nums.size() - 1);
        // std::cout << idx << std::endl;
        vector<int> ret;
        ret.push_back(-1);
        ret.push_back(-1);
        if (idx == -1) {
            return ret;
        } 
        
        int i = idx;
        int j = idx;
        while (i >= 0 && nums[i] == target) {
            ret[0] = i;
            i--;
        }
        
        while (j < nums.size() && nums[j] == target) {
            ret[1] = j;
            j++;
        }
        
        return ret;
        
        
    }
    
    int binarySearch(vector<int>& nums, int target, int low, int high) {
        // avoid infinite loop
        if (low <= high) {
            int mid = (low + high)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                return binarySearch(nums, target, mid + 1, high);
            } else if (nums[mid] > target) {
                return binarySearch(nums, target, low, mid - 1);
            }  
        }
        
        return -1;
    } 
    
    // initially gave linear solution
    vector<int> linearSearchRange(vector<int>& nums, int target) {
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
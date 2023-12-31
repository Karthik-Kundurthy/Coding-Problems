class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        // maintain a count 
        int count = 0;
        
        //  index to update
        int set_idx = 0;
    
        int i = 0;
        while (i < nums.size())  {
            int ele = nums[i];
            if (ele == val) {
                // want to move i past this 
                i++;
            } else {
                // ret val
                count++;
                // update the curr position in the array
                nums[set_idx] = ele;
                // increments
                set_idx++;
                i++;
            }
        }
        
        return count;
        
    }
};


// for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] != val) {
        //         count++;
        //     }
        //     if (nums[i] == val) {
        //         nums[i] = -1;
        //         set_idx = i;
        //     } else if (set_idx != -1) {
        //         nums[set_idx] = nums[i];
        //         // nums[i] = -1;
        //     } 
        // }
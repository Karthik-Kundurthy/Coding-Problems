class Solution {
public:
    // O(n) time and space
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // hashmap in C++
        std::unordered_map<int, int> map; 
        
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) {
                cout << "hello there" << endl;
                // prints iterator, gives compile error, need to get the value itself
                // cout << map.find(nums[i]) << endl;
                return {i, map[nums[i]]};
            } else {
                map[target - nums[i]] = i;
            }
        }
        
        // printing the map, commented out to improve runtime
        // for (const auto& pair : map) {
        //     std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        // }

        // default
        return {-1, -1};
    }
};
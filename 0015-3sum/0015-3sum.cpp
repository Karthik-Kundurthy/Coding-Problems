class Solution {
public:
    // working with structs
    struct Triplet {
        vector<int> vals = {0, 0, 0};
        
        // Using user defined data type as a key, so need to have a bool operator as basis of comparision
        bool operator<(const Triplet& t2) const {
            // Compare each element of vals
            for (int i = 0; i < 3; ++i) {
                if (vals[i] < t2.vals[i]) return true;
                if (vals[i] > t2.vals[i]) return false;
            }
            return false;  // Equal
        } 

    };

    
    // overall time complexity, sorting, iterating through n elements, for each element doing another O(n) operation to get all pairs -> O(n^2) 
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        // global array passed to every two sum invocation
        std::vector<vector<int>> triplets;
        
        
        
        // // visited set -- get this to work later
        // std::unordered_map<Triplet, int> visited;
        
        // start by sorting
        std::sort(nums.begin(), nums.end());
        
        // Printing the vector elements using std::copy and ostream_iterator
        std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        // iterate, skip outer loop duplicates
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                twoSum(nums, -nums[i], triplets, i);  
            }
            
        }
        
        // return
        return triplets;
        
    }
    
    void twoSum(vector<int>& nums, int target, std::vector<vector<int>>& triplets, int curr_idx) {
        // starting at curr to avoid duplicate triplets like 1, 2, -3 and -3, 1, 2
        int j = curr_idx + 1;
        int k = nums.size() - 1;
        
        while (j < k) {
            if (nums[j] + nums[k] < target) {
                j++;
            } else if (nums[j] + nums[k] > target) {
                k--;
            } else {
                Triplet t;
                t.vals[0] = nums[curr_idx];
                t.vals[1] = nums[j];
                t.vals[2] = nums[k];
                
                // Skip duplicates in the inner loop
                while (j < k && nums[j] == nums[j + 1]) {
                    j++;
                }
                while (j < k && nums[k] == nums[k - 1]) {
                    k--;
                }
                triplets.push_back(t.vals);
                j++;
                k--;
                
//                 // ensure triplet not already in list, will get visited set to work later
//                 bool flag = false;
//                 for (int i = 0; i < triplets.size(); i++) {
//                     vector<int> curr = triplets[i];
//                     if (t.vals[0] == curr[0] && t.vals[1] != curr[1] && t.vals[0] != curr[1]) {
//                         flag = true;
//                         break;
//                     }
//                 }
//                 if (!flag) {
//                     triplets.push_back(t.vals);
                    
//                 }
                
                
                
            
            }
        }
         
        // std::copy(triplets.begin(), triplets.end(), std::ostream_iterator<int>(std::cout, " "));
        // std::cout << std::endl;
        // std::cout << nums[curr_idx] << std::endl;
    }
};

// // Default constructor
        // Triplet() = default;
        // // Constructor to initialize values
        // Triplet(int a, int b, int c) : vals{a, b, c} {}
        // // Equality operator for unordered_map
        // bool operator==(const Triplet& other) const {
        //     return vals == other.vals;
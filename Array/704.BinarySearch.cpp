class Solution {
    public:
        /**
         * @brief Finds the target in a sorted array using Binary Search (Closed Interval [l, r] approach).
         * @param nums The sorted array of integers.
         * @param target The value to search for.
         * @return The index of the target if found, otherwise -1.
         */
        int search(std::vector<int>& nums, int target) {
            int n = nums.size();
            int l = 0;
            int r = n - 1; 
            // [l, r] defines the search range where both boundaries are inclusive.
            // We use l <= r because when l == r, there is still one element to check.
            while(l <= r){
                // Calculate the middle index 'm'. This formula prevents integer overflow
                int m = l + (r - l) / 2; 
                
                if (nums[m] < target){  
                    // Target is on the right side. The element at index m is too small, 
                    l = m + 1;
                }
                else if (nums[m] > target){ 
                    // Target is on the left side. The element at index m is too large, 
                    r = m - 1;
                }
                else{
                    return m;
                }
            }
            return -1;
        }
    };
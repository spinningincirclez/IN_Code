#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // vector<int> sumIdx(2,-1);

        // Brute force method (nested for loops)
        // for (int i = 0; i < nums.size(); i++) { // For each index of the vector...
        //     for (int j = i+1; j < nums.size(); j++) // Compare the sums of each index after that point
        //         if (nums[i] + nums[j] == target) {
        //             sumIdx[0] = i;
        //             sumIdx[1] = j;
        //         }
        // }

        int compliment;
        unordered_map<int, int> idxMap; // unordered <Key, Value> <Value = Key, Index = Value>

        // Less agressive method
        for (int i = 0; i < nums.size(); i++) { // Only 1 for loop, O(n);
            compliment = target - nums[i]; // Search for the compliment

            if (idxMap.find(compliment) != idxMap.end()) { // Lookup time is O(1)
                return {idxMap[compliment], i};
            }

            idxMap[nums[i]] = i; // Add this to the map for safekeeping later.
        }

        return {}; // Return empty if no solution exists

    }
};

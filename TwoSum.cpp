class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        // Maintain a map of elements and their original index
        unordered_map<int, int> elemIndex;
        
        for (int i = 0; i < nums.size(); i++)
        {
            elemIndex[nums[i]] = i;
        }
        
        
        // now get the first element and binary search for sum - elem
        for (int i = 0; i < nums.size(); i++)
        {
            int elemToFind = target - nums[i];
            int index2 = 0;
            if(elemIndex.find(elemToFind)!=elemIndex.end() && (index2 = elemIndex.find(elemToFind)->second) != i)
            {
                result.push_back(i+1);
                result.push_back(index2+1);

            return result;
            }
            
        }
        
        return result;
        
    }
};

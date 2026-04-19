class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # make a hashmap that contains the compliment and the index
        seen = {}
        # loop through every number in the list
        for i in range(len(nums)):
            # calculate the compliment
            comp = target - nums[i]
            # check if this compiment exists in the hashmap
            if comp in seen:
                # if yes, return. found the pair of indexes
                return [seen[comp], i]
            # if not put it in the seen record
            seen[nums[i]]= i
        # if nothing found, return none
        return None
    
        
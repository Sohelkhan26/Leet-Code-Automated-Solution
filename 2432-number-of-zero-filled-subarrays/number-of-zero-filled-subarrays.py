class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans , zero , n = 0 , 0 , len(nums)
        for num in nums:
            zero = zero + 1 if num == 0 else 0
            ans += zero
        return ans
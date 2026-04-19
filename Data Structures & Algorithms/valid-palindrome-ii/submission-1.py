class Solution:
    def validPalindrome(self, s: str) -> bool:
        freq = {}
        odd_counter = 0
        for c in s:
            if c not in freq:
                freq[c] = 1
            else:
                freq[c] += 1
                if freq[c] % 2 == 0:
                    odd_counter -= 1
                else:
                    odd_counter += 1
        return odd_counter <= 1
        
# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def insertionSort(self, pairs: List[Pair]) -> List[List[Pair]]:
        answer = []
        answer.append(pairs[:])
        if len(pairs) == 0: return pairs
        for i in range(1, len(pairs)): 
            j = i - 1 
            # answer.append(pairs[:]) 
            while j >= 0 and pairs[j+1].key < pairs[j].key: 
                pairs[j], pairs[j+1] = pairs[j+1], pairs[j]
                j -= 1 
                # answer.append(pairs[:])
            answer.append(pairs[:]) 
        return answer
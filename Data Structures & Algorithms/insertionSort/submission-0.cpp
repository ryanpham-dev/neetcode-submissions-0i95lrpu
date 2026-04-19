// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> output;
        output.push_back(pairs);
        for (int i = 1; i < pairs.size(); i++) {
            int ckey = pairs[i].key;
            int j = i - 1;
            int pkey = pairs[j].key;
            while(j >=0 && ckey < pkey) {
                pairs[j + 1].key = pkey;
                j--;
                pkey = pairs[j].key;
            }
            pairs[j+1].key = ckey;
            output.push_back(pairs);
        }
        return output;
    }
};

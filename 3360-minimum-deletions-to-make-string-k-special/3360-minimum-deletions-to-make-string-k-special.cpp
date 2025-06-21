class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> charFreq;
        for (char c : word) {
            charFreq[c]++;
        }

        vector<int> frequencies;
        for (auto& pair : charFreq) {
            frequencies.push_back(pair.second);
        }
        sort(frequencies.rbegin(), frequencies.rend());

        int minDeletions = INT_MAX;
        for (int i = 0; i < frequencies.size(); i++) {
            int temp = frequencies[i];
            int deletions = 0;
            for (int f : frequencies) {
                if (f > temp + k) {
                    deletions += f - (temp + k);
                }
                else if (f < temp) {
                    deletions += f;
                }
            }
            minDeletions = min(minDeletions, deletions);
            if (minDeletions == 0) {
                break;
            }
        }
        return minDeletions;
    }
};
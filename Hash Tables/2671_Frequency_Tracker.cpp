class FrequencyTracker {
    unordered_map<int, int> freq;   
    unordered_map<int, int> count;  

public:
    FrequencyTracker() {}

    void add(int number) {
        if (freq[number] > 0) {
            count[freq[number]]--;
        }
        freq[number]++;
        count[freq[number]]++;
    }

    void deleteOne(int number) {
        if (freq[number] > 0) {
            count[freq[number]]--;
            freq[number]--;
            if (freq[number] > 0) {
                count[freq[number]]++;
            }
        }
    }

    bool hasFrequency(int frequency) {
        return count[frequency] > 0;
    }
};

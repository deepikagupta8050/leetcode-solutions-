class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> groups;
    int maxFreq = 0;

    FreqStack() {
    }

    void push(int val) {
        freq[val]++;
        int f = freq[val];

        maxFreq = max(maxFreq, f);

        groups[f].push_back(val);
    }

    int pop() {
        int val = groups[maxFreq].back();
        groups[maxFreq].pop_back();

        freq[val]--;

        if (groups[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};
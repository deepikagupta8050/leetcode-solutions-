class DataStream {
public:
    int value, k;
    int count;

    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        count = 0;
    }

    bool consec(int num) {
        if (num == value)
            count++;
        else
            count = 0;

        return count >= k;
    }
};
class RandomizedSet {
private:
    unordered_map<int, int> valToIndex;
    vector<int> values;
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valToIndex.count(val))
            return false;
        values.push_back(val);
        valToIndex[val] = values.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!valToIndex.count(val))
            return false;

        int lastVal = values.back();
        int valIndex = valToIndex[val];
        values[valIndex] = lastVal;
        valToIndex[lastVal] = valIndex;
        values.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }
};
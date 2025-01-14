class RandomizedSet {
private:
    std::vector<int> nums;
    std::unordered_map<int, int> numToIndex;

public:
    RandomizedSet() {
        srand(time(0));
    }

    bool insert(int val) {
        if (numToIndex.find(val) != numToIndex.end()) {
            return false;
        }
        numToIndex[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (numToIndex.find(val) == numToIndex.end()) {
            return false;
        }
        int index = numToIndex[val];
        int last = nums.back();
        nums[index] = last;
        numToIndex[last] = index;
        nums.pop_back();
        numToIndex.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
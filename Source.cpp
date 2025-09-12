import std;
using namespace std;
bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> duplicate;
        for (auto num : nums) {
            if (duplicate.count(num)) {
                return true;
            }
            duplicate.insert(num);
        }
        return false;
    }

int main() {
    vector<int>nums = { 1,1,3,4 };
    if (containsDuplicate(nums))
        println("Contains Duplicate");

    return 0;
}



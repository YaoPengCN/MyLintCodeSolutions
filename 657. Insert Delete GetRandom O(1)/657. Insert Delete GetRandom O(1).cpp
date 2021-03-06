/** 
 * 657. Insert Delete GetRandom O(1)
 * Difficulty
 * Medium
 * 
 * Description
 * Design a data structure that supports all following operations in average O(1) time. 
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 * 
 *  Example
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 * // Since 2 is the only number in the set, getRandom always return 2.
 * randomSet.getRandom();
 * 
 * Related Problems
 * 954. Insert Delete GetRandom O(1) - Duplicates allowed
 * */

/**
 * Array + HashMap
 * Ref[1]: https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247487414&idx=1&sn=2be87c0c9279da447f8ac8b8406230fe
 * Ref[2]: https://www.jiuzhang.com/problem/insert-delete-getrandom-o1/#tag-lang-cpp
 * Running Time: - ms
 */

class RandomizedSet
{
public:
    RandomizedSet()
    {
        srand(time(NULL));
        n = 0;
    }

    /*
     * @param val: a value to the set
     * @return: true if the set did not already contain the specified element or false
     */
    bool insert(int val)
    {
        if (valToIndex.find(val) == valToIndex.end())
        {
            if (n < nums.size())
            {
                nums[n] = val;
            }
            else
            {
                nums.push_back(val);
            }
            valToIndex[val] = n;
            n++;
            return true;
        }
        return false;
    }

    /*
     * @param val: a value from the set
     * @return: true if the set contained the specified element or false
     */
    bool remove(int val)
    {
        if (valToIndex.find(val) != valToIndex.end())
        {
            nums[valToIndex[val]] = nums[n - 1];
            valToIndex[nums[n - 1]] = valToIndex[val];
            n--;
            valToIndex.erase(val);
            return true;
        }
        return false;
    }

    /*
     * @return: Get a random element from the set
     */
    int getRandom()
    {
        if (nums.size())
            return nums[rand() % nums.size()];
        else
        {
            return 0;
        }
    }

private:
    vector<int> nums;
    unordered_map<int, int> valToIndex;
    int n;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */

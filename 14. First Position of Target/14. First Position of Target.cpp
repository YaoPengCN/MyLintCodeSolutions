/** 
* 14. First Position of Target
* Difficulty
* Easy
* 
* Description
* For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.
* If the target number does not exist in the array, return -1.
* 
* Example
* Example 1
* Input:  [1,4,4,5,7,7,8,9,9,10]，1
* Output: 0
* Explanation: the first index of  1 is 0.
* 
* Example 2
* Input: [1, 2, 3, 3, 4, 5, 10]，3
* Output: 2
* Explanation: the first index of 3 is 2.
* 
* Example 3
* Input: [1, 2, 3, 3, 4, 5, 10]，6
* Output: -1
* Explanation: not exist 6 in array.
*
* Challenge
* If the count of numbers is bigger than 2^32, can your code work properly?

* Related Problems 
* 459. Closest Number in Sorted Array
* 458. Last Position of Target
* 457. Classical Binary Search
* 447. Search in a Big Sorted Array
* 163. Unique Binary Search Trees
* 141. Sqrt(x)
* 11. Search Range in Binary Search Tree
*/

/**
 * Challenge: If the count of numbers is bigger than 2^32, can your code work properly?
 * Run Time: 403ms
 */
class Solution
{
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target)
    {
        vector<int>::size_type left, right;
        left = 0;
        right = nums.size() - 1;

        if (nums.empty())
            return -1;

        if (nums[left] == target)
            return left;

        while (left < right - 1)
        {
            vector<int>::size_type mid = left + (right - left) / 2;
            if (nums[mid] == target)
                right = mid;
            if (nums[mid] < target)
                left = mid;
            else
                right = mid;
        }

        if (nums[left] == target)
            return left;
        else if (nums[right] == target)
                return right;
            else
                return -1;
    }
};

// /**
//  * Run Time: 406ms
//  */
// class Solution
// {
// public:
//     /**
//      * @param nums: The integer array.
//      * @param target: Target to find.
//      * @return: The first position of target. Position starts from 0.
//      */
//     int binarySearch(vector<int> &nums, int target)
//     {
//         vector<int>::size_type left, right;
//         left = 0;
//         right = nums.size() - 1;

//         if (nums.empty())
//             return -1;

//         if (nums[left] == target)
//             return left;

//         while (left < right - 1)
//         {
//             vector<int>::size_type mid = left + (right - left) / 2;
//             if (nums[mid] == target)
//                 right = mid;
//             if (nums[mid] < target)
//                 left = mid;
//             else
//                 right = mid;
//         }

//         if (nums[left] == target)
//             return left;
//         else if (nums[right] == target)
//                 return right;
//             else
//                 return -1;
//     }
// };
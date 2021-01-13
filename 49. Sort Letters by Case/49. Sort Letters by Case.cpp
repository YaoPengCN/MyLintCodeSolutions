/** 
 * 49. Sort Letters by Case
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * Given a string which contains only letters. 
 * Sort it by lower case first and upper case second.
 * 
 * Clarification
 * It's NOT necessary to keep the original order of lower-case letters and upper case letters.
 * 
 * Example
 * Example 1
 * Input:  "abAcD"
 * Output:  "acbAD"
 * 
 * Example 2
 * Input: "ABC"
 * Output:  "ABC"
 * 
 * Challenge
 * Do it in one-pass and in-place.
 *
 * Related Problems 
 * 1025. Custom Sort String
 * 769. Spiral Array
 * 761. Smallest Subset
 * 625. Partition Array II
 * 373. Partition Array by Odd and Even
 * 144. Interleaving Positive and Negative Numbers 
 * 96. Partition List
 * 31. Partition Array
 * */

/**
 * Challenge:
 * Do it in one-pass and in-place.
 * 
 * Double pointers based on quick sort
 * 
 * Running Time:  359ms
 */

class Solution
{
public:
    /*
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
    void sortLetters(string &chars)
    {
        if (chars.empty() || chars.size() == 1)
            return;

        int left = 0, right = chars.size() - 1;
        while (left <= right)
        {
            while (left <= right && islower(chars[left]))
            {
                left++;
            }
            while (left <= right && isupper(chars[right]))
            {
                right--;
            }

            if (left <= right)
            {
                swap(chars[left], chars[right]);
                left++;
                right--;
            }
        }
    }
};
/** 
 * 133. Longest Word
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * Given a dictionary, find all of the longest words in the dictionary.
 * 
 * Example
 * Example 1
 * Input: 
 *  {
 * 	"dog",
 * 	"google",
 * 	"facebook",
 * 	"internationalization",
 * 	"blabla"
 * 	}
 * Output: ["internationalization"]
 * 
 * Example 2:
 * Input:
 *  {
 * 	"like",	
 *  "love",
 *  "hate",
 * 	"yes"
 *  }
 * 	Output: ["like", "love", "hate"]
 * 
 * Challenge
 * It's easy to solve it in two passes.
 * Can you do it in one pass?
 *  
 * Related Problems
 * 422. Length of Last Word
 */

/**
 * Running Time: 354ms
 */

class Solution
{
public:
    /*
     * @param dictionary: an array of strings
     * @return: an arraylist of strings
     */
    vector<string> longestWords(vector<string> &dictionary)
    {

        if (dictionary.empty())
            return {};

        vector<string> res;

        auto maxLength = dictionary[0].size();
        for (auto word : dictionary)
        {
            if (maxLength < word.size())
            {
                maxLength = word.size();
                res.clear();
                res.push_back(word);
            }
            else if (maxLength == word.size())
                res.push_back(word);
        }
        return res;
    }
};
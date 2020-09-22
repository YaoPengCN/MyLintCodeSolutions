/** 
* 9. Fizz Buzz
* Difficulty
* Easy
* 
* Description
* Given number n. Print number from 1 to n. But:
* · when number is divided by 3, print "fizz".
* · when number is divided by 5, print "buzz".
* · when number is divided by both 3 and 5, print "fizz buzz".
* · when number can't be divided by either 3 or 5, print the number itself.
*
* Example
* If n = 15, you should return:
* [
*   "1", "2", "fizz",
*   "4", "buzz", "fizz",
*   "7", "8", "fizz",
*   "buzz", "11", "fizz",
*   "13", "14", "fizz buzz"
* ]
* 
* If n = 10, you should return:
* [
*   "1", "2", "fizz",
*   "4", "buzz", "fizz",
*   "7", "8", "fizz",
*   "buzz"
* ]
* 
* Challenge
* Can you do it with only one if statement?

* Related Problems 
* 766. Leap Year
* 765. Valid Triangle
*/

/**
 * Challenge: Can you do it with only one if statement?
 * Run Time: 50 ms
 */
class Solution {
public:
    /**
     * @param n: An integer
     * @return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        vector<string> results;
        for ( size_t i = 1; i <= n; i++ )
        {
            (i % 15 == 0)  ? results.push_back("fizz buzz") : (i % 5 == 0)  ? results.push_back("buzz") :  (i % 3 == 0)  ? results.push_back("fizz") : results.push_back(to_string(i));
        }
        return results;
    }
};

// /**
//  * Run Time: 50 ms
//  */
// class Solution {
// public:
//     /**
//      * @param n: An integer
//      * @return: A list of strings.
//      */
//     vector<string> fizzBuzz(int n) {
//         vector<string> results;
//         for (int i = 1; i <= n; i++){
//             if ( i % 15 == 0){
//                 results.push_back("fizz buzz");
//             }
//             else if ( i % 5 == 0){
//                 results.push_back("buzz");
//             }
//             else if (i % 3 == 0){
//                 results.push_back("fizz");
//             }
//             else {
//                 results.push_back(to_string(i));
//             }
//         }
//         return results;
//     }
// };

/** 
 * 1509. Lemonade Change
 * 
 * Difficulty
 * Easy
 * 
 * Description
 * At a lemonade stand, each lemonade costs $5.
 * Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).
 * Each customer will only buy one lemonade and pay with either a $5, $10, or $20bill. 
 * You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.
 * Note that you don't have any change in hand at first.
 * Return true if and only if you can provide every customer with correct change.
 * 
 * Clarification
 * 0 <= bills.length <= 10000
 * bills[i] is 5 or 10 or 20
 * 
 * Example
 * Example 1
 * Input: bills = [5,5,5,10,20]
 * Output: true
 * Explanation: 
 * From the first 3 customers, we collect three $5 bills in order.
 * From the fourth customer, we collect a $10 bill and give back a $5.
 * From the fifth customer, we give a $10 bill and a $5 bill.
 * Since all customers got correct change, we output true.
 * 
 * Example 2:
 * Input: bills = [5,5,10,10,20]
 * Output: false
 * Explanation: 
 * From the first two customers in order, we collect two $5 bills.
 * For the next two customers in order, we collect a $10 bill and give back a $5 bill.
 * For the last customer, we can't give change of $15 back because we only have two $10 bills.
 * Since not every customer received correct change, the answer is false. 
 */

/** 
 * Running Time: 50ms
 */
class Solution
{
public:
    /**
     * @param bills: the Bill
     * @return: Return true if and only if you can provide every customer with correct change.
     */
    bool lemonadeChange(vector<int> &bills)
    {
        if (bills.size() == 0)
            return true;
        int count5 = 0, count10 = 0;
        for (vector<int>::size_type i = 0; i != bills.size(); i++)
        {
            switch (bills[i])
            {
            case 5:
                count5++;
                break;
            case 10:
                count5--;
                count10++;
                break;
            case 20:
                if (count10 > 0)
                {
                    count10--;
                    count5--;
                }
                else
                {
                    count5 -= 3;
                }
                break;
            default:
                return false;
            }
            if (count5 < 0)
                return false;
        }
        return true;
    }
};
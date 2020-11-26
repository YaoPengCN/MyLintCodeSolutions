/** 
 * 1264. Perfect Rectangle
 * 
 * Difficulty
 * Hard
 * 
 * Description
 * Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.
 * Each rectangle is represented as a bottom-left point and a top-right point. 
 * For example, a unit square is represented as [1,1,2,2]. 
 * (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2))
 *
 * Example
 * Input：
 * rectangles = 
 * [[1,1,3,3],
 *  [3,1,4,2],
 *  [3,2,4,4],
 *  [1,3,2,4],
 *  [2,3,3,4]]
 * Output：
 * true
 * Explanation：
 * All 5 rectangles together form an exact cover of a rectangular region.
 * 
 * Example 2
 * Input：
 * rectangles = 
 * [[1,1,2,3],
 *  [1,3,2,4],
 *  [3,1,4,2],
 *  [3,2,4,4]]
 * Output：
 * false
 * Explanation：
 * Because there is a gap between the two rectangular regions.
 * 
 * Example 3
 * Input：
 * rectangles = 
 * [[1,1,3,3],
 *  [3,1,4,2],
 *  [1,3,2,4],
 *  [3,2,4,4]]
 * Output：
 * false
 * Explanation：
 * Because there is a gap in the top center.
 * 
 * Example 4
 * Input：
 * rectangles = 
 * [[1,1,3,3],
 *  [3,1,4,2],
 *  [1,3,2,4],
 *  [2,2,4,4]]
 * Output：
 * false
 * Explanation：
 * Because two of the rectangles overlap with each other.
 */

/**
 * Ref[1]: https://mp.weixin.qq.com/s/PL7h_5hx6XZ1hEyVVusRBA
 * Ref[2]: https://www.jiuzhang.com/problem/perfect-rectangle/#tag-lang-cpp
 * Running Time: 50ms
 */

class Solution
{
public:
	/**
     * @param rectangles: N axis-aligned rectangles
     * @return: if they all together form an exact cover of a rectangular region
     */
	bool isRectangleCover(vector<vector<int>> &rectangles)
	{
		unordered_map<string, int> hash;
		for (auto val : rectangles)
		{
			//枚举四个顶点
			for (int i = 0; i < 4; i++)
			{		
				//字符串保存坐标																		  
				string tem = to_string(val[i / 2 * 2]) + ',' + to_string(val[i % 2 * 2 + 1]); 

				// 第i位置1后与hash[tem]做与运算。
				if (hash[tem] & (1 << i)) 
				{ 
					//如果当前点在其他矩形的同样顶点位置出现
					return false;
				}
				//将当前点在该矩形的此处顶点位置计入
				hash[tem] |= (1 << i); //第i位置1后与hash[tem]相加
			}
		}

		// 顶点数。矩形只有4个顶点。这4个顶点各自仅在所有子矩形中出现1次。
		int cntCorner = 0;
		for (auto &val : hash)
		{
			int sec = val.second;
			if (!(sec & (sec - 1)) && cntCorner++ > 4)
			{ 
				//如果cntCorner(顶点数)大于4
				return false;
			}
			if ((sec & (sec - 1)) && !(sec == 3 || sec == 12 || sec == 5 || sec == 10 || sec == 15))
			{ 
				//3,12,5,10,15分别代表该点出现2次和4次
				// 画示意图可以知道，如果该点出现2次或4次，那么它不会是最后形成的多边形的顶点。
				return false;
			}
		}
		return true;
	}
};
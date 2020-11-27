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
 * If the covered rectangle only has 4 corners，the covered rectangle is a perfect rectangle
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
		if (rectangles.empty() || rectangles.size() == 1)
			return true;

		// "hash" records the appearacne times of each coordinate.
		// unordered_map could not hash vector<int> directly
		// so convert vector<int> to string
		unordered_map<string, int> hash;

		for (vector<vector<int>>::size_type i = 0; i != rectangles.size(); i++)
		{
			// rectangles[i] = [x0, y0, x1, y1]
			// hash[x0, y0]++
			string tem = to_string(rectangles[i][0]) + ',' + to_string(rectangles[i][1]);
			hash[tem]++;

			// hash[x1, y1]++
			tem = to_string(rectangles[i][2]) + ',' + to_string(rectangles[i][3]);
			hash[tem]++;

			// hash[x0, y1]++
			tem = to_string(rectangles[i][0]) + ',' + to_string(rectangles[i][3]);
			hash[tem]++;

			// hash[x1, y0]++
			tem = to_string(rectangles[i][2]) + ',' + to_string(rectangles[i][1]);
			hash[tem]++;
		}

		// the covered rectangle should only have 4 corners
		// each corner only appears once in all the single rectangles.
		int corner = 0;
		for (auto &item : hash)
		{
			if ((item.second) == 1)
				corner++;
			if (corner > 4)
				return false;
		}

		// if the covered rectangle only has 4 corners，
		// the covered rectangle is a perfect rectangle
		return true;
	}
};

// /**
//  * Ref[1]: https://mp.weixin.qq.com/s/PL7h_5hx6XZ1hEyVVusRBA
//  * Ref[2]: https://www.jiuzhang.com/problem/perfect-rectangle/#tag-lang-cpp
//  * Running Time: 50ms
//  */

// class Solution
// {
// public:
// 	/**
//      * @param rectangles: N axis-aligned rectangles
//      * @return: if they all together form an exact cover of a rectangular region
//      */
// 	bool isRectangleCover(vector<vector<int>> &rectangles)
// 	{
// 		if (rectangles.empty() || rectangles.size() == 1)
// 			return true;

// 		// "areaSum" records the sum of the area of the single rectangles
// 		int areaSum = 0;
// 		// "cover" records the coordinates of the covered rectangle
// 		// cover = [x0, y0, x1, y1]
// 		vector<int> cover = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};

// 		// "hash" records the appearacne times of each coordinate.
// 		// unordered_map could not hash vector<int> directly
// 		// so convert vector<int> to string
// 		unordered_map<string, int> hash;

// 		for (vector<vector<int>>::size_type i = 0; i != rectangles.size(); i++)
// 		{
// 			areaSum += area(rectangles[i]);

// 			cover[0] = min(cover[0], rectangles[i][0]);
// 			cover[1] = min(cover[1], rectangles[i][1]);
// 			cover[2] = max(cover[2], rectangles[i][2]);
// 			cover[3] = max(cover[3], rectangles[i][3]);

// 			// rectangles[i] = [x0, y0, x1, y1]
// 			// hash[x0, y0]++
// 			string tem = to_string(rectangles[i][0]) + ',' + to_string(rectangles[i][1]);
// 			hash[tem]++;

// 			// hash[x1, y1]++
// 			tem = to_string(rectangles[i][2]) + ',' + to_string(rectangles[i][3]);
// 			hash[tem]++;

// 			// hash[x0, y1]++
// 			tem = to_string(rectangles[i][0]) + ',' + to_string(rectangles[i][3]);
// 			hash[tem]++;

// 			// hash[x1, y0]++
// 			tem = to_string(rectangles[i][2]) + ',' + to_string(rectangles[i][1]);
// 			hash[tem]++;
// 		}

// 		// the sum of the areas should be equal to the area of the coverd rectangle
// 		if (areaSum != area(cover))
// 			return false;

// 		// the covered rectangle should only have 4 corners
// 		// each corner only appears once in all the single rectangles.
// 		int corner = 0;
// 		for (auto &item : hash)
// 		{
// 			if ((item.second) == 1)
// 				corner++;
// 			if (corner > 4)
// 				return false;
// 		}

// 		// if 1. the sum of the areas equals to the area of the coverd rectangle
// 		// 2.  the covered rectangle only has 4 corners
// 		// the covered rectangle is a perfect rectangle
// 		return true;
// 	}

// private:
// 	int
// 	area(vector<int> coordinates)
// 	{
// 		// coordinates[x0, y0, x1, y1]
// 		// area = (x1 - x0) * (y1 - y0)
// 		return (coordinates[3] - coordinates[1]) * (coordinates[2] - coordinates[0]);
// 	}
// };

// /**
//  * Ref[1]: https://mp.weixin.qq.com/s/PL7h_5hx6XZ1hEyVVusRBA
//  * Ref[2]: https://www.jiuzhang.com/problem/perfect-rectangle/#tag-lang-cpp
//  * Running Time: 50ms
//  */

// class Solution
// {
// public:
// 	/**
//      * @param rectangles: N axis-aligned rectangles
//      * @return: if they all together form an exact cover of a rectangular region
//      */
// 	bool isRectangleCover(vector<vector<int>> &rectangles)
// 	{
// 		unordered_map<string, int> hash;
// 		for (auto val : rectangles)
// 		{
// 			//枚举四个顶点
// 			for (int i = 0; i < 4; i++)
// 			{
// 				//字符串保存坐标
// 				string tem = to_string(val[i / 2 * 2]) + ',' + to_string(val[i % 2 * 2 + 1]);

// 				// 第i位置1后与hash[tem]做与运算。
// 				if (hash[tem] & (1 << i))
// 				{
// 					//如果当前点在其他矩形的同样顶点位置出现
// 					return false;
// 				}
// 				//将当前点在该矩形的此处顶点位置计入
// 				hash[tem] |= (1 << i); //第i位置1后与hash[tem]相加
// 			}
// 		}

// 		// 顶点数。矩形只有4个顶点。这4个顶点各自仅在所有子矩形中出现1次。
// 		int cntCorner = 0;
// 		for (auto &val : hash)
// 		{
// 			int sec = val.second;
// 			if (!(sec & (sec - 1)) && cntCorner++ > 4)
// 			{
// 				//如果cntCorner(顶点数)大于4
// 				return false;
// 			}
// 			if ((sec & (sec - 1)) && !(sec == 3 || sec == 12 || sec == 5 || sec == 10 || sec == 15))
// 			{
// 				//3,12,5,10,15分别代表该点出现2次和4次
// 				// 画示意图可以知道，如果该点出现2次或4次，那么它不会是最后形成的多边形的顶点。
// 				return false;
// 			}
// 		}
// 		return true;
// 	}
// };
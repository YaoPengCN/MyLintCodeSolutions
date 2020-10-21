/** 
 * 1062. Flood Fill
 * Difficulty
 * Easy
 * 
 * Description
 * An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
 * Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
 * To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
 * plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. 
 * Replace the color of all of the aforementioned pixels with the newColor.
 * At the end, return the modified image.
 * 
 * Clarification
 * The length of image and image[0] will be in the range [1, 50].
 * The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
 * The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
 *
 * Example
 * Example 1
 * Input:
 * image = [[1,1],[0,0]]
 * sr = 0, sc = 0, newColor = 2
 * Output: [[2,2],[0,0]]
 * 
 * Example 2
 * Input:
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation: 
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected by a path of the same color as the starting pixel are colored with the new color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
 * 
 * Related Problems
 * 1225. Island Perimeter
 * */

/**
 * Running Time: 50ms
 */

class Solution
{
public:
	/**
     * @param image: a 2-D array
     * @param sr: an integer
     * @param sc: an integer
     * @param newColor: an integer
     * @return: the modified image
     */
	vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
	{
		if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image.size() || image[sr][sc] == newColor)
			return image;
		int oldColor = image[sr][sc];
		search(image, sr, sc, newColor, oldColor);
		return image;
	}

private:
	void search(vector<vector<int>> &image, int i, int j, int newColor, int oldColor)
	{
		if (i - 1 >= 0 && image[i - 1][j] == oldColor)
		{
			image[i - 1][j] = newColor;
			search(image, i - 1, j, newColor, oldColor);
		}

		if (i + 1 != image.size() && image[i + 1][j] == oldColor)
		{
			image[i + 1][j] = newColor;
			search(image, i + 1, j, newColor, oldColor);
		}

		if (j - 1 >= 0 && image[i][j - 1] == oldColor)
		{
			image[i][j - 1] = newColor;
			search(image, i, j - 1, newColor, oldColor);
		}

		if (j + 1 != image[i].size() && image[i][j + 1] == oldColor)
		{
			image[i][j + 1] = newColor;
			search(image, i, j + 1, newColor, oldColor);
		}

		image[i][j] = newColor;
	}
};
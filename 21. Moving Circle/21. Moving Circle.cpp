/** 
 * 21. Moving Circle
 * 
 * Difficulty
 * Medium
 * 
 * Description
 * The problem will give the center coordinates (x, y) and radius r of the two circles A and B.
 * Then the problem give you a point P, and move the center of circle A to the point P along a straight line.
 * Will the circle A intersect with the circle B during the move? 
 * (The moving process includes the starting point and an ending point)
 * If it they intersect return 1, otherwise return -1.
 * 
 * Clarification
 * 1. The radius of both circles does not exceed 10000.
 * 2. The absolute value of the abscissa and ordinate values does not exceed 10000.
 * 3. The list in input represent [X_A, Y_A, R_A, X_B, Y_B, R_B, X_P, Y_P].
 * 
 * Example
 * Example 1
 * Input：
 * [0,0,2.5,3,2,0.5,0,2]
 * Output：
 * 1
 * Explain：
 * The center of circle A (0, 0) has a radius of 2.5, the center of circle B (3, 2) has a radius of 0.5, and the point P (0, 2). 
 * 
 * Example 2
 * Input：
 * [0,0,2,5,0,1,0,2]
 * Output：
 * -1
 * Explain：
 * The center of circle A (0, 0) has a radius of 2, the center of circle B (5,0) has a radius of 1, and the point P (0, 2). 
 * */

/**
 * Ref: https://www.jiuzhang.com/problem/moving-circle/#tag-lang-cpp
 * Running Time: 51ms
 */

class Solution
{
public:
    /**
     * @param position: the position of circle A,B and point P.
     * @return: if two circle intersect return 1, otherwise -1.
     */
    int IfIntersect(vector<double> &position)
    {
        point A, B, P, M;
        double ra, rb;
        double dmin, dmax;

        A.x = position[0], A.y = position[1];
        ra = position[2];
        B.x = position[3], B.y = position[4];
        rb = position[5];
        P.x = position[6], P.y = position[7];

        // draw a perpendicular from B to AP 
        // M is a pointer on the perpendicular
        // if A and P is not overlapped, then M is not overlapped with B
        M.x = B.x - (P.y - A.y), M.y = B.y + (P.x - A.x);

        // if circle A cross the cross point of point B to point B's perpendicular to line AP
        if (xmult(A, B, M) * xmult(B, P, M) >= 0)
        {
            if (A.x == P.x && A.y == P.y)
            {
                dmin = distance(B, A);
            }
            else
            {
                dmin = dis_ptoline(B, A, P);
            }
        }
        else
        {
            dmin = min(distance(A, B), distance(P, B));
        }
        dmax = max(distance(A, B), distance(P, B));
        if (dmin > ra + rb || dmax < fabs(ra - rb))
            return -1;
        return 1;
    }

private:
    typedef struct point
    {
        double x, y;
    } point;

    // AB×AC
    double xmult(point B, point C, point A)
    {
        return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
    }

    // distance between two pointers
    double distance(point A, point B)
    {
        return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    }
    
    // distance from A to line BC
    double dis_ptoline(point A, point B, point C)
    {
        return fabs(xmult(A, B, C)) / distance(B, C);
    }
};
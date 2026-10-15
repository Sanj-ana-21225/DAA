#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>
using namespace std;
struct Point
{
    int x, y;
};
double distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}
double bruteForce(vector<Point> &points, int left, int right)
{
    double minDist = DBL_MAX;
    for (int i = left; i <= right; i++)
    {
        for (int j = i + 1; j <= right; j++)
        {
            minDist = min(minDist, distance(points[i], points[j]));
        }
    }
    return minDist;
}
bool compareY(Point a, Point b)
{
    return a.y < b.y;
}
double stripClosest(vector<Point> &strip, double d)
{
    sort(strip.begin(), strip.end(), compareY);
    double minDist = d;
    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < strip.size() &&
             (strip[j].y - strip[i].y) < minDist; j++)
        {
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }
    return minDist;
}
double closestUtil(vector<Point> &points, int left, int right)
{
    if (right - left <= 2)
        return bruteForce(points, left, right);
    int mid = (left + right) / 2;
    Point midPoint = points[mid];
    double dl = closestUtil(points, left, mid);
    double dr = closestUtil(points, mid + 1, right);
    double d = min(dl, dr);
    vector<Point> strip;
    for (int i = left; i <= right; i++)
    {
        if (abs(points[i].x - midPoint.x) < d)
            strip.push_back(points[i]);
    }
    return min(d, stripClosest(strip, d));
}
bool compareX(Point a, Point b)
{
    return a.x < b.x;
}
double closest(vector<Point> &points)
{
    sort(points.begin(), points.end(), compareX);
    return closestUtil(points, 0, points.size() - 1);
}
int main()
{
    vector<Point> points = {
        {2, 3},
        {12, 30},
        {40, 50},
        {5, 1},
        {12, 10},
        {3, 4}
    };
    cout << "Minimum Distance = " << closest(points);
    return 0;
}

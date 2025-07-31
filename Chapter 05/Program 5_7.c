#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    double x, y;
};

bool compareByX(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

bool compareByY(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

double distanceBetween(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double closestPairBruteForce(const vector<Point>& points) {
    int n = points.size();
    double minDistance = numeric_limits<double>::max();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double distance = distanceBetween(points[i], points[j]);
            minDistance = min(minDistance, distance);
        }
    }

    return minDistance;
}

double closestPairStrip(const vector<Point>& strip, double minDistance) {
    int n = strip.size();
    double minStripDistance = minDistance;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < min(i + 7, n); j++) {
            double distance = distanceBetween(strip[i], strip[j]);
            minStripDistance = min(minStripDistance, distance);
        }
    }

    return minStripDistance;
}

double closestPairRec(vector<Point>& points) {
    int n = points.size();

    if (n <= 3) {
        // Base case: Use brute force for small number of points
        return closestPairBruteForce(points);
    }

    // Divide the points into two halves
    int mid = n / 2;
    vector<Point> leftPoints(points.begin(), points.begin() + mid);
    vector<Point> rightPoints(points.begin() + mid, points.end());

    // Recursively find the closest pairs in each half
    double leftClosest = closestPairRec(leftPoints);
    double rightClosest = closestPairRec(rightPoints);

    // Find the minimum distance between the two halves
    double minDistance = min(leftClosest, rightClosest);

    // Merge the results from the two halves
    vector<Point> strip = pointsWithinStrip(points, mid, minDistance);
    return min(minDistance, closestPairStrip(strip, minDistance));
}

vector<Point> pointsWithinStrip(const vector<Point>& points, int mid, double minDistance) {
    vector<Point> strip;

    for (const Point& point : points) {
        if (abs(point.x - points[mid].x) < minDistance) {
            strip.push_back(point);
        }
    }

    sort(strip.begin(), strip.end(), compareByY);

    return strip;
}

double closestPair(vector<Point>& points) {
    // Sort points by x-coordinate
    sort(points.begin(), points.end(), compareByX);

    // Call the recursive function
    return closestPairRec(points);
}

int main() {
    // Example usage
    vector<Point> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};

    double minDistance = closestPair(points);

    cout << "Closest Pair Distance: " << minDistance << endl;

    return 0;
}

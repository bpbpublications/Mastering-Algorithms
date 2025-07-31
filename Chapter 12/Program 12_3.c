#include <stdio.h>

typedef struct Point {
    int x, y;
} Point;

// Function to swap two points
void swap(Point *a, Point *b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the orientation of the triplet (p, q, r).
// The function returns the following values:
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// Function to print the convex hull
void printConvexHull(Point points[], int n) {
    // There must be at least 3 points
    if (n < 3) return;

    // Initialize Result
    Point hull[n];
    int hullSize = 0;

    // Find the leftmost point
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x)
            leftmost = i;
    }

    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again. This loop runs O(h)
    // times where h is number of points in result or output.
    int p = leftmost, q;
    do {
        // Add current point to result
        hull[hullSize++] = points[p];

        // Search for a point 'q' such that orientation(p, x,
        // q) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            // If i is more counterclockwise than current q, then
            // update q
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;

    } while (p != leftmost);  // While we don't come to first point

    // Print Result
    printf("The points in the convex hull are:\n");
    for (int i = 0; i < hullSize; i++)
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
}

// Main function
int main() {
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    printConvexHull(points, n);
    return 0;
}

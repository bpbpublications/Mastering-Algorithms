#include <stdio.h>
#include <stdlib.h>

// Point structure
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

// Function to sort points by polar angle with the pivot
int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    int o = orientation(pivot, *p1, *p2);
    if (o == 0)
        return (p1->x - pivot.x) * (p1->x - pivot.x) + (p1->y - pivot.y) * (p1->y - pivot.y) <
               (p2->x - pivot.x) * (p2->x - pivot.x) + (p2->y - pivot.y) * (p2->y - pivot.y) ? -1 : 1;
    return (o == 2) ? -1 : 1;
}

// Function to return the next to top element of a stack
Point nextToTop(Point stack[], int *top) {
    return stack[*top - 1];
}

// Function to print the convex hull
void printConvexHull(Point points[], int n) {
    // Find the bottom-most point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at first position
    swap(&points[0], &points[min]);

    // Sort n-1 points with respect to the first point. A point p1 comes before p2 in sorted output if p2
    // has a larger polar angle (in counterclockwise direction) than p1
    pivot = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    // Create an empty stack and push first three points to it
    Point stack[n];
    int top = -1;
    stack[++top] = points[0];
    stack[++top] = points[1];
    stack[++top] = points[2];

    // Process remaining n-3 points
    for (int i = 3; i < n; i++) {
        // Keep removing top while the angle formed by points next-to-top, top, and points[i] makes a non-left turn
        while (top > 0 && orientation(nextToTop(stack, &top), stack[top], points[i]) != 2)
            top--;
        stack[++top] = points[i];
    }

    // Now stack has the output points, print contents of stack
    printf("The points in the convex hull are:\n");
    for (int i = 0; i <= top; i++)
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
}

// Main function
int main() {
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    printConvexHull(points, n);
    return 0;
}

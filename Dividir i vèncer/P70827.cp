// Closest pair  (Martí Cortada Garcia)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

// Structure to represent a point (x, y coordinates)
struct Point {
    double x, y;
};

// Returns the distance between two points
double Distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Compares two points by the y coordinate (smallest first)
// In case of a tie, it compares be the x coordinate
bool sortY(const Point& p1, const Point& p2) {
    if (p1.y != p2.y) return p1.y < p2.y;
    return p1.x < p2.x;
}

// Pre: P is a vector of points sorted by the y coordinate
//      X[i..j] contains the x-coordinates of the points in P in ascending order
// Returns the smallest distance of a pair of points in P.
// If i >= j, it returns infinity.
double ClosestPoints(const vector<Point>& P, const vector<double>& X, int i, int j) {

    // Base case: 0 or 1 elements -> infinity
    if (P.size() <= 1) return numeric_limits<double>::infinity();

    // Exotic case, all points have the same x-coordinate. We need to
    // treat it to avoid all points to go to the left (infinite recursion)
    // We simply calculate the shortest distance between the y coordinates.
    if (X[i] == X[j]) {
        double d = numeric_limits<double>::infinity();
        for (int i = 0; i < P.size() - 1; ++i) {
            d = min(d, P[i+1].y - P[i].y);
        }
        return d;
    }

    // Divide and conquer: split X[i..j] into two segments.
    int mid = (i+j)/2;
    double midx = X[mid];

    // Create two vectors from P (left and right) sorted by the y coordinates
    vector<Point> Pleft, Pright;
    for (const Point& p: P) {
        if (p.x <= midx) Pleft.push_back(p);
        else Pright.push_back(p);
    }

    // Find the smallest distance at each side
    double d = min(ClosestPoints(Pleft, X, i, mid), ClosestPoints(Pright, X, mid+1, j));

    // Calculate the limits of the central strip
    double xmin = midx - d;
    double xmax = midx + d;

    // Calculate the points in the central strip sorted by the y coordinate
    vector<Point> Pmid;
    for (const Point& p: P) {
        if (p.x >= xmin and p.x <= xmax) Pmid.push_back(p);
    }

    // Find the smallest distance (visit points in order)
    for (int k = 0; k < Pmid.size(); ++k) {
        for (int q = k+1; q < Pmid.size(); ++q) {
            // Check when there is no need to look for more points
            if (Pmid[q].y - Pmid[k].y >= d) break; // Too far
            d = min(d, Distance(Pmid[q], Pmid[k]));
        }
    }

    return d;
}


// Main program: reads a list of points (pairs of (x,y) coordinates)
// and writes the shortest distance between two points
int main() {
    vector<Point> P; // Vector of points
    vector<double> X; // Vector of X-coordinates
    double x, y;
    while (cin >> x >> y) {
        P.push_back({x, y});
        X.push_back(x);
    }

    sort(X.begin(), X.end()); // sorted by x-coordinates
    sort(P.begin(), P.end(), sortY); // sorted by y coordinates

    cout << fixed << setprecision(5) << ClosestPoints(P, X, 0, X.size()-1) << endl;
}

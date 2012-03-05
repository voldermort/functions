    class Point implements Comparable<Point> {

        double x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            if (this.x > o.x) {
                return 1;
            }
            if (this.x < o.x) {
                return -1;
            }
            if (this.y > o.y) {
                return 1;
            }
            if (this.y < o.y) {
                return -1;
            }

            throw new UnsupportedOperationException("Not supported yet.");
        }
    }

    public double where(Point a, Point b, Point p) {
        return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
    }

    public ArrayList<Point> convex(ArrayList<Point> points) {
        Collections.sort(points);

        if (points.size() <= 1) {
            return points;
        }
        ArrayList<Point> lower = new ArrayList<Point>();
        ArrayList<Point> upper = new ArrayList<Point>();
        ArrayList<Point> ret = new ArrayList<Point>();
        for (Point p : points) {
            while (lower.size() >= 2 && where(lower.get(lower.size() - 2), lower.get(lower.size() - 1), p) <= 0) {
                lower.remove(lower.size() - 1);
            }
            lower.add(p);
        }
        Collections.reverse(points);
        for (Point p : points) {
            while (upper.size() >= 2 && where(upper.get(upper.size() - 2), upper.get(upper.size() - 1), p) <= 0) {
                upper.remove(upper.size() - 1);
            }
            upper.add(p);
        }
        for (int i = 0; i < lower.size()-1; i++) {
            ret.add(lower.get(i));
        }

        for (int i = 0; i < upper.size()-1; i++) {
            ret.add(upper.get(i));
        }
        return ret;
    }


//////////////////////////////////////////// convex-hull

struct Point {
        coord_t x, y;
 
        bool operator <(const Point &p) const {
                return x < p.x || (x == p.x && y < p.y);
        }
};
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
        int n = P.size(), k = 0;
        vector<Point> H(2*n);
 

        sort(P.begin(), P.end());

        for (int i = 0; i < n; i++) {
                while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
                H[k++] = P[i];
        }

        for (int i = n-2, t = k+1; i >= 0; i--) {
                while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
                H[k++] = P[i];
        }
 
        H.resize(k);
        return H;
}

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

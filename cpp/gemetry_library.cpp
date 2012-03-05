#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<cassert>
#include<climits>
#include<complex>
using namespace std;

const double pi = 2.0 * acos(0.0);
const double eps = 1e-9;

class point{
	public:
	double x,y;
	point(){}
	point(double _x,double _y):x(_x),y(_y){}
	
	point operator +(const point & o1){
		return point(x+o1.x,y+o1.y);
	}
	point operator -(const point & o1){
		return point(x-o1.x,y-o1.y);
	}
	point operator *(double o1){
		return point(x*o1,y*o1);
	}
	
	double length(){
		return x*x+y*y;
	}
	
	int norm(){
		double l=length(); 
		if(fabs(l)<eps)return 0;
		x/=l;
		y/=l;
		return 1;
	}
	
};
bool operator<(const point& a, const point& b) {
    if (fabs(a.x - b.x) < eps) return a.y < b.y;
    return a.x < b.x;
}

double dist(point &o1,point &o2){
	return sqrt((o1.x-o2.x)*(o1.x-o2.x)+(o1.y-o2.y)*(o1.y-o2.y));
}

double dot(point &o1,point &o2){
	return o1.x*o2.x+o1.y*o2.y;
}

int wside(point &o1,point &o2,point &o3){
	//line==o1->o2
	//o3 is a point 
	//returnns 1 if left side 0 if on and -1 if right side
	double ret= (o1.x-o3.x)*(o2.y-o3.y)-(o1.y-o3.y)*(o2.x-o3.x);
	if(fabs(ret)<eps)return 0;
	if(ret>0)return 1;
	return -1;
}

bool better(point& o1, point& o2, point& o3)
// used by convec hull: from p3, if p1 is better than p2
{
	double sg = (o1.y - o3.y)*(o2.x - o3.x)-(o1.x - o3.x)*(o2.y - o3.y);
	//watch range of the numbers
	if (fabs(sg) < eps) {
		if (dist(o3, o1) > dist(o3, o2))return true;
		else return false;
	}
	if (sg < 0) return true;
	return false;
}


vector<point> convex_hull(vector<point> vin)
{
	int n = vin.size();
	sort(vin.begin(),vin.end());
	point stk[vin.size()+1];
	int pstk, i;
	if(vin.size()<=2){
		return vin;
	}
	vector<point> vout;
	stk[0] = vin[0];
	stk[1] = vin[1];
	pstk = 2;
	for (i = 2; i < n; i++) {
		if (dist(vin[i], vin[i - 1]) < eps) continue;
		while (pstk > 1 && better(vin[i], stk[pstk - 1], stk[pstk - 2]))
			pstk--;
		stk[pstk] = vin[i];
		pstk++;
	}
	for (i = 0; i < pstk; i++) vout.push_back(stk[i]);
	// turn 180 degree
	for (i = 0; i < n; i++) {
		vin[i].y = -vin[i].y;
		vin[i].x = -vin[i].x;
	}
	sort(vin.begin(), vin.end());
	stk[0] = vin[0];
	stk[1] = vin[1];
	pstk = 2;
	for (i = 2; i < n; i++) {
		if (dist(vin[i], vin[i - 1]) < eps) continue;
		while (pstk > 1 && better(vin[i], stk[pstk - 1], stk[pstk - 2]))
			pstk--;
		stk[pstk] = vin[i];
		pstk++;
	}
    for (i = 1; i < pstk - 1; i++) {
		stk[i].x = -stk[i].x; // don’t forget rotate 180 d back.
		stk[i].y = -stk[i].y;
		vout.push_back(stk[i]);
	}
	return vout;
}

int isConvex(vector<point>& v)
// test whether a simple polygon is convex
// return 0 if not convex, 1 if strictly convex,
// 2 if convex but there are points unnecesary
// this function does not work if the polycon is self intersecting
// in that case, compute the convex hull of v, and see if both have the same area
{
	int i, j, k;
	int c1 = 0;
	int c2 = 0;
	int c0 = 0;
	int n = v.size();
	for (i = 0; i < n; i++) {
		j = (i + 1) % n;
		k = (j + 1) % n;
		int s = wside(v[i], v[j], v[k]);
		if (s == 0) c0++;
		if (s > 0) c1++;
		if (s < 0) c2++;
	}
	if (c1 && c2) return 0;
	if (c0) return 2;
	return 1;
}

double trap(point a, point b) {
    return (0.5 * (b.x - a.x)*(b.y + a.y));
}

double area(vector<point> &vin)
// Area of a simple polygon, not neccessary convex
{
    int n = vin.size();
    double ret = 0.0;
    for (int i = 0; i < n; i++)
        ret += trap(vin[i], vin[(i + 1) % n]);
    return fabs(ret);
}

double peri(vector<point> &vin)
// Perimeter of a simple polygon, not neccessary convex
{
    int n = vin.size();
    double ret = 0.0;
    for (int i = 0; i < n; i++)
        ret += dist(vin[i], vin[(i + 1) % n]);
    return ret;
}

double triarea(point a, point b, point c) {
    return fabs(trap(a, b) + trap(b, c) + trap(c, a));
}

double height(point a, point b, point c)
// height from a to the line bc
{
    double s3 = dist(c, b);
    double ar = triarea(a, b, c);
    return (2.0 * ar / s3);
}

int intersection(point p1, point p2, point p3, point p4, point &r)
// two lines given by p1->p2, p3->p4 r is the intersection point
// return -1 if two lines are parallel
{
    double d = (p4.y - p3.y)*(p2.x - p1.x) - (p4.x - p3.x)*(p2.y - p1.y);
    if (fabs(d) < eps) return -1;
    // might need to do something special!!!
    double ua;
    ua = (p4.x - p3.x)*(p1.y - p3.y) - (p4.y - p3.y)*(p1.x - p3.x);
    ua /= d;
    // ub = (p2.x - p1.x)*(p1.y-p3.y) - (p2.y-p1.y)*(p1.x-p3.x);
    //ub /= d;
    r = p1 + (p2 - p1) * ua;
    return 0;
}

void closestpt(point p1, point p2, point p3, point &r)
// the closest point on the line p1->p2 to p3
{
    if (fabs(triarea(p1, p2, p3)) < eps) {
        r = p3;
        return;
    }
    point v = p2 - p1;
    v.norm();
    double pr; // inner product
    pr = (p3.y - p1.y) * v.y + (p3.x - p1.x) * v.x;
    r = p1 + v*pr;
}

int hcenter(point p1, point p2, point p3, point& r) {
    // point generated by altitudes
    if (triarea(p1, p2, p3) < eps) return -1;
    point a1, a2;
    closestpt(p2, p3, p1, a1);
    closestpt(p1, p3, p2, a2);
    intersection(p1, a1, p2, a2, r);
    return 0;
}

int center(point p1, point p2, point p3, point& r) {
    // point generated by circumscribed circle
    if (triarea(p1, p2, p3) < eps) return -1;
    point a1, a2, b1, b2;
    a1 = (p2 + p3)*0.5;
    a2 = (p1 + p3)*0.5;
    b1.x = a1.x - (p3.y - p2.y);
    b1.y = a1.y + (p3.x - p2.x);
    b2.x = a2.x - (p3.y - p1.y);
    b2.y = a2.y + (p3.x - p1.x);
    intersection(a1, b1, a2, b2, r);
    return 0;
}

int bcenter(point p1, point p2, point p3, point& r) {
    // angle bisection
    if (triarea(p1, p2, p3) < eps) return -1;
    double s1, s2, s3;
    s1 = dist(p2, p3);
    s2 = dist(p1, p3);
    s3 = dist(p1, p2);
    double rt = s2 / (s2 + s3);
    point a1, a2;
    a1 = p2 * rt + p3 * (1.0 - rt);
    rt = s1 / (s1 + s3);
    a2 = p1 * rt + p3 * (1.0 - rt);
    intersection(a1, p1, a2, p2, r);
    return 0;
}

double angle(point& p1, point& p2, point& p3)
// angle from p1->p2 to p1->p3, returns -PI to PI
{
    point va = p2 - p1;
    va.norm();
    point vb;
    vb.x = -va.y;
    vb.y = va.x;
    point v = p3 - p1;
    double x, y;
    x = dot(v, va);
    y = dot(v, vb);
    return (atan2(y, x));
}


double angle(double a, double b, double c)
// in a triangle with sides a,b,c, the angle between b and c
// we do not check if a,b,c is a triangle here
{
    double cs = (b * b + c * c - a * a) / (2.0 * b * c);
    return (acos(cs));
}
void rotate(point p0, point p1, double a, point& r)
// rotate p1 around p0 clockwise, by angle a
// don’t pass by reference for p1, so r and p1 can be the same
{
    p1 = p1 - p0;
    r.x = cos(a) * p1.x - sin(a) * p1.y;
    r.y = sin(a) * p1.x + cos(a) * p1.y;
    r = r + p0;
}
void reflect(point& p1, point& p2, point p3, point& r)
// p1->p2 line, reflect p3 to get r.
{
    if (dist(p1, p3) < eps) {
        r = p3;
        return;
    }
    double a = angle(p1, p2, p3);
    r = p3;
    rotate(p1, r, -2.0 * a, r);
}
int pAndSeg(point& p1, point& p2, point& p)
// the relation of the point p and the segment p1->p2.
// 1 if point is on the segment; 0 if not on the line; -1 if on the line but not on the segment
{
    double s = triarea(p, p1, p2);
    if (s > eps) return (0);
    double sg = (p.x - p1.x)*(p.x - p2.x);
    if (sg > eps) return (-1);
    sg = (p.y - p1.y)*(p.y - p2.y);
    if (sg > eps) return (-1);
    return (1);
}

int lineAndCircle(point& oo, double r, point& p1, point& p2, point& r1, point& r2)
// returns -1 if there is no intersection
// returns 1 if there is only one intersection
{
    point m;
    closestpt(p1, p2, oo, m);
    point v = p2 - p1;
    v.norm();
    double r0 = dist(oo, m);
    if (r0 > r + eps) return -1;
    if (fabs(r0 - r) < eps) {
        r1 = r2 = m;
        return 1;
    }
    double dd = sqrt(r * r - r0 * r0);
    r1 = m - v*dd;
    r2 = m + v*dd;
    return 0;
}

int CAndC(point o1, double r1, point o2, double r2, point& q1, point& q2)
// intersection of two circles
// -1 if no intersection or infinite intersection
// 1 if only one point
{
    double r = dist(o1, o2);
    if (r1 < r2) {
        swap(o1, o2);
        swap(r1, r2);
    }
    if (r < eps) return (-1);
    if (r > r1 + r2 + eps) return (-1);
    if (r < r1 - r2 - eps) return (-1);
    point v = o2 - o1;
    v.norm();
    q1 = o1 + v*r1;
    if (fabs(r - r1 - r2) < eps || fabs(r + r2 - r1) < eps) {
        q2 = q1;
        return (1);
    }
    double a = angle(r2, r, r1);
    q2 = q1;
    rotate(o1, q1, a, q1);
    rotate(o1, q2, -a, q2);
    return 0;
}


int pAndPoly(vector<point> pv, point p)
// the relation of the point and the simple polygon
// 1 if p is in pv; 0 outside; -1 on the polygon
{
    int i, j;
    int n = pv.size();
    pv.push_back(pv[0]);
    for (i = 0; i < n; i++)
        if (pAndSeg(pv[i], pv[i + 1], p) == 1) return (-1);
    for (i = 0; i < n; i++)
        pv[i] = pv[i] - p;
    p.x = p.y = 0.0;
    double a, y;
    while (1) {
        a = (double) rand() / 10000.00;
        j = 0;
        for (i = 0; i < n; i++) {
            rotate(p, pv[i], a, pv[i]);
            if (fabs(pv[i].x) < eps) j = 1;
        }
        if (j == 0) {
            pv[n] = pv[0];
            j = 0;
            for (i = 0; i < n; i++) if (pv[i].x * pv[i + 1].x < -eps) {
                    y = pv[i + 1].y - pv[i + 1].x * (pv[i].y - pv[i + 1].y) / (pv[i].x - pv[i + 1].x);
                    if (y > 0) j++;
                }
            return (j % 2);
        }
    }
    return 1;
}

void cutPoly(vector<point>& pol, point& p1, point& p2, vector<point>& pol1, vector<point>& pol2)
// cut the convex polygon pol along line p1->p2;
// pol1 are the resulting polygon on the left side, pol2 on the right.
{
    vector<point> pp, pn;
    pp.clear();
    pn.clear();
    int i, sg, n = pol.size();
    point q1, q2, r;
    for (i = 0; i < n; i++) {
        q1 = pol[i];
        q2 = pol[(i + 1) % n];
        sg = wside(p1, p2, q1);
        if (sg >= 0) pp.push_back(q1);
        if (sg <= 0) pn.push_back(q1);
        if (intersection(p1, p2, q1, q2, r) >= 0) {
            if (pAndSeg(q1, q2, r) == 1) {
                pp.push_back(r);
                pn.push_back(r);
            }
        }
    }
    pol1.clear();
    pol2.clear();
    if (pp.size() > 2) pol1=convex_hull(pp);
    if (pn.size() > 2) pol2=convex_hull(pn);
}

int main(){
	
}














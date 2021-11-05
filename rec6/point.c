#include "point.h"

int point_show(Point_2D p){
	printf("(%.2f, %.2f)",p.x,p.y);
	return 1;
}
double point_dist(Point_2D p1, Point_2D p2){
	double xdist = pow(p1.x-p2.x,2);
	double ydist = pow(p1.y-p2.y,2);
	return sqrt(xdist + ydist); 
}
int point_eq(Point_2D p1, Point_2D p2){
	if(point_dist(p1,p2)<0.000001) return 1;
	return 0;
}
double rect_area(Rect r){
	return (r.ur.x - r.ll.x)*(r.ur.y - r.ll.y);
}
int is_in_rect(Point_2D p, Rect r){
	if(p.x > r.ll.x && p.x < r.ur.x && p.y > r.ll.y && p.y < r.ur.y) return 1;
	return 0;
}

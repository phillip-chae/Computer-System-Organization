#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

struct Point_2D{
	double x;
	double y;
};
struct Rect{
	struct Point_2D ll;
	struct Point_2D ur;
};
typedef struct Point_2D Point_2D;
typedef struct Rect Rect;

int point_show(Point_2D point);
double point_dist(Point_2D p1, Point_2D p2);
int point_eq(Point_2D p1, Point_2D p2);
double rect_area(Rect r);
int is_in_rect(Point_2D p, Rect r);

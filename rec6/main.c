#include "point.h"
int main(){
	//Initialize all needed variables to test
	Point_2D display, distance1, distance2, equal1, equal2, rp;
	Rect r;
	
	//Set values for the variables
	display.x = 5;
	display.y = 6;

	distance1.x = 0;
	distance1.y = 2;
	distance2.x = 3;
	distance2.y = 6;

	equal1.x = 1;
	equal1.y = 1;
	equal2.x = 1;
	equal2.y = 1;
	
	r.ur.x = 9;
	r.ur.y = 10;
	r.ll.x = -2;
	r.ll.y = -5;

	rp.x = 0;
	rp.y = 0;
	//Test point_show

	printf("////////////////////TESTING START////////////////////\n\n");

	printf("The point_show function:\n");
	point_show(display);
	printf("\n\n");

	//Test point_dist
	printf("The point_dist function:\n");	

	printf("The distance between ");
	point_show(distance1);
	printf(" and ");
	point_show(distance2);
	printf(" is: %.2f\n\n", point_dist(distance1, distance2));

	assert(point_dist(distance1,distance2) == 5.0);

	//Test point_eq
	printf("The point_eq function:\n");

	printf("The points ");
	point_show(equal1);
	printf(" and ");
	point_show(equal2);
	if(point_eq(equal1,equal2) == 1) printf(" are equal\n\n");
	else printf(" are not equal\n\n");

	assert(point_eq(equal1,equal2) == 1);

	//Test rect_area
	printf("The rect_area function:\n");	

	printf("The rectangle with an upper right point of ");
	point_show(r.ur);
	printf(" and a lower left point of ");
	point_show(r.ll);
	printf(" has an area of: %.2f\n\n", rect_area(r));
	
	assert(rect_area(r) == 165.0);

	//Test is_in_rect
	printf("The is_in_rect function:\n");
	
	printf("The point ");
	point_show(rp);
	if(is_in_rect(rp,r) == 1) printf(" is ");
	else printf(" is not ");
	printf("in the rectangle with an upper right point of ");
	point_show(r.ur);
	printf(" and a lower left point of ");
	point_show(r.ll);

	assert(is_in_rect(rp,r) == 1);

	printf("\n\n////////////////////TESTING COMPLETE///////////////////\n");
}

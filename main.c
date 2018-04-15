#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Calculate distance.
double distance(int x1, int x2, int y1, int y2){
    double xDifference = pow(x1-x2, 2);
    double yDifference = pow(y1-y2, 2);
    return sqrt(xDifference + yDifference);
}

// Calculate area.
double area(int x1, int x2, int x3, int y1, int y2, int y3){
    double x1Multiple = x1*(y2-y3);
    double x2Multiple = x2*(y3-y1);
    double x3Multiple = x3*(y1-y2);
    
    double area = abs(x1Multiple + x2Multiple + x3Multiple);
    return (0.5)*area;
}

// Calculate the center of gravity.
float centerOfGravity(int a, int b, int c){
    return (float)(a + b + c)/3;
}

// Calculate the length of median.
float lengthOfMedian(int a, int b, int c){
    double aSquare = pow(a, 2); 
    double bSquare = pow(b, 2); 
    double cSquare = pow(c, 2); 
    return (float)(sqrt(2*(bSquare + cSquare) - aSquare)*(0.5));
}

// Check if the given triangle is a right triangle.
bool isRight(int a, int b, int c){
    return (pow(a, 2) + pow(b, 2)) == pow(c, 2);
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    printf("Enter first corner: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter second corner: ");
    scanf("%d%d", &x2, &y2);
    printf("Enter third corner: ");
    scanf("%d%d", &x3, &y3);
    
    double aEdge = distance(x1, x2, y1, y2); 
    double bEdge = distance(x1, x3, y1, y3); 
    double cEdge = distance(x2, x3, y2, y3);
    
    bool aEdgeRule = abs(bEdge-cEdge)<aEdge && aEdge< bEdge + cEdge;
    bool bEdgeRule = abs(aEdge-cEdge)<bEdge && bEdge< aEdge + cEdge;
    bool cEdgeRule = abs(aEdge-bEdge)<cEdge && cEdge< aEdge + bEdge;
   
    if(!aEdgeRule || !bEdgeRule || !cEdgeRule) {
        printf("This is not triangle. Please enter another set of coordinates.");
        return -1;
    }
        
    if (aEdge == bEdge && aEdge == cEdge) {
        printf("This is a Regular Triangle.\n");
    } else if((aEdge == bEdge && bEdge != cEdge) || (aEdge == cEdge && cEdge != bEdge) || (bEdge == cEdge && cEdge != aEdge)) {
        printf("This is a Isosceles Triangle.\n");
    } else if((aEdge != bEdge) && (aEdge != cEdge) && (bEdge != cEdge)) {
        printf("This is a Scalene Triangle.\n");
    }

    if(isRight(aEdge, bEdge, cEdge) || isRight(aEdge, cEdge, bEdge) || isRight(bEdge, cEdge, aEdge)) {
        printf("This is a Right Triangle.\n");
    }

    printf("Area: %.2lf\n", area(x1, x2, x3, y1, y2, y3));
    printf("Cx: %.2lf\n", centerOfGravity(x1, x2, x3));
    printf("Cy: %.2lf\n", centerOfGravity(y1, y2, y3));
    printf("The length of the median a: %.3lf\n", lengthOfMedian(aEdge, bEdge, cEdge));
    printf("The length of the median b: %.3lf\n", lengthOfMedian(bEdge, aEdge, cEdge));
    printf("The length of the median c: %.3lf\n", lengthOfMedian(cEdge, bEdge, aEdge));


    return 0;
}




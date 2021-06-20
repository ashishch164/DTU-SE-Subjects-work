/*Program to classify whether a triangle is acute, obtuse or right angled given the sides of
the triangle*/
//Header Files
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main() //Main Begins
 {
 double a,b,c;
 double a1,a2,a3;
 int valid=0;
 clrscr();
 printf("Enter first side of the triangle:"); /*Enter the sides of Triangle*/
 scanf("%lf",&a);
 printf("Enter second side of the triangle:");
 scanf("%lf",&b);
 printf("Enter third side of the triangle:");
 scanf("%lf",&c);
/*Checks whether a triangle is valid or not*/
 if(a>0&&a<=100&&b>0&&b<=100&&c>0&&c<=100) {
 if((a+b)>c&&(b+c)>a&&(c+a)>b) {
 valid=1;
 }
 else {
 valid=-1;
 }
 }
 if(valid==1) {
 a1=(a*a+b*b)/(c*c);
 a2=(b*b+c*c)/(a*a);
a3=(c*c+a*a)/(b*b);
 if(a1<1||a2<1||a3<1) {
 printf("Obtuse angled triangle");
 }
 else if(a1==1||a2==1||a3==1) {
 printf("Right angled triangle");
 }
 else {
 printf("Acute angled triangle");
 }
 }
 else if(valid==-1) {
 printf("\nInvalid Triangle");
 }
 else {
 printf("\nInput Values are Out of Range");
 }
 getch();
 } //Main Ends


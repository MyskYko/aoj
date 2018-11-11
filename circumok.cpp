#include <stdio.h>
#include <math.h>
#include <iostream>
 
using namespace std;
 
int main(void){
    int n, i, j;
    double x1,y1,x2,y2,x3,y3, r, px, py;
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        if((y2 - y1) * (x3 - x1) - (y3 - y1) * (x2 - x1) == 0){
            if(x1 == x2 && x2 == x3){
                px = x1;
                py = (max(y1,max(y2,y3)) + min(y1,min(y2,y3))) / 2;
                r = fabs(max(y1,max(y2,y3)) - py);
            }
            else{
                double tx1, ty1, tx2, ty2;
                if(x1 > x2 && x1 > x3){
                    tx1 = x1, ty1 = y1;
                }else if(x2 > x1 && x2 > x3){
                    tx1 = x2, ty1 = y2;
                }else{
                    tx1 = x3, ty1 = y3;
                }
                if(x1 < x2 && x1 < x3){
                    tx2 = x1, ty2 = y1;
                }else if(x2 < x1 && x2 < x3){
                    tx2 = x2, ty2 = y2;
                }else{
                    tx2 = x3, ty2 = y3;
                }
                px = (tx1 + tx2) / 2;
                py = (ty1 + ty2) / 2;
                r = sqrt(pow(tx1 - px,2.0) + pow(ty1 - py,2.0));
            }
        }else{
            py = ((x3 - x1) * (pow(x2,2.0) - pow(x1,2.0) + pow(y2,2.0) - pow(y1,2.0)) - (x2 - x1) * (pow(x3,2.0) - pow(x1,2.0) + pow(y3,2.0) - pow(y1,2.0))) / (2 * ((y2 - y1) * (x3 - x1) - (y3 - y1) * (x2 - x1)));
            px = ((y3 - y1) * (pow(y2,2.0) - pow(y1,2.0) + pow(x2,2.0) - pow(x1,2.0)) - (y2 - y1) * (pow(y3,2.0) - pow(y1,2.0) + pow(x3,2.0) - pow(x1,2.0))) / (2 * ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)));
            r = sqrt(pow(px - x1,2.0) + pow(py - y1,2.0));
        }
        printf("%.3f %.3f %.3f\n",px,py,r);
    }
    return 0;
}

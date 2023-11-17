#include <stdio.h>
double dif(double a,double b){
    return a-b;
}
int main()
{
    double x[4] = {1.0,1.05,1.1,1.15};
    double y[4] = {0.1924,0.2414,0.2933,0.3492};
    double f = 1.09;
    double den[4] = {1,1,1,1},num[4] = {1,1,1,1};
    for(int i = 0;i < 4;i++){
        for(int j = 0;j<4;j++){
            if(i != j){
                den[i] *= dif(x[i],x[j]);
                num[i] *= dif(f,x[j]);
            }
        }
    }
    double res[4] = {0};
    for(int i = 0;i < 4;i++){
        res[i] += y[i] * num[i] / den[i];
    }
    double ans = 0;
    for(int i = 0;i < 4;i++){
        ans += res[i];
    }
    printf("%lf\n",ans);
    return 0;
}

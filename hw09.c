#include <stdio.h>
double newton(int x,int y,double year[4],double ppm[4]){
    if(x == y){
        return ppm[x];
    }else{
        return (newton(x+1,y,year,ppm) - newton(x,y-1,year,ppm)) / (year[y] - year[x]);
    }
}
int main()
{
    double year[4] = {1800,1850,1900,2000};
    double ppm[4] = {280,283,291,370};
    double res = 0;
    double f = 1950;
    for(int i = 0;i < 4;i++){
        double term = newton(0,i,year,ppm);
        for(int j = 0;j < i;j++){
            term *= (f - year[j]);
        }
        res += term;
    }
    printf("%lf\n",res);

    return 0;
}

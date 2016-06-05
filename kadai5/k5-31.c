/*---------------------------------------------------
課題5
方程式の解をニュートン法で求め，誤差が繰り返し回数の2乗(重根の場合は1乗)
に比例して減少することを示せ．
(x+2)(x-1)^2=0
2014/10/10 4I31 福嶋開人
----------------------------------------------------*/

#include<stdio.h>
#include<math.h>

double f(double x){
	double y, z;
	y = x + 2.0;
	z = x - 1.0;
	return(y*pow(z, 2.0));
}

int main(void)
{
	int i = 0;
	double dx = 0.001, x0, x, fd, err, epa = 1.0e-4, epr = 1.0e-8;
	printf("Intput x:");
	scanf_s("%lf", &x);
	do{
		i += 1;
		x0 = x;
		fd = (f(x0 + dx) - f(x0)) / dx;
		x = x0 - f(x0) / fd;
		err = fabs(x - x0) / (epa + epr*(fabs(x0) + fabs(x)));
		printf("%d	%.20lf\n", i,1-x);
	} while (err > 1);
	printf("解：%lf		収束するのに%d回",x,i);
	getch();
	return(0);
}
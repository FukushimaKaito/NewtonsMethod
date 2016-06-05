/*---------------------------------------------------
�ۑ�5
�������̉����j���[�g���@�ŋ��߁C�덷���J��Ԃ��񐔂�2��(�d���̏ꍇ��1��)
�ɔ�Ⴕ�Č������邱�Ƃ������D
(x+2)(x-1)^2=0
2014/10/10 4I31 �����J�l
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
	printf("���F%lf		��������̂�%d��",x,i);
	getch();
	return(0);
}
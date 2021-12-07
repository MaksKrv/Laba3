#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#define lip 0.0001
double f(double x)// my function 2*pow(x,3)-0.2*pow(x,2)+0.5*x+3
{
    return 2*pow(x,3)-0.2*pow(x,2)+0.5*x+3;
}
double f_derivative1 (double x)    //перша похідна функції
{
    return  6*pow(x,2)-0.4*x+0.5 ;
}
double f_derivative2 (double x)    //друга похідна функції
{
    return 12*x-0.4;
}

void dump(double xi,double fault,int n,double Timer)
{
    printf("x = %lf\n",xi);
    printf("f(x)  = %lf\n",fault);
    printf("Count of iterations = %d\n",n);
    printf("Calculation time = %lf\n",Timer);
}

int main()
{

    double x1, x2,xi,timer,fault;
    unsigned int N, n = 0,var;
    char i;
    printf("1 - chord method\n2 - half chord method\n3 - method Newton\n");
    scanf("%d",&var);
    switch(var)
    {
    case 1://chord method
        x1=0;
        x2=0;
      do
      {
            x1=x1-0.5;
            x2=+0.5;
      }
      while((f(x1)*f(x2))>0);
      printf("Fault: \n");
      scanf("%lf",&fault);
      printf("Max count of iterations: \n");
      clock_t T1 = clock();
      scanf("%d",&N);
      do
      {
         xi=((f(x2)*x1) - (f(x1)*x2))/(f(x2) - f(x1));
         if( f(xi) >  0 )
         {
            x2=xi;
         }
        else
        {
            x1=xi;
        }
        if(n==N)
        {
            printf("The maximum number of iterations is reached\n");
            printf("Press ESC to finish the calculation \nor press any key to continue the calculation\n");
            i = getch();
            if((int)i==27)
            {
                system("cls");
                break;
            }
            else
            {
             system("cls");
            }
        }
        n++;
      }
      while ( fabs (f(xi)) > fault );
      clock_t T2 = clock();
        dump(xi,fabs (f(xi)),n,(double)(T2 - T1) / CLOCKS_PER_SEC);
       break;
    case 2:// half chord method
      do
      {
        printf("Left limit: \n");
        scanf("%lf",&x1);
        printf("Right limit: \n");
        scanf("%lf",&x2);
      }
      while((f(x1)*f(x2))>0);
      printf("Fault: \n");
      scanf("%lf",&fault);
      printf("Max count of iterations: \n");
      clock_t T11 = clock();
      scanf("%d",&N);
      do
      {
         xi=(x1+x2)/2;
         if( f(xi) >  0 )
         {
            x2=xi;
         }
        else
        {
            x1=xi;
        }
        if(n==N)
        {
            printf("The maximum number of iterations is reached\n");
            printf("Press ESC to finish the calculation \nor press any key to continue the calculation\n");
            i = getch();
            if((int)i==27)
            {
                system("cls");
                break;
            }
            else
            {
             system("cls");
            }
        }
        n++;
      }
      while ( fabs (f(xi)) > fault );
      clock_t T22 = clock();
     dump(xi,fabs (f(xi)),n,(double)(T22 - T11) / CLOCKS_PER_SEC);
      break;
    case 3://method Newton
       do
      {
        printf("Left limit: \n");
        scanf("%lf",&x1);
        printf("Right limit: \n");
        scanf("%lf",&x2);
      }
      while((f(x1)*f(x2))>0);
      printf("Fault: \n");
      scanf("%lf",&fault);
      printf("Max count of iterations: \n");
      clock_t T111 = clock();
      scanf("%d",&N);

    if(f(x1)*f_derivative2(x1)<0)
        xi=x1;
    else
        xi=x2;
    do
    {
        xi=xi-f(xi)/f_derivative1(xi);
        n++;
    }
    while (fabs(f(xi))>=lip);
 if(n==N)
        {
            printf("The maximum number of iterations is reached\n");
            printf("Press ESC to finish the calculation \nor press any key to continue the calculation\n");
            i = getch();
            if((int)i==27)
            {
                system("cls");
                break;
            }
            else
            {
             system("cls");
            }
        }
        n++;
while ( fabs (f(xi)) > fault );
      clock_t T222 = clock();
     dump(xi,fabs (f(xi)),n,(double)(T222 - T111) / CLOCKS_PER_SEC);

    break;
}
return 0;
}

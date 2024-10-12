#include <stdio.h>
#include <math.h>

enum num{
    noroots = 0,
    oneroot = 1,
    tworoots= 2,
    infroots=-1
}; // TODO rename num to Num or num_t and noroots to NOROOTS or c_noroots
int getcf(double *a, double *b, double *c);
enum num solve(double a, double b, double c, double *x1, double *x2);
void out(enum num z, double x1, double x2);

static const double LITTLE=0.00001;

int main()

{
    double a=0;
    double b=0;
    double c=0;
    int cnt=getcf(&a, &b, &c);

    double x1=0;
    double x2=0;
    enum num z=solve(a, b, c, &x1, &x2);

    out(z, x1, x2);
}

int getcf(double *a, double *b, double *c)
{
    return scanf("%lf %lf %lf", a, b, c);
}

enum num solve(double a, double b, double c, double *x1, double *x2) // TODO разбить на функции
{
    if(fabs(a)<LITTLE)
    {
        if(fabs(b)<LITTLE)
        {
            if(fabs(c)<LITTLE) return infroots;
            else return noroots;
        }

        else//else if b!=0
        {
            if(fabs(c)<LITTLE)
            {
                *x1=0;
                *x2=0;
                return oneroot;
            }
            else
            {
                *x1=-c/b;
                *x2=-c/b;
                return oneroot;

            }
        }
    }

    else
    {
        if(fabs(b)<LITTLE)
        {
            if(fabs(c)<LITTLE)
            {
                *x1=0;
                *x2=0;
                return oneroot;
            }
            else if(fabs(c)<LITTLE)
            {
                *x1=sqrt(-c/a);
                *x2=-sqrt(-c/a);
                return tworoots;
            }
            else return noroots;

        }

        else
        {
            if(fabs(c)<LITTLE)
            {
                *x1=0;
                *x2=-b/a;
                return tworoots;
            }
            else
            {
                if (b*b-(4*a*c)<0)
                {
                    return noroots;
                }
                else
                {
                    *x1=(-b+sqrt(b*b-(4*a*c)))/(2*a);
                    *x2=(-b-sqrt(b*b-(4*a*c)))/(2*a);
                    return tworoots;
                }
            }
        }
    }
}
void out(enum num z, double x1, double x2)
{
    switch(z)
    {
        case noroots:
            printf("net korney\n");
            break;
        case infroots:
            printf("mnogo korney\n");
            break;
        case oneroot:
            printf("x1=x2=%lf\n", x1);
            break;
        case tworoots:
            printf("x1=%lf, x2=%lf\n", x1, x2);
            break;
    }
}

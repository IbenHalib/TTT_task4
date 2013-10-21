#include "fucker.h"
#include <qmath.h>

Fucker::Fucker()
{
}

void Fucker::init()
{
//    C = 0.5;
//    K = 1e-13;
//    T = 300;
//    k = 1.38e-23;
//    g1 = 3.1e-21;
//    alpha = 1.0;

//    dt = 1e-5;
//    t = 0;

     k = 1.38e-23;
     dt = 1e-5;
     t = 0;
     K = 1e-13;
     C0 = 0.3;
     T = 550;
     alpha = 2.4;
     C1 = 0.5;
     pi = 3.14;
     sigma = 0.05;
     n = 7e28;
     dg1 = -3e-20;
     N_tot = 1e22;
     N0 = 7;

    for (int i = 0; i < 1000; i++) {
        f[i][0] = i;
        f[i][1] = 0;
    }

    f[0][1] = 1.0;
}

double Fucker::f_incr(int NB, double C)
{
    f[NB-1][1]*nu_p(NB-1, C) + f[NB + 1][1]*nu_m(NB+1, C) - f[NB][1]*(nu_p(NB, C) + nu_m(NB, C));
}

double Fucker::nu_p(int NB, double C)
{
    return K*C*qPow(NB, 1/3);
}

double Fucker::nu_m(int NB, double C)
{
    return nu_p(NB, C)*qExp((dg(NB, C) - dg(NB-1, C))/(k*T));
}

double Fucker::dg(int NB, double C)
{
    return dg_n(NB)/C1 - dg0(C)/C1 + (C - C1)/C1*ddg_0(C) + 4*pi*sigma*qPow((3.0/(4*pi*n*C1)), 2.0/3)*(qPow((NB+1), 2.0/3) - qPow((NB), 2.0/3));
}

double Fucker::dg_n(double C)
{
    return dg1 + alpha*k*T;
}

double Fucker::dg0(double C)
{
    return k*T*(C*qLn(C) + (1 - C)*qLn(1 - C));
}

double Fucker::C_func()
{
    double s = sum_N();
    return (N_tot*C0 - s)/(N_tot - 1.0/C1*s);
}

double Fucker::sum_N()
{
    double sum = 0;
    for (int NB = N0; NB < N_max; NB++) {
        sum += f[NB][1]*double(NB);
    }

    return sum;
}

double Fucker::ddg_0(double C)
{
    return k*T*(qLn(C) - qLn(1.0 - C));
}

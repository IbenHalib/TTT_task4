#ifndef FUCKER_H
#define FUCKER_H

#define N_max 5000

class Focker
{
public:
    Focker();
    void init();

    //Focker equation
    double f_incr(int NB, double C);

    double nu_p(int NB, double C);

    double nu_m(int NB, double C);

    double dg(int NB, double C);

    double dg_n(double C);

    double dg0(double C);

    double C_func();

    double ddg_0(double C);
    double sum_N();

    double evolute();


    double k;
    double f[N_max];
    double f_temp[N_max];
    double dt;
    double t;
    double K, C0;
    double T;
    double alpha;
    double C1;
    double pi;
    double sigma;
    double n;
    double dg1;
    double N_tot;
    int N0;

    double W;
};

#endif

#ifndef FUCKER_H
#define FUCKER_H

#define N_max 10000

class Fucker
{
public:
    Fucker();
    void init();

    //fucking equation
    double f_incr(int NB, double C);

    //deserter (traitor)
    double nu_p(int NB, double C);

    //Behold, fucking pisser scared
    double nu_m(int NB, double C);

    //Jewish manners
    double dg(int NB, double C);

    //Some body nothing to deal
    double dg_n(double C);

    //More equations - better physics
    double dg0(double C);

    //Look previous
    double C_func();

    double ddg_0(double C);
    double sum_N();


    double k;
    double f[N_max][2];
    double dt;
    double t;
    double K, C, C0;
    double T;
    double alpha;
    double C1;
    double pi;
    double sigma;
    double n;
    double dg1;
    double N_tot;
    double N0;
};

#endif // FUCKER_H

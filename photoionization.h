#ifndef PHOTOIONIZATION_H
#define PHOTOIONIZATION_H

struct SigmaParams
{
	double sigma_0;
	double E_0;
	double y_0;
	double y_1;
	double y_w;
	double y_a;
	double P;
};

//verner ea 1996 photoionization cross section
//fitting function
double F_verner(double x, SigmaParams SP);

//photoionization cross section
double sigma_E(double E, SigmaParams SP);

//HI
double E_thresh_HI(void);
double sigma_HI(double E);

//HeI
double E_thresh_HeI(void);
double sigma_HeI(double E);

//HeII
double E_thresh_HeII(void);
double sigma_HeII(double E);

#endif // PHOTOIONIZATION_H

#include <math.h>
#include <stdio.h>
#include "photoionization.h"

//fitting function of verner ea 1996
double F_verner(double x, SigmaParams SP)
{
	double y_1 = SP.y_1;
	double y_w = SP.y_w;
	double y_a = SP.y_a;
	double P = SP.P;
	double y = sqrt(x*x + y_1*y_1);
	double a = sqrt(y/y_a);
	double b = 0.5*P-5.5;
	double F = ( pow(x-1,2) + y_w*y_w )*pow(y,b)*pow(1+a,-P);
	//printf("x %e y %e y_w %e a %e b %e P %e F %e\n",x,y,y_w,a,b,P,F);
	return F;
}

//photoionization cross section
double sigma_E(double E, SigmaParams SP)
{
	//equation 1 of verner et al. 1996
	//return answer in cm^2
	double sigma_0 = SP.sigma_0 * 1.0e-18; //cm^2
	double E_0 = SP.E_0;
	double y_0 = SP.y_0;
	double x = E/E_0 - y_0;
	double F = F_verner(x,SP);

	return sigma_0 * F; // cm^2
}

//HI
double E_thresh_HI(void)
{
	// photoionization threshold of HI in eV
	//Table 1 of verner ea 1996
	return 13.60;
}
double sigma_HI(double E)
{
	//photoionization cross section of
	//hydrogen, parameters from table
	//1 of verner ea 1996 ApJ 465 487
	SigmaParams SP;
	SP.E_0     = 4.298e-1;
	SP.sigma_0 = 5.475e4;
	SP.y_a     = 3.288e1;
	SP.P       = 2.963e0;
	SP.y_w     = 0;
	SP.y_0     = 0;
	SP.y_1     = 0;

	//return photoionization cross section
	//in units of cm^2
	return sigma_E(E, SP);
}

//HeI
double E_thresh_HeI(void)
{
	// photoionization threshold of HeI in eV
	//Table 1 of verner ea 1996
	return 2.459e1;
}
double sigma_HeI(double E)
{
	//photoionization cross section of
	//HeI, parameters from table
	//1 of verner ea 1996 ApJ 465 487
	SigmaParams SP;
	SP.E_0     = 1.361e1;
	SP.sigma_0 = 9.492e2;
	SP.y_a     = 1.469e0;
	SP.P       = 3.188e0;
	SP.y_w     = 2.039e0;
	SP.y_0     = 4.434e-1;
	SP.y_1     = 2.135e0;

	//return photoionization cross section
	//in units of cm^2
	return sigma_E(E, SP);
}

//HeII
double E_thresh_HeII(void)
{
	// photoionization threshold of HeII in eV
	//Table 1 of verner ea 1996
	return 5.442e1;
}
double sigma_HeII(double E)
{
	//photoionization cross section of
	//HeII, parameters from table
	//1 of verner ea 1996 ApJ 465 487
	SigmaParams SP;
	SP.E_0     = 1.720e0;
	SP.sigma_0 = 1.369e4;
	SP.y_a     = 3.288e1;
	SP.P       = 2.963e0;
	SP.y_w     = 0;
	SP.y_0     = 0;
	SP.y_1     = 0;

	//return photoionization cross section
	//in units of cm^2
	return sigma_E(E, SP);
}
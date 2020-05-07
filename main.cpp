#include <stdio.h>
#include "photoionization.h"

int main(int argc, char **argv)
{
	int n = 1000;
	double E_min = 10.0; //eV
	double E_max = 100.0; //eV
	double E;
	double sHI, sHeI, sHeII;
	for(int i=0;i<n;i++)
	{
		E = (E_max-E_min)*((double) i)/((double) n) + E_min;
		sHI   = sigma_HI(E);
		sHeI  = sigma_HeI(E);
		sHeII = sigma_HeII(E);
		printf("%e\t%e\t%e\t%e\n",E,sHI,sHeI,sHeII);
	}

	return 0;
}
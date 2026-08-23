#include <stdio.h>

#define NUM_POINTS 40000000000

int main(int argc, char **argv){
		long long int i;
		double pi=0.0;
		for(i=0;i<NUM_POINTS;i++){
			pi += 4.0/(4.0*(double)i+1.0);
			pi -= 4.0/(4.0*(double)i+3.0);
		}
		printf("%.10lf\n", pi);
		return 0;
}

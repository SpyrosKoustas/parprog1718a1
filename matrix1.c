#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> 

#define numCol 100

void get_walltime ( double *wct) {
	struct timeval tp; 
	gettimeofday (&tp,NULL);
	*wct = (double) (tp.tv_sec + tp.tv_usec / 1000000.0 );

}

int main ()
	{ 
		double *table;	
		double start;
		double end;

		int i;
		int j;

        FILE *fptr;
        fptr = fopen("results_matrix1.csv", "a");
		
		table = (double * )malloc(numCol*numRows*sizeof(double));
			if ( table == 0)
			{
				printf("ERROR");
				return 1;
			}
			
		
		for (i=0; i < 	numCol*numRows; i++){
				table[i] = 1.0;
				
		}
		
		get_walltime(&start);
		for ( i = 0; i < numRows; i++){
			for (j = 0; j < numCol; j++) {
				//Prospellash ana grammh
				table[i*numCol+j]++;	
			}
		}
		
		get_walltime(&end);
		
		for (i = 0; i <  numCol*numRows; i++) {
			if ( table[i] != 2.0 )
			{ 
				printf ( "ERROR not 2.0\n" );
				break;
			}
		}
		
		double time = end - start ;
		double mega = (2.0*numRows*numCol)/(time*1e6);
        fprintf(fptr, "%lf, %lf\n", time, mega);
		printf ( "Time = %lf\n" , time ) ; 
		printf ( "Megaaccess/sec = %lf\n" , mega ) ; 
		printf ("Success! \n" );
        fclose(fptr);
		free(table);

		return 0 ;

}

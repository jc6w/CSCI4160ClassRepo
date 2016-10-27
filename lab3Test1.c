/* Calculate the inverse of a matrix no bigger than 10X10
   using modified Gaussian Elimination
   Assumption:  The matrix is invertible
*/
#include <stdio.h>



int main()
{
    float mat[10][10] ;
    float inverse[10][10] = {1,0,0,0,0,0,0,0,0,0,
                   0,1,0,0,0,0,0,0,0,0,
                   0,0,1,0,0,0,0,0,0,0,
                   0,0,0,1,0,0,0,0,0,0,
                   0,0,0,0,1,0,0,0,0,0,
                   0,0,0,0,0,1,0,0,0,0,
                   0,0,0,0,0,0,1,0,0,0,
                   0,0,0,0,0,0,0,1,0,0,
                   0,0,0,0,0,0,0,0,1,0,
                   0,0,0,0,0,0,0,0,0,1};
    int size = 10,i,j,k;
    float div;
    float mul;

    /*//Read in the matrix
    printf( "input size ");
    scanf("%d",&size); */

    printf ("input the matrix\n");
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            scanf("%f", &mat[i][j]);
#pragma omp parallel num_threads(size)
		   {
		#pragma omp for
    /* Create inverse */
    for(i=0;i<size;i++)
    {
        /* Divide row i by the main diagonal element
           Assumption:  It will not be zero
        */
        div = mat[i][i];
	    
	
	
		for(j=0;j<size;j++)
		{
		mat[i][j] /= div;
		inverse[i][j] /= div;
		}
        /* For all other rows != i get zeros in column i
        */
        for(k=0;k<size;k++)
        {
            if(k != i)
            {
                /* Multiply row i by negative what is in
                   row k column i
                   and then add the result to row k
                */
                mul = -mat[k][i];
			//#pragma omp for
			for(j=0;j<size;j++)
			{
			mat[k][j] += mat[i][j]*mul;
			inverse[k][j] += inverse[i][j]*mul;
			}
            }
        }
    }
}
    printf( "The inverse is \n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            printf("%.3f ", inverse[i][j]);
        printf("\n");
    }

    return 0;
}
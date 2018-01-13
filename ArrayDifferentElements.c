/*	I Pledge my Honor that I have not cheated, and will not cheat, on this assignment - Si Dang
	The program is using arrays to find the different elements of 2 arrays and print out 
	the complements of 2 array in range 0 to 9. Using arrays of 0s and 1s.
	The program is using pointers arithmetic in functions
	The program was wittern by Si Dang #U25273656 
*/

#include<stdio.h>

//functions declaration
void set_difference(int *a, int *b, int n, int *difference);
void set_complement(int *a, int n, int *complement);

//main function
int main(void)
{
    //arrays declaration
    int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int difference[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int complement[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    //variables declaration
	int N, M;
    int i = 0, j = 0;
    int ele;

	//prompt user enter values
	/*array a*/
    printf("Please enter the number of elements in set A: ");
    scanf("%d", &N);
    printf("Enter the numbers in set A: ");
    for(i = 0; i < N; i++)
        {
		    scanf("%d", &ele);
        	a[ele] = 1;
        }
	
	/*array b*/
    printf("Please enter the number of elements in set B: ");
    scanf("%d", &M);
    printf("Enter the numbers in set B: ");
    for(j = 0; j < M; j++)
        {
            scanf("%d", &ele);
            b[ele] = 1;
        }

    //Display the difference of 2 arrays  
    printf("Difference of A and B: ");
    //function called
    set_difference(a, b, 10, difference);
    //using for-loop to display all elements of arrays
    for(i = 0; i < 10; i++)
        {
            if(difference[i] == 1) /*based on the result in function set_difference*/
            	{
                	printf("%d ", i);
				}
        }
    
	//Display the complement of arrays
	/*array A*/    
    printf("\n");
    printf("Complement of A: ");
    //function called
    set_complement(a, 10, complement);
    for(i = 0; i < 10; i++)
        {
            if(complement[i] == 1)
				{
                	printf("%d ", i);
                }
        }

	/*array B*/
    for(i = 0; i < 10; i++)
		{
            complement[i] = 0;
		}
		 
    printf("\n");
    printf("Complement of B: ");
    //function called
    set_complement(b, 10, complement);
    for(j = 0; j < 10; j++)
        {
            if(complement[j] == 1)
				{
                	printf("%d ", j);
				}
        }
        printf("\n");
	return 0;
}

//function finding difference elements
void set_difference(int *a, int *b, int n, int *difference)
{
	//pointers and variables declaration
    int *Pa = a;
    int *Pb = b;
    int *Pd = difference;
    int *Pan= a + n; 
    int *Pbn = b + n; 
    
    //finding the differences
    for(; Pa != Pan && Pb != Pbn; ++Pa, ++Pb, ++Pd) //checking through arrays to find the difference then increasing the index
		{
			//it will be 1 if elements of A are not same elements of B
        	if( *Pa == 1 && *Pb == 0 )
				{
            		*Pd = 1;
				}
   		}
}
//function finding complements
void set_complement(int *a, int n, int *complement)
{
	//pointers and variables declaration
    int *Pa = a;
    int *Pc = complement;
    int *P = a + n;
    
    for(; Pa != P; ++Pa, ++Pc) //array a's elements are not same a[i], increasing array a and array complement
		{
			//if arrays have an element in range 0-9, complement function will through that elements away.
        	if( *Pa == 0)
				{
            		*Pc= 1; 
				}
		}
}

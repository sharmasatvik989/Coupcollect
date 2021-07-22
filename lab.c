#include <stdio.h>
#include<stdlib.h>

//  Initilization of the funcitons to be used for calculation of empirical and theoretical value.

long double bercoe(int n, int r);

int mathpo(int base, int exp);

void sos(int tnc,int cof,int cose, double ftp, double stp);

void empva(int tnc , int cof, int cose , double ftp , double stp);

long double arr[1001][1001] = { 0 }; 

void init();



//without using power function we have created a function to return the value of it.


int mathpo(int no, int exp)  
 {

    int endre = 1;

    while (exp != 0) 
    {

        endre *= no;

        --exp;

    }

    return endre;

 }
 
 // we use pascals triangle to work on combiantions

long double bercoe(int n, int r)

{

    if (n<r)

    {

        return 0;

    }

    return arr[n][r];

}


void init()

{

    arr[0][0] = 1;

    int i;

    for (i = 1; i < 1001; i++) 
    {

        arr[i][0] = 1;

        int j;

        for (j = 1; j < i + 1; j++) 
        {

            arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]);

        }

    }

}






// the main function which takes the coupons and probability of first type.

int main() 

{

    

    init();

    int tnc ;

    int cof;

    printf("Enter total number of coupons and number of coupons of first type \n");

    scanf("%d%d", &tnc, &cof);

    

    if (cof> tnc)

        {

           printf("First type cannot be greater than total number of coupons \n");

           exit(1);

       }

    int cose = tnc -cof;

    printf("Enter the probability of each coupon of first type\n");

    double ftp;

    scanf("%lf", &ftp);

    double fpp= ftp * cof;

    double stp = ((1 - fpp)/cose);

    printf("Second type probability %lf\n", stp);

    

    sos(tnc,cof,cose, ftp ,stp); // sum of the sequence for theoretical value

    empva(tnc, cof , cose , ftp, stp); // calling the function for empirical value calculation

    return 0;

}


// function to calculate the theoretical value


void sos  (int tnc,int cof ,int cose, double ftp, double stp)

{

    long double theo = 0; 
    mathpo(-1, (tnc - 1)); 
    int iterc = 0;

    int sen;

    for (sen = 0; sen  < tnc; sen++)

   {
 

       double setsu = 0;

       int value = mathpo(-1, (tnc - 1 - sen));

       int ss;

       for (ss = 0; ss <= sen; ss++)

        {

        int rev = sen - ss;

        long double value1 = bercoe(cof, ss) * bercoe(cose, rev); // calls the function to return the combiantions



        if (value1 > 0)
        
        {

        long double den = (ss * ftp) + (rev * stp);

        long double curse = value1/(1 - den);


        setsu += curse;

            iterc++;

        }

    }

       setsu*= value;

       theo +=  setsu;

   }

    printf("Theoritical sum is %Lf  count %d\n", theo, iterc);

}


// function to calculate the empirical value 



void empva(int tnc,int cof,int cose, double ftp, double stp) 
{

    long double tt = 0.0;

    int emp;

    printf("Enter # of iterations for empirical\n");

    scanf("%d", &emp);

    printf("Enter seed: \n");

    int seed;

    scanf("%d",&seed);

    int iter;

    int i;

    for (i = 0; i< emp; i++) 
    
    {

        int *samsp = (int *)calloc(tnc, sizeof(int));

        iter = 0;

        int sum = 0;

        while (sum != tnc)
        {

            int temp = rand()%1000000 + 1;

            long double calpr = temp/1000000.00;

            if (calpr <= cof * ftp)
            {

                int cal = rand()%cof;

                if (samsp[cal] == 0)
                {

                    samsp[cal] = 1;

                    sum++;

                }

            } 
            
            else 
            {

                int cal = rand()%cose + cof;

                if (samsp[cal] == 0) 
                {

                    samsp[cal] = 1;

                    sum++;

                }

            }

            iter++;

        }

        tt += iter;

        free(samsp);

    }
    
    long double empiricalvalu = tt/emp;

    printf("Empiricial number opf Boxes: %Lf\n", empiricalvalu);

}

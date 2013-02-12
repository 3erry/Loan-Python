//David Berry
//10/16/12
//COP 3223
//Section 4: Program 6: Loan

#include <stdio.h>

double constant = 100;
double monthsofyear = 12;

int main()
{
    double pay, yrate, value, owed, mrate, close;
    int i = 1, month = 1;

    //ask the user certain variables
    printf("What is the value left on the mortgage?\n");
    scanf("%lf",&value);

    printf("What is the annual interest rate of the loan, in percent?\n");
    scanf("%lf",&yrate);
    mrate = (yrate/constant)/monthsofyear;


    printf("What is the monthly payment?\n");
    scanf("%lf",&pay);

    //Start with the title of the chart and first input, only need one of these so it comes before the for loop.
    printf("Months   Payment    Amount Owed\n");

    owed = (value+(value*mrate))-pay;
    printf("%d     %.2lf      %.2lf\n",month, pay, owed);

    for(i = 1; owed > 0; i++)
    {
        owed = (owed + (owed*mrate)) - pay;
        month++;
        printf("%d      %.2lf      %.2lf\n",month,pay, owed);

        if(owed-pay <=0)
        {
            pay = (owed*mrate)+owed;
            owed = 0;
            month++;
            printf("%d      %.2lf      %.2lf\n",month,pay, owed);
            break;
        }
    }

    printf("What is the loan refinance annual interest rate, in percent?\n");
    scanf("%lf",&yrate);
    mrate = (yrate/constant)/monthsofyear;

    printf("What is the closing cost of the loan?\n");
    scanf("%lf",&close);

    printf("Here is a revised payment chart:\n");

    return 0;
}


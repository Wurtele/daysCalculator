#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *   Program name: daysCalculatorB.c
 *   Author: Owen Wurtele
 */

int main ( int argc, char *argv[] ) {

   /* Names of the months */
   char *monthName[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September",
                      "October", "November", "December" };

   /* The number of days in each month */
   int monthLength1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   int monthLength2[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   int monthStart1[12] = { 1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
   int monthStart2[12] = { 1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

   int dd1 = 0;
   int mm1 = 0;
   int yyyy1 = 0;
   int dd2 = 0;
   int mm2 = 0;
   int yyyy2 = 0;

   int i;

   int doy1 = 0;
   int doy2 = 0;

   int diff = 0;

   if ( argc < 7 ) {
      printf ( "Usage: ./dates dd mm yyyy dd mm yyyy \n" );
      exit ( 1 );
   } else {
      dd1 = atoi ( argv[1] );
      mm1 = atoi ( argv[2] );
      yyyy1 = atoi ( argv[3] );
      dd2 = atoi ( argv[4] );
      mm2 = atoi ( argv[5] );
      yyyy2 = atoi ( argv[6] );
   }


   if ( yyyy1%4==0 && ( yyyy1%100!=0 || yyyy1%400==0 ) ) {
      monthLength1[1] = 29;
      for (i=2; i<12; i++) {
        monthStart1[i]++;
      }
   }
   if ( yyyy2%4==0 && ( yyyy2%100!=0 || yyyy2%400==0 ) ) {
      monthLength2[1] = 29;
      for (i=2; i<12; i++) {
        monthStart2[i]++;
      }
   }

   /* Error calculator  and date stuff*/
   if ( mm1<1 || mm1>12 ) {
      printf ( "Error - the month entered (%d) is not in the proper range (1-12)\n", mm1 );
      exit ( 1 );
   } if ( mm2<1 || mm2>12 ) {
      printf ( "Error - the month entered (%d) is not in the proper range (1-12)\n", mm2 );
      exit ( 1 );
   } if ( dd1<1 || dd1>monthLength1[mm1-1] ) {
      printf ( "Error - you entered %d for the day and that is not in the range (1-%d)\n", dd1, monthLength1[mm1-1] );
      exit ( 1 );
   } if ( dd2<1 || dd2>monthLength2[mm2-1] ) {
      printf ( "Error - you entered %d for the day and that is not in the range (1-%d)\n", dd2, monthLength2[mm2-1] );
      exit ( 1 );
   }

   if (argc > 7) {
     if ( strcmp( "include", argv[7])==0) {
       dd2 = dd2 + 1;
     }
   }

   /* End area */

   doy1 = monthStart1[mm1-1] + dd1 - 1;
   doy2 = monthStart2[mm2-1] + dd2 - 1;

   if (doy1 > doy2) {
     printf ( "Error - Start date occurs after end date\n");
     exit ( 1 );
   }

   diff = doy2 - doy1;
   printf("%d\n",diff);

   return ( 0 );
}

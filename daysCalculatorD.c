#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 *   Program name: daysCalculatorD.c
 *   Author: Owen Wurtele
 */

int main ( int argc, char *argv[] ) {

   /* The number of days in each month */
   int monthLength1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   int monthLength2[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   int monthStart1[12] = { 1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
   int monthStart2[12] = { 1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

   time_t now;
   time(&now);

   char dayStr1[3];
   char monthStr1[3];
   char yearStr1[5];

   char dayStr2[3];
   char monthStr2[3];
   char yearStr2[5];

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

   if ( argc < 3 ) {
      printf ( "Usage: ./dates dd-mm-yyyy dd-mm-yyyy \n" );
      exit ( 1 );
   } else {

      if ( strcmp(argv[1],"today")==0) {
        struct tm *local = localtime(&now);   /* date and time got from techiedelight.com hint */
        dd1 = local->tm_mday;
        mm1 = local->tm_mon + 1;
        yyyy1 = local->tm_year + 1900;
      } else {
        dayStr1[0] = argv[1][0];
        dayStr1[1] = argv[1][1];
        dayStr1[2] = '\0';

        monthStr1[0] = argv[1][3];
        monthStr1[1] = argv[1][4];
        monthStr1[2] = '\0';

        yearStr1[0] = argv[1][6];
        yearStr1[1] = argv[1][7];
        yearStr1[2] = argv[1][8];
        yearStr1[3] = argv[1][9];
        yearStr1[4] = '\0';

        dd1 = atoi (dayStr1);
        mm1 = atoi (monthStr1);
        yyyy1 = atoi(yearStr1);
      }

      if ( strcmp(argv[2],"today")==0) {
        struct tm *local = localtime(&now);   /* date and time got from techiedelight.com hint */
        dd2 = local->tm_mday;
        mm2 = local->tm_mon + 1;
        yyyy2 = local->tm_year + 1900;
      } else {
        dayStr2[0] = argv[2][0];
        dayStr2[1] = argv[2][1];
        dayStr2[2] = '\0';

        monthStr2[0] = argv[2][3];
        monthStr2[1] = argv[2][4];
        monthStr2[2] = '\0';

        yearStr2[0] = argv[2][6];
        yearStr2[1] = argv[2][7];
        yearStr2[2] = argv[2][8];
        yearStr2[3] = argv[2][9];
        yearStr2[4] = '\0';

        dd2 = atoi(dayStr2);
        mm2 = atoi(monthStr2);
        yyyy2 = atoi(yearStr2);
      }
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

   if (argc > 3) {
     if ( strcmp( "include", argv[3])==0) {
       dd2 = dd2 + 1;
     }
   }

   /* End area */

   doy1 = monthStart1[mm1-1] + dd1 - 1;
   doy2 = monthStart2[mm2-1] + dd2 - 1;

   diff = doy2 - doy1;



   printf("%d\n",diff);

   return ( 0 );
}

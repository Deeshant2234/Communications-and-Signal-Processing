#include <stdio.h>
#include "common_functions.h"
#include<math.h>
int main(void){

//Initialization of variables for Low Pass Filter Function
int N1=39; //Number of taps or samples
int fc1=400; //cut-off frequency in Hz
double PI=3.14;
double wc1=PI/2; // cut-off frequency in radians/sec
double hd1_positive_side[(N1-1)/2]; //positive array for positive of hd[n]
double hd1_negative_side[(N1-1)/2]; //negative array for negatives of hd[n]
double w1[N1-1];  //array for window sequence
double h1[(N1-1)/2]; //Low pass filter response in discrete time domain

//Initialization of variables for High Pass Filter Function
int N2=39; //Number of taps or samples
int fc2=1200;
int fs2=4800;
double wc2=2*PI*(fc2/fs2);
double hd2_positive_side[(N2-1)/2];
double hd2_negative_side[(N2-1)/2];
double w2[N2-1];
double h2[(N2-1)/2];



//Initialization of variables for Band Pass Filter Function
int N3=39; //Number of taps or samples
double fc3_1=500;
double fc3_2=1200;
double fs3=6000;
double wc3_1=2*3.14*(fc3_1/fs3);
double wc3_2=2*3.14*(fc3_2/fs3);
double hd3_positive_side[(N3-1)/2];
double hd3_negative_side[(N3-1)/2];
double w3[N3-1];
double h3[(N3-1)/2];



//Calling a Low pass filter function

Low_pass_Filter(hd1_positive_side, hd1_negative_side, w1, h1, N1, wc1, fc1);

//Printing hd1[n], w1[n] and output h1[n]
printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("LOW PASS FILTER DESIGN \n");
printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("Values of hd1[n]\n");

for(int i=-(N1-1)/2; i<0;i++)
    {
   printf(" hd1[%d] : %f\n",i,hd1_negative_side[-i]);
    }

for(int i=0; i<=(N1-1)/2;i++)
     {
   printf(" hd1[%d] : %f\n",i,hd1_positive_side[i]);
     }



printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("Values of w1[n]\n");

for(int i=0; i<=(N1-1);i++)
    {
   printf(" w1[%d] : %f\n",i,w1[i]);
    }



printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("Output of a Low Pass Filter h1[n] for wc1=pi/2 \n");

for(int i=-(N1-1)/2; i<0;i++)
    {

          int p=0;
          h1[-i]=hd1_negative_side[-i]*w1[p];
          p=p+1;

        printf(" h1[%d] : %f\n",i,h1[-i]);
    }

for(int i=0; i<=(N1-1)/2;i++)
     {
        h1[i]=hd1_positive_side[i]*w1[i+((N1-1)/2)];
        printf(" h1[%d] : %f\n",i,h1[i]);

     }

printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");

//changing value of cut-off frequency
wc1=PI/4;

// calling a low pass filter function again
Low_pass_Filter(hd1_positive_side, hd1_negative_side, w1, h1, N1, wc1, fc1);

//Printing output h1[n] again
printf("Output of a Low Pass Filter h1[n] for wc1=pi/4 \n");

for(int i=-(N1-1)/2; i<0;i++)
    {
          int p=0;
          h1[-i]=hd1_negative_side[-i]*w1[p];
          p=p+1;

        printf(" h1[%d] : %f\n",i,h1[-i]);
    }

for(int i=0; i<=(N1-1)/2;i++)
     {
        h1[i]=hd1_positive_side[i]*w1[i+((N1-1)/2)];
        printf(" h1[%d] : %f\n",i,h1[i]);
     }


// Calling High pass filter function
High_pass_Filter(hd2_positive_side, hd2_negative_side, w2, h2, N2, fs2, wc2, fc2);

//Printing hd2[n], w2[n] and output h2[n]
printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("HIGH PASS FILTER DESIGN \n");
printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("Values of hd2[n]\n");

for(int i=-(N2-1)/2; i<0;i++)
    {
   printf(" hd2[%d] : %f\n",i,hd2_negative_side[-i]);
    }

for(int i=0; i<=(N2-1)/2;i++)
     {
   printf(" hd2[%d] : %f\n",i,hd2_positive_side[i]);
     }



printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("Values of w2[n]\n");

for(int i=0; i<=(N2-1);i++)
    {
   printf(" w2[%d] : %f\n",i,w2[i]);
    }



printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("Output of a High Pass Filter h2[n]\n");

for(int i=-(N2-1)/2; i<0;i++)
    {

          int p=0;
          h2[-i]=hd2_negative_side[-i]*w2[p];
          p=p+1;

        printf(" h2[%d] : %f\n",i,h2[-i]);
    }

for(int i=0; i<=(N2-1)/2;i++)
     {
        h2[i]=hd2_positive_side[i]*w2[i+((N2-1)/2)];
        printf(" h2[%d] : %f\n",i,h2[i]);

     }


// calling Bandpass filter function
Band_pass_Filter(hd3_positive_side, hd3_negative_side, w3, h3, N3, fs3, wc3_1, wc3_2, fc3_1, fc3_2 );

//Printing hd3[n], w3[n] and output h3[n]
printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("BAND-PASS FILTER DESIGN \n");
printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("Values of hd3[n]\n");

for(int i=-(N3-1)/2; i<0;i++)
    {
   printf(" hd3[%d] : %f\n",i,hd3_negative_side[-i]);
    }

for(int i=0; i<=(N3-1)/2;i++)
     {
   printf(" hd3[%d] : %f\n",i,hd3_positive_side[i]);
     }



printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("Values of w3[n]\n");

for(int i=0; i<=(N3-1);i++)
    {
   printf(" w3[%d] : %f\n",i,w3[i]);
    }



printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("Output of a Band Pass Filter h3[n]\n");

for(int i=-(N3-1)/2; i<0;i++)
    {
          int p=0;
          h3[-i]=hd3_negative_side[-i]*w3[p];
          p=p+1;
        printf(" h3[%d] : %f\n",i,h3[-i]);
    }

for(int i=0; i<=(N3-1)/2;i++)
     {
        h3[i]=hd3_positive_side[i]*w3[i+((N3-1)/2)];
        printf(" h3[%d] : %f\n",i,h3[i]);

     }



}

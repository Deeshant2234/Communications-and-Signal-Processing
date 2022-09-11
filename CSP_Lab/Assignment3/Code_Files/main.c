#include <stdio.h>
#include "common_functions.h"
#include<math.h>
#define PI 3.1415926

int main(void){

//Initialization of variables for Low Pass Filter Function

// For M=L=2
printf("---------------------------------------------------------------------------------------------------------------------\n");
printf("-------------------------------------------------For M=L=2 and fc=600Hz---------------------------------------------------------\n");

double fc=600;   //cut-off frequency in Hz
double fs=2400;  //cut-off frequency in Hz
int M=2;       // Downscaling factor
int L=2;       // Upscaling Factor
int N=39;      //Number of taps or samples
double wc=2*PI*(fc/fs);       // Cut-off of Anti Aliasing Filter
double x[48];     // Input Signal with 48 samples
double hd[N];     // Response of Anti Aliasing Filter
double w[N];      // Hamming window function
double h[N];      // Practical Response of Anti Imaging filter
double xf[48+N-1];    // xf-(Lh-1/2)samples from start and end
double xd[48/M];    // Downsampler output
double xu[48];    // Upsampler output
double y[48+N-1];     // y-(Lh-1/2)samples from start and end
double e[48];     // error array e[n]=x[[n]-y[n]

// Calling a Decimation and Interpolation function
decimation_interpolation(x,hd,w,h,xf,xd,xu,y,e,fs,fc,N,M,L,wc);


// Printing Input Signal
printf(" INPUT SIGNAL : x[n]  \n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
for(int i=0; i<=47;i++)
    {
   printf( "x[%d] : %f\n",i,x[i]);
    }


// Printing Desired Response of anti Aliasing filter
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
printf(" DESIRED RESPONSE OF LPF/ ANTI ALIASING FILTER : hd[n]  \n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
for(int i=0; i<=(N-1);i++)
    {
   printf(" hd[%d] : %f\n",i,hd[i]);
    }

// Printing Window funtion
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
printf(" WINDOW FUNCTION w[n]  \n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
for(int i=0; i<=(N-1);i++)
    {
   printf(" w[%d] : %f\n",i,w[i]);
    }

// Printing Alti aliasing fitler practical response
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
printf(" ANTI ALIASING FILTER RESPONSE : h[n] FOR wc=pi/M  \n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
for(int i=0; i<=(N-1);i++)
    {
   printf(" h[%d] : %f\n",i,h[i]);
    }

//Printing output of LPF
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
printf("OUTPUT OF ANTI ALIASING FILTER i.e. xf[n]=xf-(Lh-1/2)  \n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
for(int i=0; i<=47;i++)
    {
   printf(" xf[%d] : %f\n",i,xf[i]);
    }


// Decimated Output
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
printf(" DECIMATED OUTPUT FOR M=2 \n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");

for(int i=0; i<=((48/M)-1);i++)
    {
   printf(" xd[%d] : %f\n",i,xd[i]);
    }

// Printing UPSAMPLER OUTPUT
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
printf(" UPSAMPLER OUTPUT FOR L=2 \n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");

for(int i=0; i<=47;i++)
    {
   printf(" xu[%d] : %f\n",i,xu[i]);
    }

// Printing output of a anti imaging filter
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
printf(" OUTPUT of ANTI IMAGING FILTER y[n] : y-(Lh-1/2  \n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");

for(int i=0; i<=47;i++)
    {
   printf("y[%d] : %f\n",i,y[i]);
    }

//Printing error array
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
printf(" ERROR: e[n]= y[n]-x[n]\n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");

for(int i=0; i<=47;i++)
    {
   printf("e[%d] : %f\n",i,e[i]);
    }

//Average error
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
printf(" AVERAGE ERROR");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");

double sum=0;
double avg_error=0;
for(int i=0; i<=47;i++)
    {
        sum=sum+e[i];

    }
     avg_error=sum/48;
printf("Average Error : %f\n",avg_error);

// For M=L=3
printf("---------------------------------------------------------------------------------------------------------------------\n");
printf("---------------------------------------------------For M=L=3 and fc=400Hz---------------------------------------------------------\n");

// Changing values
fc=400;   //cut-off frequency in Hz
M=3;       // Downscaling factor
L=3;       // Upscaling Factor
N=39;      //Number of taps or samples
wc=2*PI*(fc/fs);       // Cut-off of Anti Aliasing Filter




// Calling Decimation and Interpolation Function
decimation_interpolation(x,hd,w,h,xf,xd,xu,y,e,fs,fc,N,M,L,wc);

// Printing Input Signal

printf(" INPUT SIGNAL : x[n]  \n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
for(int i=0; i<=47;i++)
    {
   printf( "x[%d] : %f\n",i,x[i]);
    }

// Printing y[n]
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
printf(" OUTPUT of ANTI IMAGING FILTER y[n] : y-(Lh-1/2  \n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");

for(int i=0; i<=47;i++)
    {
   printf("y[%d] : %f\n",i,y[i]);
    }


// Printing error array
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
printf(" ERROR: e[n]= y[n]-x[n]\n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");

for(int i=0; i<=47;i++)
    {
   printf(" e[%d] : %f\n",i,e[i]);
    }

// Printing Average Error
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
printf(" Average Error\n");
printf("------------------------------------------- \n");
printf("------------------------------------------- \n");
sum=0;
avg_error=0;
for(int i=0; i<=47;i++)
    {
        sum=sum+e[i];

    }
     avg_error=sum/48;
printf("Average Error : %f\n",avg_error);


}

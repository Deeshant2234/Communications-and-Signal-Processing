#include <stdio.h>
#include "common_functions.h"
#include<math.h>
#define PI 3.1415926535

void decimation_interpolation(double x[],double hd[], double w[], double h[], double xf[], double  xd[], double  xu[], double  y[], double e[], double fs, double fc, int N, int M, int L, double wc)
{
int f0=100;
int f1=200;
int f2=300;

// -------------------------------------------------DECIMATION OF INPUT SIGNAL x[n]---------------------------------------------------

// x[n]: Input samples
int q=-24;
for(int n=0; n<=47;n++,q++)
   {
          x[n]=sin((2*PI*f0*q)/fs) + (0.5*sin((2*PI*f1*q)/fs))  + (0.6*sin((2*PI*f2*q)/fs)) ;
   }

// Anti-Aliasing Filter Design with cutoff=pi/M
int p=-(N-1)/2;
for(int n=0; n<=(N-1);n++,p++)
    {
      if(p!=0)
      {
          hd[n]=(sin(wc*p))/(PI*p);
      }
      else
      {
          hd[n]=wc/PI;
      }
    }

// Hamming Window Function
for(int n=0; n<=(N-1);n++)
    {
      w[n]=0.54-(0.46*cos((2*PI*n)/(N-1))); //for loop to enter values in wn[] based upon hamming window function.
    }

// Impulse Response of a LPF
for(int n=0; n<=(N-1); n++)
    {
      h[n]=hd[n]*w[n];
    }



//Output of a Anti- Aliasing Filer: Convolution of x[n] and h[n] :
for(int n=0; n<=85;n++)
    {
      xf[n]=0;
      int Gain1=1;
      for(int k=0; k<=n;k++)
       {
          if((k<=47)&&((n-k)<=(N-1)))
            {
            xf[n]+=Gain1*x[k]*h[n-k];
            }
       }
     }


// Discarding (Lh-1)/2 from staring and end of xf[n]
int k=19;
for(int n=0; n<=47;n++,k++)
    {
      xf[n]=xf[k];
    }


// Downsampling of xf[n]
for(int i=0; i<=((48/M)-1);i++)
    {  xd[i]=0;
       xd[i]+=xf[M*i];
    }

// -------------------------------------------------INTEROLATION OF RECEIVED SIGNAL xd[n]---------------------------------------------------

// Upsampling of xd[n]
for(int i=0; i<=47;i++)
    {
       xu[i]=xd[i/L];
        if(i%L==0)
        {
        xu[i]=xd[i/L];
        }
        else
        {
          xu[i]=0;
        }
    }

// Anti-Imaging Filter Design Output: Convolution of xu[n] and h[n] : Cut off = Pi/L and Gain= L
for(int n=0; n<=(48+N-2);n++)
    {
      y[n]=0;
      for(int k=0; k<=n;k++)
       {
          int Gain2=L;
          if((k<=47)&&((n-k)<=(N-1)))
            {
            y[n]+=Gain2*xu[k]*h[n-k];
            }
       }
    }

// Discarding (Lh-1)/2 from staring and end of y[n]
int j=19;
for(int n=0; n<=47;n++,j++)
    {
      y[n]=y[j];
    }

// Error : Difference between x[n] and y[n]
for(int n=0; n<=47;n++)
    {
      e[n]=y[n]-x[n];
    }

}

#include <stdio.h>
#include "common_functions.h"


//function for convolution of two sequence

void convolution(float x1[], int lenx1, float h1[], int lenh1,float y1[], int leny1)
{

  for(int n=0; n<leny1;n++)
    {
      y1[n]=0;
      for(int k=0; k<=n;k++)
       {
          if((k<=(lenx1-1))&&((n-k)<=(lenh1-1)))
            {
            y1[n]+=x1[k]*h1[n-k];
            }
       }

    }

}




//function for Correlation of two sequence

void correlation(float x2[], int lenx2, float y2[], int leny2, float R_xy[], int lenR_xy)
{

      int p=leny2-1;
      float h2[leny2];

    for(int i=0;i<leny2;i++)  // Loop to time reverse the sequence 2
    {
      h2[i]= y2[p];
      p=p-1;
    }

    for(int n=0; n<lenR_xy;n++) //Loop to convolve one signal with time reversed of other signal
    {
        R_xy[n]=0;
      for(int k=0; k<=n;k++)
       {
          if((k<=(lenx2-1))&&((n-k)<=(leny2-1)))
            {
            R_xy[n]+=x2[k]*h2[n-k];
            }
       }
    }

}





//function for Downsampling of a given sequence

void downsampling(float x3[], int lenx3,float y3[], int leny3,float y4[], int leny4)
{

   for(int i=0; i<leny3;i++)
    {  int D=2;
       y3[i]=x3[D*i];
    }

   for(int i=0; i<leny4;i++)
    { int D=3;
      y4[i]=x3[D*i];
    }
}




//function for Upsampling of a given sequence
void upsampling(float x4[], int lenx4,float y5[], int leny5,float y6[], int leny6){

for(int i=0; i<leny5;i++)
    {
        int U = 2;
        if(i%2==0)
        {
        y5[i]=x4[i/U];
        }
        else
        {
          y5[i]=0;
        }
    }

   for(int i=0; i<leny6;i++)
   {
       int U=3;
      if(i%3==0)
      {
        y6[i]=x4[i/U];
      }
      else
      {
          y6[i]=0;
      }
   }
}




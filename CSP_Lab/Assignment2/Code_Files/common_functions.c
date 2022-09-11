#include <stdio.h>
#include "common_functions.h"
#include<math.h>

// Function for a Low Pass Filter
void Low_pass_Filter(double hd1_positive_side[],double hd1_negative_side[], double w1[], double h1[],int N1, double wc1, int fc1)
{
    //Since in c-programming indexing is from 0 to n. So, I take two different arrays to store hd1[n] values i.e.,positive and negative side,
    // w1[n] is a array for hamming windowing function
    // wc1, fc1 is the cut-off frequencies in radians/sec and Hz respectively.



      hd1_positive_side[0]=wc1/3.14;

for(int n=1; n<=(N1-1)/2;n++)  // for loop to enter values in positive and negative array hd1[] based upon IFFT of a low pass filter.
    {
      hd1_negative_side[n]=(sin(wc1*-n*0.01744))/(3.14*-n); // every degree of sine or cosine is multiplied with 0.0174(or π/180) to convert it into radians.
      hd1_positive_side[n]=(sin(wc1*n*0.01744))/(3.14*n);
    }

for(int n=0; n<=N1-1;n++)
    {
      w1[n]=0.54-(0.46*cos((2*3.14*n*0.01744)/(N1-1))); //for loop to enter values in wn1[] based upon hamming window function.
    }

}


// Function for a High Pass Filter
void High_pass_Filter(double hd2_positive_side[],double hd2_negative_side[], double w2[], double h2[],int N2, int fs2, double wc2, int fc2)
{
   hd2_positive_side[0]=1-(wc2/3.14);

for(int n=1; n<=(N2-1)/2;n++)  // for loop to enter values in positive and negative array hd2[] based upon IFFT of a High pass filter.
    {
      hd2_negative_side[n]=(sin(3.14*-n*0.01744)/(3.14*-n))-((sin(wc2*-n*0.01744))/(3.14*-n));
      hd2_positive_side[n]=(sin(3.14*n*0.01744)/(3.14*n))-((sin(wc2*n*0.01744))/(3.14*n));
    }

for(int n=0; n<=N2-1;n++)
    {
      w2[n]=0.54-(0.46*cos((2*3.14*n*0.01744)/(N2-1))); //for loop to enter values in wn2[] based upon hamming window function.
    }
}



// Function for a Band Pass Filter
void Band_pass_Filter(double hd3_positive_side[],double hd3_negative_side[], double w3[], double h3[],int N3, double fs3, double wc3_1, double wc3_2, double fc3_1, double fc3_2 )
{
  //wc3_1, fc3_1, wc3_2, and fc3_2 is the lower and upper cut-off frequencies in radians/sec and Hz respectively.
  //fs3 is a sampling frequency.

 hd3_positive_side[0]=(wc3_2-wc3_1)/3.14;

for(int n=1; n<=(N3-1)/2;n++)  // for loop to enter values in positive and negative array hd3[] based upon IFFT of a Band pass filter.
    {
      hd3_negative_side[n]=(sin(wc3_2*-n*0.01744)-(sin(wc3_1*-n*0.01744)))/(3.14*-n);
      hd3_positive_side[n]=(sin(wc3_2*n*0.01744)-(sin(wc3_1*n*0.01744)))/(3.14*n);
    }

for(int n=0; n<=N3-1;n++)
    {
      w3[n]=0.54-(0.46*cos((2*3.14*n*0.01744)/(N3-1)));n//for loop to enter values in wn3[] based upon hamming window function.
    }




}

#include <stdio.h>
#include "common_functions.h"

int main(void){

//Initialization of variables for Convolution Function
float x1[]={0.5377, 1.8339, -2.2588, 0.8622, 0.3188, -1.3077, -0.4336, 0.3426, 3.5784, 2.7694, -1.3499, 3.0349,0.7254, -0.0631, 0.7147, -0.2050, -0.1241, 1.4897, 1.4090,1.4172};
float h1[]={0.6715, -1.2075, 0.7172, 1.6302, 0.4889, 1.0347,0.7269, -0.3034, 0.2939, -0.7873, 0.8884, -1.1471, -1.0689, -0.8095, -2.9443};
int lenx1=20;  //length of x1 array
int lenh1=15;  //length of h1  array
int leny1=lenx1+lenh1-1;  // calculated length of y1 array
float y1[leny1];

//Initialization of variables for Correlation Function
float x2[]={0.5377, 1.8339, -2.2588, 0.8622, 0.3188, -1.3077, -0.4336, 0.3426, 3.5784, 2.7694, -1.3499, 3.0349,0.7254, -0.0631, 0.7147, -0.2050, -0.1241, 1.4897, 1.4090,1.4172};
//length of x2 array
float y2[]={0.6715, -1.2075, 0.7172, 1.6302, 0.4889, 1.0347,0.7269, -0.3034, 0.2939, -0.7873, 0.8884, -1.1471, -1.0689, -0.8095, -2.9443};
//length of y2 array
int lenx2=20;
int leny2=15;
int lenR_xy=lenx2+leny2-1; // calculated length of R_xy i.e correlation output array
float R_xy[lenR_xy];


//Initialization of variables for Downsampling Function
float x3[]={0.3252, -0.7549, 1.3703, -1.7115, -0.1022, -0.2414, 0.3192, 0.3129, -0.8649, -0.0301, -0.1649, 0.6277,1.0933, 1.1093, -0.8637, 0.0774, -1.2141, -1.1135, -0.0068,1.5326, -0.7697, 0.3714, -0.2256, 1.1174, -1.0891, 0.0326,0.5525, 1.1006, 1.5442, 0.0859, -1.4916, -0.7423, -1.0616,2.3505, -0.6156, 0.7481 };
int lenx3= 36;   // length of x3 array
int leny3= (lenx3)/2; // calculated length of y3 array
int leny4= (lenx3)/3;  // calculated length of y4 array
float y3[leny3];
float y4[leny4];


//Initialization of variables for Upsampling Function
float x4[]={0.3252, 1.3703, -0.1022, 0.3192, -0.8649, -0.1649, 1.0933, -0.8637, -1.2141, -0.0068, -0.7697, -0.2256, -1.0891, 0.5525, 1.5442, -1.4916, -1.0616, -0.6156};
int lenx4= 18;   //length of x4 array
int leny5= (lenx4)*2;  // calculated length of y5 array
int leny6= (lenx4)*3;  // calculated length of y6 array
float y5[leny5];
float y6[leny6];


// Calling a Convolution Function
convolution(x1,lenx1,h1,lenh1,y1,leny1);
   printf("CONVOLUTION OF TWO SIGNALS\n");
// printing a output of covolution
for(int i=0; i<leny1;i++){
    printf("y1[%d] : %f\n",i,y1[i]);
}

printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("CROSS-CORRELATION OF TWO SIGNALS\n");
correlation(x2,lenx2,y2,leny2,R_xy,lenR_xy);

  for(int i=0; i<lenR_xy;i++){
   printf(" R_xy[%d] : %f\n",i,R_xy[i]);

     }



 // Calling a Downsampling Fuction
downsampling(x3,lenx3,y3,leny3,y4,leny4);

// Printing a Downsampling Function i.e. downsampled by factor of 2
printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("DOWNSAMPLING BY FACTOR OF 2\n");
for(int i=0; i<leny3;i++){
printf("y3[%d] : %f\n",i,y3[i]);
}

// Printing a Downsampling Function i.e. downsampled by factor of 3
printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("DOWNSAMPLING BY FACTOR OF 3\n");
for(int i=0; i<leny4;i++){
printf("y4[%d] : %f\n",i,y4[i]);
}


//Calling a Upsampling Function
upsampling(x4,lenx4,y5,leny5,y6,leny6);

// Printing a Upsampling Function i.e. Upsampled by factor of 2
printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("UPSAMPLING BY FACTOR OF 2\n");
for(int i=0; i<leny5;i++){
printf("y5[%d] : %f\n",i,y5[i]);
}

// Printing a Upsampling Function i.e. Upsampled by factor of 3
printf("--------------------------------------------------------------------------\n");
printf("--------------------------------------------------------------------------\n");
printf("UPSAMPLING BY FACTOR OF 3\n");
for(int i=0; i<leny6;i++){
printf("y6[%d] : %f\n",i,y6[i]);
}

return 0;
}

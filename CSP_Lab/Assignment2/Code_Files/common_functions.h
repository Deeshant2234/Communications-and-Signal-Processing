//Declaring Low pass filter function Function
void Low_pass_Filter(double hd1_positive_side[],double hd1_negative_side[], double w1[], double h1[],int N1, double wc1, int fc1);
//Declaring High pass filter function Function
void High_pass_Filter(double hd2_positive_side[],double hd2_negative_side[], double w2[], double h2[],int N2, int fs2, double wc2, int fc2);
//Declaring Band pass filter function Function
void Band_pass_Filter(double hd3_positive_side[],double hd3_negative_side[], double w3[], double h3[],int N3, double fs3, double wc3_1, double wc3_2, double fc3_1, double fc3_2 );

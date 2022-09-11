clear ; % erasing all previous data in our workspace
clc;       % clearing our command window

%GENERATING AND VERIFYING 10-ORTHOGONAL SIGNALS

T=0.00005;   % Defining time period of first signal
N=10;      % Total number of orthogonal signal we want to generate
f=1/T;     % frequency [Hz]
t=(0:1/(f*100):T); 
phi=0; %phase of the signal
s=0;  % variable to hold sum of all the signals
 
for i=1:N           %for loop to generate N number of orthogonal signals each with different frequency to other
    y=sin(2*pi*i*f*t+phi);  % generated sin wave with frequency i*f
    s=s+y;           %sum of all the signals
   switch i          % switch statement to put different signals to different variables
       case 1
           y1=y;
       case 2
           y2=y;    
       case 3
           y3=y;
       case 4
           y4=y;
       case 5
           y5=y;
       case 6
           y6=y;
       case 7
           y7=y;
       case 8
           y8=y;
       case 9
           y9=y;
       case 10
           y10=y;  
           
    subplot(1,2,1);   % plot to plot all N-signals in a single graph
    plot(t,y1);
    axis([0 T -2 2]); 
    hold on;
    title("Plot of 10-Orthogonal Signals")
    xlabel('time(s)');  
    ylabel('amplitude(V)'); 
    plot(t,y2);   plot(t,y3);   plot(t,y4);  plot(t,y5);  plot(t,y6);  plot(t,y7);
    plot(t,y8);  plot(t,y9); plot(t,y10);
    hold off;  
   end
 
end
    
subplot(1,2,2) % plot to summation of all N-signals in a single graph
plot(t,s);
axis([0 T -2 2])
title("Plot of Summation of 10-Orthogonal Signals");
xlabel('time(s)');
ylabel('amplitude(V)');

%Stacking all signal matrices as a column of a Single matrix
A=[transpose(y1) transpose(y2) transpose(y3) transpose(y4) transpose(y5) transpose(y6) transpose(y7) transpose(y8) transpose(y9) transpose(y10)];

%Calling Orthogonality check function to check pairwise orthogonality of
%all signals i.e. stacked in A matrix

Product=Orthogonality_Check_Function(A); 

%Product matrix contain all results of orthogonality condition i.e
%if two signals are orthogonal their product value equals O otherwise
%non-zero.


%GENERATING AND VERIFYING TWO NON-ORTHOGONAL SIGNALS
N1=2;
k=0;

for i=1:N1           %for loop to generate N number of orthogonal signals each with different frequency to other
    l=4*i*sin(2*pi*f*t+phi);  % generated sin wave with frequency f
    k=k+l;           %sum of both the signals
   switch i          % switch statement to put different signals to different variables
       case 1
           s1=l;
       case 2
           s2=l;    
       
           figure(2);
    subplot(1,2,1);   % plot to plot both-signals in a single graph
    plot(t,s1);
    axis([0 T -10 10]); 
    hold on;
    title("Plot of 2-Non-Orthogonal Signals")
    xlabel('time(s)');  
    ylabel('amplitude(V)'); 
    plot(t,s2);  
    hold off;  
   end
 
end
subplot(1,2,2) % plot to summation of both signals in a single graph
plot(t,k);
axis([0 T -15 15])
title("Plot of Summation of both Non-Orthogonal Signals");
xlabel('time(s)');
ylabel('amplitude(V)');

Product1=round(sum(s1.*s2),5); %for orthogonality inner product of two vectors is zero
 if Product1==0
            fprintf("Provided two signal i.e. s%i and s%i,are orthogonal to each other \n",1,2)
        else
            fprintf("Provided two signal i.e. s%i and s%i,are not orthogonal to each other \n",1,2)
 end

 
 



%Initialization of Variables
clc;
close all;
clear all; 
N=1e6;
BPSK=[1,-1];
QPSK=[1+1i,1-1i,-1+1i,-1-1i];
Es_BPSK=((BPSK(1)^2)+(BPSK(2)^2))/2;

Es_QPSK=0;
for i=1:length(QPSK)
Es_QPSK=Es_QPSK+((QPSK(i)*conj(QPSK(i)))/4);
end
QPSK_norm=QPSK/sqrt(Es_QPSK);
Es_QPSK=Es_QPSK*(1/Es_QPSK);
Eb_QPSK=Es_QPSK/2;


for SNR_dB = 0:10
    SNR_lin= 10^(SNR_dB/10);
    sd_BPSK=sqrt(Es_BPSK/(2*SNR_lin));
    sd_QPSK=sqrt(Es_QPSK/(2*(2*SNR_lin)));

Sym_err_BPSK=0;
Sym_err_QPSK=0;
Bit_err_BPSK=0;
Bit_err_QPSK=0;
  for iter= 1:N
      %Random Bit Generation
      Bit_BPSK=randi([0,1],1); %Random Bit Generation for BPSK
      Bit_QPSK=randi([0,1],1,2); %Random Bit Generation for QPSK

      %Mapping of Bits according to modulation scheme
      Sym_BPSK=digital_modulation_BPSK(Bit_BPSK);  %Mapping according to BPSK scheme
      Sym_QPSK=digital_modulation_QPSK(Bit_QPSK,QPSK_norm); %Mapping according to QPSK scheme
      
     
      %AWGN Noise 
      n_BPSK=sd_BPSK* randn;  
      n_QPSK=sd_QPSK*(randn+1i*randn);
  
    %Receiver Side 
      y_BPSK=Sym_BPSK + n_BPSK;
      y_QPSK=Sym_QPSK + n_QPSK;

    % Estimated Symbol   
      Est_x_BPSK=ml_detection(y_BPSK,BPSK);
      Est_x_QPSK=ml_detection(y_QPSK,QPSK_norm);
      
    %Estimated Bit BPSK
      if Est_x_BPSK==1
        Est_Bit_BPSK=0;
      else
        Est_Bit_BPSK=1;
      end
      
     

    %Number of corrupted Symbol for QPSK 
      if Est_x_BPSK~=Sym_BPSK
         Sym_err_BPSK=Sym_err_BPSK+1;
      end

      
     %Number of corrupted Symbol for QPSK 
      if Est_x_QPSK~=Sym_QPSK
          Sym_err_QPSK=Sym_err_QPSK+1;
      end

    
      %Number of corrupted Bit for BPSK 
      if Est_Bit_BPSK~=Bit_BPSK
          Bit_err_BPSK=Bit_err_BPSK+1;
      end
          %Estimated Bit QPSK
    if Est_x_QPSK==QPSK_norm(1)
        Est_Bit_QPSK=[0,0];
    elseif Est_x_QPSK==QPSK_norm(2)
        Est_Bit_QPSK=[0,1];
    elseif Est_x_QPSK==QPSK_norm(3)
        Est_Bit_QPSK=[1,0];
    else
        Est_Bit_QPSK=[1,1];
    end

      %Number of corrupted Bit for QPSK
      if xor(Est_Bit_QPSK(1)~=Bit_QPSK(1),Est_Bit_QPSK(2)~=Bit_QPSK(2))
          Bit_err_QPSK= Bit_err_QPSK+1;
      elseif ((Est_Bit_QPSK(1)~=Bit_QPSK(1))&&(Est_Bit_QPSK(2)~=Bit_QPSK(2)))
           Bit_err_QPSK= Bit_err_QPSK+2;
      end

  end

  SER_BPSK(SNR_dB+1)=Sym_err_BPSK/N;
  SER_QPSK(SNR_dB+1)=Sym_err_QPSK/N;
  BER_BPSK(SNR_dB+1)=Bit_err_BPSK/N;
  BER_QPSK(SNR_dB+1)=Bit_err_QPSK/(2*N);

  SER_theo_BPSK(SNR_dB+1)=qfunc(sqrt(2*SNR_lin));
  SER_theo_QPSK(SNR_dB+1)=2*qfunc(sqrt(2*SNR_lin));
end


Eb_N0_dB=0:10;
%Plot of SER of BPSK  Simulated 
semilogy(Eb_N0_dB,SER_BPSK);
grid on;
hold on;
%Plot of SER of BPSK  Theoratical
semilogy(Eb_N0_dB,SER_theo_BPSK);
grid on;
%Plot of BER of BPSK 
semilogy(Eb_N0_dB,BER_BPSK);
grid on;
%Plot of SER of QPSK Simulated
semilogy(Eb_N0_dB,SER_QPSK);
grid on;
%Plot of SER of QPSK  Theoratical
semilogy(Eb_N0_dB,SER_theo_QPSK);
grid on;
%Plot of BER of QPSK 
semilogy(Eb_N0_dB,BER_QPSK);
grid on;
legend('SER BPSK','SER BPSK Ther.','BER BPSK','SER QPSK','SER QPSK Theo.','BER QPSK')
hold off;

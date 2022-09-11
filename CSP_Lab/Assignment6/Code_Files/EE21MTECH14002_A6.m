clc;
clear all;
%========================= BPSK ===========================%
[BER,SER,BER_theory,SER_theory]=deal(zeros(1,11));
%Initialization
Bandwidth= 100;           %In Khz
Base_Freq= 5;             %Base Frequency in KHz
Sym_Time = 1/Base_Freq;   % Symbol Time
N_subcarr= 20;            % Total Number of Subcarriers 
N=1e3;
Tx_samples=zeros((N/N_subcarr),1); 


for Eb_No_dB=0:10
    
    n=1;    %Es=nEb where n=1 for BPSK
    Es_No_dB=Eb_No_dB+10*log10(n);  
    Es_No=10^( Es_No_dB/10);
    
    BPSK_symbols=[1,-1];    %BPSK constellation set (Already Normalised)
    E_s=1/2*sum(BPSK_symbols.^2);
    sd_BPSK=sqrt(E_s/(2*Es_No));
 

    symbols_in_error=0;
    bits_in_error=0;
   
     for i=1:N/N_subcarr 

       %Generating a random bit
       Rand_bit_BPSK=randi([0 1],N_subcarr,1);

       %Mapping the bits to BPSK symbol set
       BPSK_sym_array=zeros(N_subcarr,1);
       for i=1:N_subcarr
       BPSK_sym_array(i,1)=com_func.BPSK_mod(Rand_bit_BPSK(i,1));
       end
      
       %IFFT
       Tx_samples=sqrt(N_subcarr)*ifft(BPSK_sym_array);
       
       %Adding AWGN noise
       Noise = sd_BPSK*(1/sqrt(2))*(randn(20,1)+1i*randn(20,1));
        
       %Received Signal
       BPSK_rec = Tx_samples + Noise;
        
       %fft of a received signal
       BPSK_rec_fft=fft(BPSK_rec); 
   
           % Estimated Symbol 
           Est_symbol_BPSK=zeros(N_subcarr,1);
           for w=1:20
           Est_symbol_BPSK(w,1)=ml_detection(BPSK_rec_fft(w,1),BPSK_symbols);
           end
           
      
           %Number of corrupted Symbol for BPSK 
           for w=1:20
           if Est_symbol_BPSK(w,1)~=BPSK_sym_array(w,1)
           symbols_in_error=symbols_in_error+1;
           end
           end
         
           %Estimated Bit BPSK
           Est_Bit_BPSK=zeros(N_subcarr,1);
          
           for w=1:20
           if Est_symbol_BPSK(w,1)==-1
           Est_Bit_BPSK(w,1)=0;
           else
           Est_Bit_BPSK(w,1)=1;
           end
           end
           
           %Number of corrupted Bit for BPSK 
           for w=1:20
           if Est_Bit_BPSK(w,1)~=Rand_bit_BPSK(w,1)
           bits_in_error=bits_in_error+1;
           end
           end   
    end
    BER(Eb_No_dB+1)=bits_in_error/1e3;
    SER(Eb_No_dB+1)=symbols_in_error/1e3;
    Eb_No=10^(Eb_No_dB/10);
    BER_theory(Eb_No_dB+1)=qfunc(sqrt(2*Eb_No));
    SER_theory(Eb_No_dB+1)=qfunc(sqrt(2*Eb_No));
end   
    %NOTE : SER and BER for BPSK is same. Also the Bit enerygy is same as
    %symbol energy Eb=Es.    

figure(1);
f=5*(10^3):5*(10^3):100*(10^3);
subplot(2,1,1);
stem(f,BPSK_sym_array,'DisplayName','20-OFDM-Subcarriers');
title('BPSK-OFDM Frequency Domain Plot');
ylabel('Magnitude');
xlabel('Frequency(HZ)');
grid on;
legend();

subplot(2,1,2);
stem(Tx_samples,'DisplayName','Transmitted signal');
title('Plot of Tx BPSK-OFDM signal');
ylabel('Magnitude');
xlabel('Discrete Samples(N)');
grid on;
legend;

Eb_No_dB=0:10;
figure(2); 
subplot(1,2,1);
semilogy(Eb_No_dB,BER,'r*-',Eb_No_dB,BER_theory,'ko-');
title('BER of BPSK');
ylabel('BER--->');
xlabel('Eb/No(dB)--->');
grid on;
legend('Practical BER','Theoratical BER');

subplot(1,2,2);
semilogy(Eb_No_dB,SER,'r*-',Eb_No_dB,SER_theory,'ko-');
title('SER of BPSK');
ylabel('SER--->');
xlabel('Eb/No(dB)--->');
grid on;
legend('Practical SER','Theoratical SER');


%========================= QPSK ===========================%

for Eb_No_dB=0:10
    n=2;    %Es=nEb where n=2 for QPSK
    Es_No_dB=Eb_No_dB+10*log10(n);  
    Es_No=10^( Es_No_dB/10);
    
    QPSK_symbols=(1/sqrt(2))*[1+1i,1-1i,-1+1i,-1-1i];    
    E_s=1/4*sum(abs(QPSK_symbols).^2); %Normalising QPSK constellation set for unit energy
    sigma = sqrt(E_s/(2*Es_No)); 
    
    symbols_in_error=0;
    bits_in_error=0;
    
    for i=1:N/N_subcarr %Note : Submitted plot was generated using 1e4 iterations for accuracy. 
        
        for j=1:N_subcarr
        %Generating a random bit
        Rand_bit=randi([0 1],1,2);

        %Mapping the bits to QPSK symbol set
        QPSK=comm_func.QPSK_mod(Rand_bit);
        QPSK_sym_array(j)=QPSK;
        
        %ifft to get transmitted OFDM sample
        Tx_sample=ifft(QPSK);
        Tx_samples(j)=Tx_sample;
        %Adding AWGN noise
        Noise = sigma*complex(randn(1),randn(1));
        
        %Received QPSK
        QPSK_rec = Tx_sample + Noise;
        
        %fft of received bit
        QPSK_rec_fft=fft(QPSK_rec)
        
        %Implementing Maximum likelihood (minimum distance) decoding on the sampled values
        Decoded_QPSK=comm_func.ML_decode(QPSK_rec_fft,4,QPSK_symbols);
        Decoded_Rand_bit=comm_func.QPSK_demod(Decoded_QPSK);
        
        %Comparing the decoded bit/symbol with the transmitted bit/symbol
        %to increment the errors
        symbols_in_error=symbols_in_error+nnz(Decoded_QPSK-QPSK);
        bits_in_error=bits_in_error+nnz(Decoded_Rand_bit-Rand_bit);
        end
        i=i+20;
    end
    BER(Eb_No_dB+1)=bits_in_error/1e3;
    SER(Eb_No_dB+1)=symbols_in_error/1e3;
    Eb_No=10^(Eb_No_dB/10);
    BER_theory(Eb_No_dB+1)=qfunc(sqrt(2*Eb_No));
    SER_theory(Eb_No_dB+1)=2*qfunc(sqrt(2*Eb_No)); 
end

%All Plots of QPSK

figure(3);
f=5*(10^3):5*(10^3):100*(10^3);
subplot(2,1,1);
stem(f,QPSK_sym_array,'DisplayName','20-OFDM-Subcarriers');
title('QPSK-OFDM Frequency Domain Plot');
ylabel('Magnitude');
xlabel('Frequency(HZ)');
grid on;
legend();

subplot(2,1,2);
stem(Tx_samples,'DisplayName','Transmitted signal');
title('Plot of Tx QPSK-OFDM signal');
ylabel('Magnitude');
xlabel('Discrete Samples(N)');
grid on;
legend;


Eb_No_dB=0:10;

figure(4);
subplot(1,2,1);
semilogy(Eb_No_dB,BER,'r*-',Eb_No_dB,BER_theory,'ko-');
title('BER of QPSK');
ylabel('BER--->');
xlabel('Eb/No(dB)--->');
legend('Practical BER','Theoratical BER');
grid on;

subplot(1,2,2);
semilogy(Eb_No_dB,SER,'r*-',Eb_No_dB,SER_theory,'ko-');
title('SER of QPSK');
ylabel('SER--->');
xlabel('Eb/No(dB)--->');
legend('Practical SER','Theoratical SER');
grid on;

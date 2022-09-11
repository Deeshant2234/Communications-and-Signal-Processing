classdef comm_func
    methods(Static)

        %function for BPSK Modulation
        function bpsk=BPSK_mod(x)
            bpsk=2*x-1;
        end

        %function for BPSK Demodulation
        function bdemod=BPSK_demod(x)
            bdemod=(x+1)*0.5;
        end
        
        %function for QPSK Modulation
        function qpsk=QPSK_mod(x)                                 
            qpsk=(1/sqrt(2))*(2*((x(1)-0.5)+i*(x(2)-0.5)));
        end
        
        %function for QPSK Demodulation
        function qdemod=QPSK_demod(x)                               
            temp(1)=(real(x)>0);
            temp(2)=(imag(x)>0);
            qdemod=temp;
        end

        %function for ML decoding
        function decoded=ML_decode(x,no_of_symbols,symbol_array)
            for j=1:no_of_symbols
                D(j)=abs(x-symbol_array(j))^2; 
            end
            [M,I] = min(D);
            decoded=symbol_array(I);
        end
    end
end
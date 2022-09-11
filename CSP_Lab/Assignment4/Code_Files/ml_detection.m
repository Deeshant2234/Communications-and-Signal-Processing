function[Est_Sym_BPSK]=ml_detection(sym,xpsk)
   Est_Sym_BPSK=0;
   for i=1:length(xpsk)
       dis(i)=(abs(sym-xpsk(i))^2);
   end
   for i=1:length(xpsk)
       if dis(i)==min(dis)
          Est_Sym_BPSK=xpsk(i);
       end
   end   
end
function[Sym_QPSK]= digital_modulation_QPSK(Bit,QPSK)
  if Bit(1)==0
      if Bit(2)==0
        Sym_QPSK=QPSK(1);
      else
          Sym_QPSK=QPSK(2);
      end
  else
   if Bit(2)==0
      Sym_QPSK=QPSK(3);
  else
      Sym_QPSK=QPSK(4);
   end
  end
end
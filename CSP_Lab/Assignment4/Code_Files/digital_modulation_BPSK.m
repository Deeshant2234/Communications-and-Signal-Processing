function[Sym_BPSK]= digital_modulation_BPSK(Bit)
  if Bit==0
     Sym_BPSK=1;
  else
    Sym_BPSK=-1;
  end
end
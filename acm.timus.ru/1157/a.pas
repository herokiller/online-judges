var
   x,y,k,i,j,kol1,kol2 : longint;
begin
   read(x,y,k);
   for i:=k+1 to 10000 do begin
      kol1:=0;
      for j:=1 to trunc(sqrt(i)) do 
         if (i mod j =0) then inc(kol1);
      kol2:=0;
      for j:=1 to trunc(sqrt(i-k)) do
         if ((i-k) mod j =0) then inc(kol2);
      if (kol1 = y) and (kol2 = x) then begin
         write(i);
         halt(0);
      end;
   end;
   write(0);
end.
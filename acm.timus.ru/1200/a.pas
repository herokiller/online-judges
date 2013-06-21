var
   a,b,max : extended;
   i,kol1,kol2,ans1,ans2,k,m1,m2 : longint;
begin
   read(a,b);
   read(k);
   max:=-1;
   for i:=0 to k do
      if (a*i-i*i > max) then begin
         max:=a*i-i*i;
         m1:=i;
      end;
   max:=-1;
   for i:=0 to k do
      if (b*i-i*i > max) then begin
         max:=b*i-i*i;
         m2:=i;
      end;
   max:=-1;
   for i:=0 to k do begin
      kol1:=i;
      if (kol1 > m1) then
         kol1:=m1;
      kol2:=k-kol1;
      if (kol2 > m2) then
         kol2:=m2;
      if (kol1*a-kol1*kol1+kol2*b-kol2*kol2 > max) then begin
         max:=kol1*a-kol1*kol1+kol2*b-kol2*kol2;
         ans1:=kol1;
         ans2:=kol2;
      end;
   end;
   writeln(max:0:2);
   write(ans1,' ',ans2);
end.
var
   a,b,i,ans : longint;
begin
   read(a,b);
   for i:=a to b do 
      if (i mod 2 = 1) then inc(ans);
   write(ans);
end.
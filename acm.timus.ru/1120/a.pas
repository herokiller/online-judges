var
   n,i,ans : longint;
begin
   read(n);

   for i:=(trunc(sqrt(2*n)) + 10) downto 1 do
      if (2*n-i*i >= 0) then
         if ((2*n-i*i) mod i =0) then
            if ((((2*n-i*i) div i)+1) mod 2 =0) then begin
               ans:=(((2*n-i*i)div i)+1) div 2;
               write(ans,' ',i);
               halt(0);
            end;
end.
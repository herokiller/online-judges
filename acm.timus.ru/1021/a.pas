var
   n1,n2,i,j : longint;
   a,b : array [1..60000] of longint;
begin
   read(n1);
   for i:=1 to n1 do 
      read(a[i]); 
   read(n2);
   for i:=1 to n2 do 
      read(b[i]);
   
   i:=1; j:=1;
   while (i <= n1) and (j <= n2) do begin
      if (a[i] + b[j] = 10000) then begin
         write('YES');
         halt(0);
      end;
      if (a[i] + b[j] < 10000) then inc(i) else inc(j);
   end;
   write('NO');
end.
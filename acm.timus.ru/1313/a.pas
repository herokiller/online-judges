var
   n,i,j,x1,x2 : longint;
   a : array [1..300,1..300] of longint;
begin
   read(n);
   for i:=1 to n do
      for j:=1 to n do
         read(a[i,j]);

   for i:=1 to n do begin
      x1:=i; x2:=1;
      while (x1 >= 1) do begin
         write(a[x1,x2],' ');
         dec(x1); inc(x2);
      end;
   end;

   for j:=2 to n do begin
      x2:=j; x1:=n;
      while (x2 <= n) do begin
         write(a[x1,x2],' ');
         dec(x1); inc(x2);
      end;
   end;
end.
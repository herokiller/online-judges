var
   a : array [1..1000000] of extended;
   n,i : longint;
begin
   while not seekeof do begin
      inc(n);
      read(a[n]);
   end;
   for i:=n downto 1 do 
      writeln(sqrt(a[i]):0:4);
end.
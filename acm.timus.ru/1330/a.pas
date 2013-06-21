var
   a,d : array [0..15000] of int64;
   i,n,m,x,y : longint;
   sum,c : int64;
begin
   read(n);
   for i:=1 to n do
      read(a[i]);
   sum:=0;
   for i:=1 to n do begin
      sum:=sum+a[i];
      d[i]:=sum;
   end;

   read(m);
   for i:=1 to m do begin
      read(x,y);
      if (x <= y) then
         writeln(d[y]-d[x-1]) else writeln(d[x]-d[y-1]);
   end;
end.
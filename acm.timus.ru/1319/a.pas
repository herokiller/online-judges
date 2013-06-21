const
   maxn = 1000;
var
   a : array [1..maxn,1..maxn] of longint;
   n,i,j,x,y,fill : longint;
begin
   read(n);
   for i:=n downto 1 do begin
      j:=1;
      x:=j; y:=i;
      while (j<=n-i+1) do begin
         inc(j);
         inc(fill);
         a[x,y]:=fill;
         inc(x); inc(y);
      end;
   end;

   fill:=n*n+1;
   for i:=n downto 1 do begin
      j:=1;
      x:=n; y:=n-i+1;
      while (j<=n-i+1) do begin
         inc(j);
         dec(fill);
         a[x,y]:=fill;
         dec(x); dec(y);
      end;
   end;

   for i:=1 to n do begin
      for j:=1 to n do
         write(a[i,j],' ');
      writeln;
   end;
end.

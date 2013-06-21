const
   maxn = 10000;
var
   a : array [1..maxn] of longint;
   n,m,i,kol : longint;
begin
   read(n,m);
   m:=m mod n;
   for i:=1 to n do
      read(a[i]);

   kol:=0;
   for i:=m+1 to n do begin
      inc(kol);
      write(a[i]);
      if (kol = 10) then break;
   end;
   for i:=1 to m do begin
      if (kol = 10) then break;
      write(a[i]);
      inc(kol);
   end;
end.
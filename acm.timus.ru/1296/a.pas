const
   maxn = 70000;
var
   n,i,max : longint;
   a,d : array [0..maxn] of longint;
begin
   read(n);
   for i:=1 to n do
      read(a[i]);

   for i:=1 to n do begin
      if (a[i] < 0) then begin
         if (d[i-1] >= 0) then
            if (d[i-1]+a[i] > 0) then
               d[i]:=d[i-1]+a[i] else d[i]:=0;
         if (d[i-1] < 0) then
            d[i]:=0;
      end;
      if (a[i] >= 0) then begin
         if (d[i-1] >= 0) then
            d[i]:=d[i-1]+a[i];
         if (d[i-1] < 0) then
            d[i]:=a[i];
      end;
   end;
   max:=-1;
   for i:=0 to n do
      if (d[i] > max) then max:=d[i];
   write(max);
end.

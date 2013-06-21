const
   maxn = 504;
var
   num0, num1,a : array [0..maxn] of longint;
   b,d : array [0..maxn,0..maxn] of longint;
   i,j,k,k1,n : longint;
begin
   read(n,k1);
   for i:=1 to n do
      read(a[i]);

   for i:=1 to n do begin
      num0[i]:=num0[i-1];
      num1[i]:=num1[i-1];
      if (a[i] = 0) then inc(num0[i]);
      if (a[i] = 1) then inc(num1[i]);
   end;


   for i:=1 to n do
      for j:=i to n do
         b[i,j]:=(num0[j] - num0[i-1])*(num1[j] - num1[i-1]);

   for i:=0 to n do
      for j:=0 to n do
         d[i,j]:=maxlongint div 2;
   d[0,0]:=0;

   for i:=1 to k1 do
      for j:=i to n do
         for k:=i-1 to j-1 do
            if (d[i-1,k] + b[k+1,j] < d[i,j]) then
               d[i,j]:=d[i-1,k] + b[k+1,j];

   write(d[k1,n]);
end.
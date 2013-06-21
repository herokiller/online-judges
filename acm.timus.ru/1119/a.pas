const
   maxn = 1001;
var
   d : array [0..maxn,0..maxn] of single;
   n,m,i,j,x,y,k : longint;
begin
   read(m,n);
   read(k);
   for i:=1 to k do begin
      read(y,x);
      d[x,y]:=1;
   end;

   for i:=0 to n do
      d[i,0]:=i;
   for j:=0 to m do
      d[0,j]:=j;
   for i:=1 to n do
      for j:=1 to m do begin
         if (d[i,j] = 1) then
            d[i,j]:=d[i-1,j-1]+sqrt(2) else d[i,j]:=d[i-1,j-1]+2;
         if (d[i-1,j]+1 < d[i,j]) then
            d[i,j]:=d[i-1,j]+1;
         if (d[i,j-1]+1 < d[i,j]) then
            d[i,j]:=d[i,j-1]+1;
      end;

   write(round(d[n,m]*100));
end.
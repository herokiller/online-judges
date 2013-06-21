const
   maxn = 100;
var
   a,c : array [1..maxn,1..maxn] of longint;
   i,j,k,n,m,i2,j2 : longint;
   ch : char;
begin
   readln(n,m);
   for i:=1 to n do begin
      for j:=1 to m do begin
         read(ch);
         if (ch = 'W') then c[i,j]:=1 else c[i,j]:=-1;
      end;
      readln;
   end;
   for i:=1 to n do
      for j:=1 to m do begin
         read(a[i,j]);
         a[i,j]:=a[i,j] mod 2;
      end;
   for i:=1 to n do
      for j:=1 to m do
         if (a[i,j] = 1) then begin
            for i2:=1 to n do
               for j2:=1 to m do
                  if (sqrt(sqr(i2-i)+sqr(j2-j)) =
                     trunc(sqrt(sqr(i2-i)+sqr(j2-j)))) then
                     c[i2,j2]:=-c[i2,j2];
         end;

   for i:=1 to n do begin
      for j:=1 to m do
         if (c[i,j] = 1) then write('W') else write('B');
      writeln;
   end;
end.
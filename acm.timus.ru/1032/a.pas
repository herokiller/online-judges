const
   maxn = 10100;
var
   a,b : array [0..maxn] of longint;
   sum,i,j,n : longint;
begin
   read(n);
   for i:=1 to n do
      read(a[i]);
   sum:=0;
   for i:=1 to n do begin
      sum:=(sum+a[i]) mod n;
      if (b[sum] = 0) then
         b[sum]:=i
      else begin
         writeln(i-b[sum]);
         for j:=b[sum]+1 to i do
            writeln(a[j]);
         halt(0);
      end;
   end;
   if b[0] <> 0 then begin
      writeln(b[0]);
      for i:=1 to b[0] do
         writeln(a[i]);
      halt(0);
   end;

end.
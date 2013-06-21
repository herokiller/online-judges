var
   a : array [500..700] of longint;
   i,n,x,ans : longint;
begin
   read(n);
   for i:=1 to n do begin
      read(x);
      inc(a[x]);
   end;

   for i:= 500 to 700 do
      inc(ans,a[i] div 4);

   writeln(ans);
end.
const
   maxn = 100000;
var
   a : array [-maxn..maxn] of longint;
   x1,x2,n,num,p1,p2,min,max,i : longint;
begin
   read(n);
   num:=1;
   a[1]:=1;
   p1:=1;
   p2:=1;
   max:=n+1;
   min:=1;
   while true do begin
      if (num >= n) then
         break;
      inc(num);
      inc(p1);
      dec(max);
      a[p1]:=max;
      if (num >= n) then break;
      inc(num);
      dec(p2);
      dec(max);
      a[p2]:=max;
      if (num >= n) then break;
      inc(num);
      inc(min);
      inc(p1);
      a[p1]:=min;
      if (num >= n) then break;
      inc(num);
      inc(min);
      dec(p2);
      a[p2]:=min;
   end;

   for i:=1 to p1 do
      write(a[i],' ');
   for i:=p2 to 0 do
      write(a[i],' ');
   writeln;

   write(1,' ');
   x1:=2;
   while (x1 <= n) do begin
      write(x1,' ');
      inc(x1,2);
   end;
   x2:=n;
   if (x2 mod 2 =0) then dec(x2);

   while (x2 >= 3) do begin
      write(x2,' ');
      dec(x2,2);
   end;
end.

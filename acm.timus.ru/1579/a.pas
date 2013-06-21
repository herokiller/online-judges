const
   maxn = 100100;
var
   n,r,i,j,last,res,k,group : longint;
   a,pr,ans : array [1..maxn] of longint;
begin
   read(n,r);
   for i:=1 to n do
      read(a[i]);

   last:=1;
   group:=1;

   for i:=2 to n do
      if (pr[i] = 0) and (a[i] - a[last] > r) then begin
         pr[i]:=last;
         inc(last);
      end else inc(group);

   writeln(group);

   for i:=n downto 1 do begin
      j:=i; res:=0;
      while (j > 0) and (pr[j] <> -1) do begin
         inc(res);
         ans[res]:=j;
         k:=j;
         j:=pr[j];
         pr[k]:=-1;
      end;
      if (res > 0) then begin
         write(res,' ');
         for j:=res downto 1 do
            write(ans[j],' ');
         writeln;
      end;
   end;
end.
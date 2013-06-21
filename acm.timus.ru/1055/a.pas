const
   maxn = 50001;
var
   pr,kol : array [1..maxn] of longint;
   a : array [1..maxn] of longint;
   yk,n,m,i,j,ans : longint;
begin
   read(n,m);
   for i:=1 to n do
      a[i]:=i;
   for i:=2 to trunc(sqrt(n)) do
      for j:=m+1 to n do
         if (a[j] mod i =0) then
            while true do begin
               inc(kol[i]);
               a[j]:=a[j] div i;
               if (a[j] mod i <> 0) then break;
            end;

   for i:=m+1 to n do
      if (a[i] <> 1) then inc(kol[a[i]]);

   for i:=1 to n do
      a[i]:=i;

   for i:=2 to trunc(sqrt(n-m)) do
      for j:=1 to (n-m) do
         if (a[j] mod i =0) then
            while true do begin
               dec(kol[i]);
               a[j]:=a[j] div i;
               if (a[j] mod i <> 0) then break;
            end;

   for i:=1 to (n-m) do
      if (a[i] <> 1) then dec(kol[a[i]]);
   for i:=1 to n do
      if (kol[i] <> 0) then inc(ans);
   write(ans);
end.
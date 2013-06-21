const
   maxn = 500;
var
   a : array [1..maxn,1..maxn] of longint;
   b : array [1..maxn] of boolean;
   n,i,j,k,x,kol : longint;
function check(ver : longint) : boolean;
var
         i : longint;
 begin
    check:=true;
    for i:=1 to n do
       if (a[i,ver]=1) then check:=false;
 end;

begin
   read(n);
   i:=1;
   while (i<=n) do begin
      read(x);
      if (x = 0) then begin
         inc(i);
         continue;
      end;
      a[i,x]:=1;
   end;

      for i:=1 to n do
         for j:=1 to n do
            if (a[i,j]=1) then
               for k:=1 to n do
                  if (a[j,k]=1) then a[i,k]:=1;

   while true do begin
      for i:=1 to n do begin
         if check(i) and (not b[i]) then begin
            b[i]:=true;
            inc(kol);
            write(i,' ');
            for j:=1 to n do
               if (a[i,j]=1) then a[i,j]:=0;
         end;
      end;
      if kol=n then break;
   end;
end.

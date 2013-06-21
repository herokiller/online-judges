const
   maxn = 500005;
var
   a : array [1..maxn] of longint;
   last,i,kol,n,max,ans : longint;
procedure sort(l,r : longint);
var
  i,j,x,y : longint;
begin
  i:=l; j:=r; x:=a[(l+r) div 2];
  repeat
    while a[i]<x do i:=i+1;
    while x<a[j] do j:=j-1;
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      i:=i+1; j:=j-1;
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

begin
   read(n);
   for i:=1 to n do read(a[i]);
   sort(1,n);
   last:=a[1]; kol:=1; max:=1; ans:=a[1];
   for i:=2 to n do begin
      if (a[i] = last) then begin
         inc(kol);
      end else begin
         if (kol > max) then begin
            ans:=last;
            max:=kol;
         end;
         kol:=1;
         last:=a[i];
      end;
   end;
   if (kol > max) then begin
            ans:=last;
            max:=kol;
         end;
   write(ans);
end.
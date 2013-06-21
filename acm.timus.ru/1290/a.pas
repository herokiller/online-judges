var
   a : array [1..100000] of longint;
   n,i : longint;
procedure sort(l,r: longint);
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
   for i:=n downto 1 do writeln(a[i]);
end.

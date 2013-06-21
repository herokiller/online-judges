const
   maxn = 10001;
var
   a,b,c : array [1..maxn] of longint;
   i,j,kol,n : longint;

procedure sort1(l,r: longint);
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
      y:=b[i]; b[i]:=b[j]; b[j]:=y;
      y:=c[i]; c[i]:=c[j]; c[j]:=y;
      i:=i+1; j:=j-1;
    end;
  until i>j;
  if l<j then sort1(l,j);
  if i<r then sort1(i,r);
end;
procedure sort2(l,r: longint);
var
  i,j,x,y : longint;
begin
  i:=l; j:=r; x:=b[(l+r) div 2];
  repeat
    while b[i]<x do i:=i+1;
    while x<b[j] do j:=j-1;
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      y:=b[i]; b[i]:=b[j]; b[j]:=y;
      y:=c[i]; c[i]:=c[j]; c[j]:=y;
      i:=i+1; j:=j-1;
    end;
  until i>j;
  if l<j then sort2(l,j);
  if i<r then sort2(i,r);
end;

begin
   read(n);
   for i:=1 to n do begin
      read(a[i],b[i]);
      c[i]:=i; 
   end;
   sort1(1,n);
   i:=0;
   while (i < n) do begin 
      inc(i);
      kol:=0;
      for j:=i+1 to n do
         if a[j] = a[i] then inc(kol) else break;
      if (kol > 0) then begin
         sort2(i,i+kol);
         i:=i+kol;
      end;  
   end;
   i:=0;
   while (i<n) do begin
      inc(i);
      writeln(c[i],' ',c[i+1]);
      inc(i);
   end;
end.
var
   m,t,st,h : array [1..1010] of longint;
   n,i,j,k,x,max,ans,yk,pos : longint;
   b : array [1..1010] of boolean;
procedure sort(l,r: longint);
var
  i,j,x,y: longint;
begin
  i:=l; j:=r; x:=t[(l+r) DIV 2];
  repeat
    while t[i]<x do i:=i+1;
    while x<t[j] do j:=j-1;
    if i<=j then
    begin
      y:=t[i]; t[i]:=t[j]; t[j]:=y;
      y:=m[i]; m[i]:=m[j]; m[j]:=y;
      y:=h[i]; h[i]:=h[j]; h[j]:=y;
      i:=i+1; j:=j-1;
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
   read(n);
   for i:=1 to n do
      read(t[i],m[i]);
   for i:=1 to n do
      h[i]:=i;
   sort(1,n);
   max:=-1;
   for i:=1 to n do
      if (t[i] > max) then max:=t[i];
   k:=n;

   for i:=max downto 1 do begin
      x:=-1;
      for j:=k downto 1 do begin
         if (t[j] < i) then begin
            break;
         end;
         if (t[j] >= i) and (b[j] = false)
         and (m[j] > x) then begin
            x:=m[j];
            pos:=j;
         end;
      end;
      if (x <> -1) then begin
         b[pos]:=true;
         inc(yk);
         st[yk]:=h[pos];
      end;
   end;
   writeln(yk);
   for i:=yk downto 1 do
      write(st[i],' ');
end.

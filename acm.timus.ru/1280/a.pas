const
   maxn = 1002;
var
   n,m,i,j,ver,x,y : longint;
   a : array [1..maxn,1..maxn] of longint;

begin
   read(n,m);
   for i:=1 to m do begin
      read(x,y);
      a[x,y]:=1;
   end;
   for i:=1 to n do begin
      read(ver);
      for j:=1 to n do begin
         if (a[j,ver] = 1) then begin
            write('NO');
            halt(0);
         end;
      end;
      for j:=1 to n do
         a[ver,j]:=0;
   end;
   write('YES');
end.
const
   st = 32768;
var
   a : array [1..st+st-1] of longint;
   m,i,x,n : longint;
procedure refresh(ver1,ver2 : longint);
 begin
    ver1:=ver1+st-1; ver2:=ver2+st-1;
    while (ver1 > 1) do begin
       ver1:=ver1 div 2; ver2:=ver2 div 2;
       if (a[ver1+ver1] > a[ver1+ver1+1]) then
          a[ver1]:=a[ver1+ver1] else a[ver1]:=a[ver1+ver1+1];
       if (a[ver2+ver2] > a[ver2+ver2+1]) then
          a[ver2]:=a[ver2+ver2] else a[ver2]:=a[ver2+ver2+1];
    end;
 end;
procedure find(ver1,ver2 : longint);
 begin
    ver1:=ver1+st-1; ver2:=ver2+st-1;
    while (ver1 >= 1) and (ver2 >= 1) do begin
       if (ver1 = ver2) then begin
          writeln(a[ver1]);
          exit;
       end;
       if (ver1 mod 2 =1) then
          a[ver1 div 2]:=a[ver1] else
             if (a[ver1] > a[ver1+1]) then a[ver1 div 2]:=a[ver1]
             else a[ver1 div 2]:=a[ver1+1];
       if (ver2 mod 2 =0) then
          a[ver2 div 2]:=a[ver2] else
             if (a[ver2] > a[ver2-1]) then a[ver2 div 2]:=a[ver2]
             else a[ver2 div 2]:=a[ver2-1];
       ver1:=ver1 div 2;
       ver2:=ver2 div 2;
    end;
 end;
begin
   read(m);
   i:=0;
   while   true do begin
      inc(i);
      read(x); if (x = -1) then break;
      a[i+st-1]:=x;
   end;
   n:=i-1;
   for i:=st-1 downto 1 do
      if (a[i+i] > a[i+i+1]) then a[i]:=a[i+i] else a[i]:=a[i+i+1];

   for i:=1 to (n-m+1) do begin
      find(i,i+m-1);
      refresh(i,i+m-1);
   end;
end.
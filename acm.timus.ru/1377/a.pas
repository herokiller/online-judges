var
   a : array [1..200,1..200] of longint;
   n,m,i,j,i0,j0,i2,j2,x1,x2,y1,y2,fill : longint;
begin
   read(n,m);
   read(x1,y1,x2,y2);

   i0:=2; j0:=1;
   i2:=n; j2:=m;

   i:=1; j:=1;
   fill:=0;
   while true do begin

      for j:=j0 to j2 do begin
         inc(fill);
         a[i,j]:=fill;
      end;
      dec(j2);

      for i:=i0 to i2 do begin
         inc(fill);
         a[i,j]:=fill;
      end;
      dec(i2);
      for j:=j2 downto j0 do begin
         inc(fill);
         a[i,j]:=fill;
      end;
      inc(j0);

      for i:=i2 downto i0 do begin
         inc(fill);
         a[i,j]:=fill;
      end;
      inc(i0);
      if fill >= n*m then break;
   end;
   write(abs(a[x1,y1]-a[x2,y2]));
end.

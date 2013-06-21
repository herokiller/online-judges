var
   a : array [1..1000] of longint;
   k,i,j,kol1,kol2 : longint;
begin
   read(k);
   a[1]:=6; a[2]:=3;

   for i:=1 to k-1 do begin
      for j:=1 to 1000 do
         a[j]:=a[j]*55;
      for j:=1 to 1000 do begin
         if (a[j] >= 100) then begin
            a[j+2]:=a[j+2]+(a[j] div 100);
            a[j]:=a[j] mod 100;
            a[j+1]:=a[j+1]+(a[j] div 10);
            a[j]:=a[j] mod 10;
         end;
         if (a[j] >= 10) then begin
            a[j+1]:=a[j+1]+(a[j] div 10);
            a[j]:=a[j] mod 10;
         end;
      end;
   end;

   for i:=1000 downto 1 do
      if (a[i] <> 0) then begin
         for j:=i downto 1 do
            write(a[j]);
         halt(0);
      end;
end.

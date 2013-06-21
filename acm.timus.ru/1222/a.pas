var
   a : array [1..1000] of longint;
   n,t,tr,i,j : longint;
begin
   read(n);
   if (n = 1) then begin
      write(1);
      halt(0);
   end;
   tr:=n div 3;
   if (n mod 3 = 1) then begin
      dec(tr);
      inc(t,2);
   end;
   if (n mod 3 = 2) then
      inc(t);
   a[1]:=1;
   for i:=1 to t do begin
      for j:=1 to 500 do 
         a[j]:=a[j]*2;
      for j:=1 to 500 do 
         if (a[j] >= 10) then begin
            a[j+1]:=a[j+1]+1;
            a[j]:=a[j] mod 10;
         end;
   end;
   for i:=1 to tr do begin
      for j:=1 to 500 do  
         a[j]:=a[j]*3;
      for j:=1 to 500 do 
         if (a[j] >= 10) then begin
            a[j+1]:=a[j+1]+(a[j] div 10);
            a[j]:=a[j] mod 10;
         end;
   end;
   for i:=600 downto 1 do 
      if (a[i] <> 0) then begin
         for j:=i downto 1 do 
            write(a[j]);
         halt(0);
      end;
end.
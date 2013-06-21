var
   ans : array [1..3000] of longint;
   res,i,n : longint;
begin
   read(n);
   if (n=0) then begin
      write(10);
      halt(0);
   end;  
   if (n=1) then begin
      write(1);
      halt(0);
   end;
   i:=9; res:=0; 
   while (i > 1) do begin
      if (n mod i =0) then begin
         n:=n div i;
         inc(res); 
         ans[res]:=i;
      end else dec(i);
   end;
   if (n > 1) then begin
      writeln(-1);
      halt(0);
   end; 
   for i:=res downto 1 do write(ans[i]);
end.
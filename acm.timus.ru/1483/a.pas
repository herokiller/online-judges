var
   n : longint;
begin
   read(n);
   if (n =1) then begin
      write(0,' ',0);
      halt(0);
   end;
   if (n =2) then begin
      write(1,' ',1);
      halt(0);
   end;
   if (n mod 2 =1) then begin
      if (n-1 < ((n div 2)*3)) then
         write(n-1,' ') else write((n div 2)*3,' ');
      if (n-1 > ((n div 2)*3)) then
         write(n-1) else write((n div 2)*3);
   end else begin
      if (n-1 < ((n div 2)*3-2)) then
         write(n-1,' ') else write((n div 2)*3-2,' ');
      if (n-1 > ((n div 2)*3-2)) then
         write(n-1) else write((n div 2)*3-2);
   end;
end.
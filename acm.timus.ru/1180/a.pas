const
   num : set of char = ['0'..'9'];
var
  x : longint;
  y : char;
begin
   while not eof do begin
      read(y);
      if (y in num) then
         x:=((x+ord(y)-ord('0')) mod 3) else break;
   end;
   if (x mod 3 = 0) then
      writeln(2) else begin
      writeln(1); 
      write(x);
   end;
end.
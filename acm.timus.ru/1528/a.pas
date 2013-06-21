var
   i : longint;
   x,y,z : int64;
begin
   while true do begin
      read(x,y);
      if (x = 0) and (y = 0) then break;
      z:=1;
      for i:=2 to x do 
         z:=(z*i) mod y;
      writeln(z);
   end;
end.
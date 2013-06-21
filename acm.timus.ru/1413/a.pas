var
   x,y : extended;
   ch : char;
   ex,ey : longint;
begin
   while not seekeoln do begin
      read(ch);
      if (ch = '1') then begin
         dec(ex);
         dec(ey);
      end;
      if (ch = '2') then
         y:=y-1;
      if (ch = '3') then begin
         inc(ex);
         dec(ey);
      end; 
      if (ch = '4') then 
         x:=x-1;
      if (ch = '6') then 
         x:=x+1;
      if (ch = '7') then begin
         inc(ey);
         dec(ex);
      end;
      if (ch = '8') then
         y:=y+1;
      if (ch = '9') then begin
         inc(ex);
         inc(ey);
      end;
      if (ch = '0') then break;
   end; 
   x:=x+ex*(1/(sqrt(2)));
   y:=y+ey*(1/(sqrt(2)));
   write(x:0:10,' ',y:0:10);
end.
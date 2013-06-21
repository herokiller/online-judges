var
   s : extended;
   n,i,x,x1,x2,y,y1,y2 : longint;
begin
   read(s);
   read(x1,y1,x2,y2);
   read(n);

   for i:=1 to n do begin
      read(x,y);
      if (x1*y - x*y1 = 0) then
         if (x*x1 < 0) or (y*y1 < 0) then begin
            write('NO');
            if (i = n) then break;
            writeln;
            continue;
         end;
      if (x*y2 - x2*y = 0) then
         if (x*x2 < 0) or (y*y2 < 0) then begin
            write('NO');
            if (i = n) then break;
            writeln;
            continue;
         end;
      if (((x1*y - x*y1)*(x*y2 - x2*y)) >= 0) and
         ((x1*y - x*y1)*(x1*y2 - x2*y1) >= 0) then
         if (s >= sqrt(sqr(x)+sqr(y))) then
            write('YES') else write('NO')
      else write('NO');
      if (i = n) then break;
      writeln;
   end;
   close(output);
end.

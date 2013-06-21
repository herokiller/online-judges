var
   n,cur,curn,i,j,x : longint;
begin
   read(n); 
   cur:=0; 
   curn:=0;
   for i:=1 to n do begin
      read(x);
      if (cur = 0) then begin 
         cur:=x;
         curn:=1;
         continue;
      end; 
      if (cur = x) then begin
         inc(curn);
         continue;
      end;
      if (cur <> x) then begin
         if (curn > 0) then begin
            write(curn,' ',cur,' ');
            curn:=1;
            cur:=x;
         end;
      end; 
   end;
   if (curn <> 0) then 
      write(curn,' ',cur);
end.
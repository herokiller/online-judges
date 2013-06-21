var
   b,y : extended;
   x,a,i,n,ans : longint;
begin
   read(a,b);
   read(n);
   ans:=0;
   if (a = 1) then begin
      for i:=1 to n do begin
         read(x,y); 
         if (x = 1) then 
            if (y <= b) then inc(ans); 
         if (x = 2) then 
            if (y <= b+b) then inc(ans);
         if (x = 3) then
            if (y*sqrt(3)/2 <= b+b) then inc(ans); 
      end;   
   end; 
   if (a = 2) then begin
      for i:=1 to n do begin
         read(x,y); 
         if (x = 1) then
            if (y+y <= b*sqrt(2)) then inc(ans);
         if (x = 2) then
            if (y <= b*sqrt(2)) then inc(ans); 
         if (x = 3) then
            if (y*sqrt(3)/2 <= b*sqrt(2)) then inc(ans); 
      end;    
   end;
   if (a = 3) then begin 
      for i:=1 to n do begin
         read(x,y); 
         if (x = 1) then
            if (y+y <= b) then inc(ans);
         if (x = 2) then 
            if (y <= b) then inc(ans);
         if (x = 3) then 
            if (y*sqrt(3)/2 <= b) then inc(ans);
      end;
   end;
   write(ans);
end.
var
   pr,x,y : real;
   ans : longint;
begin
   read(x,y); read(pr);
   pr:=pr/100;
   while true do begin
      if (x <= y) then begin
         write(ans); 
         halt(0);
      end;
      inc(ans);
      x:=x-x*pr;
   end;
end.
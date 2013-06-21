var
   n : longint;
begin
   read(n);
   if (n=1) then begin
      write(1,' ',2,' ',3);
      halt(0);
   end;

   if (n=2) then begin
      write(3,' ',4,' ',5);
      halt(0);
   end;

   write(-1);
end.
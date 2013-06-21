var
   n,x,x1,x2,x3,x4,i : longint;

begin
   read(n);
   x1:=1; x2:=1; x3:=1; x4:=1;
   for i:=1 to n do begin
      x1:=(x1*1) mod 10000;
      x2:=(x2*2) mod 10000;
      x3:=(x3*3) mod 10000;
      x4:=(x4*4) mod 10000;
      x:=(x1+x2+x3+x4) mod 10000;
   end;

   if (x mod 10000 = 0) then begin
      write(4);
      halt(0);
   end;
   if (x mod 1000 = 0) then begin
      write(3);
      halt(0);
   end;
   if (x mod 100 = 0) then begin
      write(2);
      halt(0);
   end;
   if (x mod 10 = 0) then begin
      write(1);
      halt(0);
   end;
   write(0);
end.
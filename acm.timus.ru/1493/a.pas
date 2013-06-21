var
   x0,x,x1,x2 : longint;
begin
   read(x); x1:=0; x2:=0;
   x:=x+1; 

   x1:=x1+(x div 100000);
   x0:=x div 10000; x0:=x0 mod 10;
   x1:=x1+x0;
   x0:=x div 1000; x0:=x0 mod 10;
   x1:=x1+x0;
   
   x2:=x2+(x mod 10);
   x0:=x div 10; x0:=x0 mod 10;
   x2:=x2+x0;
   x0:=x div 100; x0:=x0 mod 10;
   x2:=x2+x0;
   if (x1 = x2) then begin
      write('Yes');
      halt(0);
   end;
   
   x:=x-2; x1:=0; x2:=0;
   x1:=x1+(x div 100000);
   x0:=x div 10000; x0:=x0 mod 10;
   x1:=x1+x0;
   x0:=x div 1000; x0:=x0 mod 10;
   x1:=x1+x0;
   
   x2:=x2+(x mod 10);
   x0:=x div 10; x0:=x0 mod 10;
   x2:=x2+x0;
   x0:=x div 100; x0:=x0 mod 10;
   x2:=x2+x0;
   if (x1 = x2) then begin
      write('Yes');
      halt(0);
   end;
   write('No');
end.
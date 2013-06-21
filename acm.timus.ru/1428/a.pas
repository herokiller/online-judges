var
   x,y,z : int64;
   i,a,b,c,k,n,a1,b1 : longint;
begin
   read(a,b,c);
   a1:=(c-1) div a;
   b1:=(c-1) div b;
   z:=2;
   x:=1;
   y:=1;

   for i:=1 to a1 do
      x:=x*z;
   for i:=1 to b1 do
      y:=y*z;
   writeln(x);
   writeln(y);
   writeln(z);
   close(output);
end.

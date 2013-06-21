var
   n,i : longint;
   x1,x2,x3,k : int64;
begin
   read(n,k);
   x1:=0;
   x2:=k-1;
   for i:=2 to n do begin
      x3:=x1;
      x1:=x2;
      x2:=(k-1)*(x2+x3);
   end;
   write(x1+x2);
end.
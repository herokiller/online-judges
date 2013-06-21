var
   n,i : longint;
   x : int64;
begin
   read(n);
   for i:=1 to n do begin
      read(x);
      x:=x-1;
      x:=x+x;
      if (trunc(sqrt(x))*(trunc(sqrt(x))+1) = x) then write('1 ') else write('0 ');
   end;
end.

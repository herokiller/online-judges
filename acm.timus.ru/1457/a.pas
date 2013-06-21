var
   n,i : longint;
   sum,x : extended;
begin
   read(n);
   for i:=1 to n do begin
      read(x);
      sum:=sum+x;
   end;
   sum:=sum/n;
   write(sum:0:6);
end.
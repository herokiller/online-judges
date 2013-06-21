var
   n,i,x,y : longint;
   a : array [1..110000] of int64;
   max : int64;
begin 
   read(n);
   for i:=1 to n do
      read(a[i]);
   max:=-1;
   for i:=1 to n-1 do 
      if (abs(a[i]-a[i+1]) > max) then begin
         max:=abs(a[i]-a[i+1]);
         x:=i;
         y:=i+1;
      end;
   write(x,' ',y);
end.
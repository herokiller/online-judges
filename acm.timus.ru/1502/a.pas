var
   ans : int64;
   i,j,n : longint;
begin
   read(n);
   for i:=0 to n do
      for j:=i to n do
         ans:=ans+i+j;
   write(ans);
end.
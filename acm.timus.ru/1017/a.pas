var
   a : array [0..501,0..501] of int64;
   n,i,j,k : longint;
   sum : int64;
begin
   read(n);
   a[0,0]:=1;
   for i:=1 to n do
      for j:=1 to i do begin
          sum:=0;
          for k:=0 to j-1 do
             sum:=sum+a[i-j,k];
          a[i,j]:=sum;
      end;
   sum:=0;
   for i:=1 to n do
      sum:=sum+a[n,i];
   write(sum-1);
end.

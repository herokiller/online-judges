var
   a : array [1..50000] of longint;
   n,k,x,j,i,kol,ans : longint;
begin
   read(n,k);
   a[1]:=n;
   while not eof do begin
      read(x);
      if (x= -1) then break;
      read(k);
      for i:=1 to k do begin
         read(j);
         read(kol);
         a[j]:=kol;
         ans:=ans+kol*(a[x]-kol);
         a[x]:=a[x]-kol;
      end;
   end;
   write(ans);
end.

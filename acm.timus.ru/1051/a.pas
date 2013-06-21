var
   n,m,c,ans : longint;
begin
   read(n,m);
   if (m >= n) then begin
      c:=m;
      m:=n;
      n:=c;
   end;
   if (m=1) then ans:=(n+1) div 2 else begin
      if (m mod 3=0)or(n mod 3=0) then ans:=2 else ans:=1;
   end;
   write(ans);
end.
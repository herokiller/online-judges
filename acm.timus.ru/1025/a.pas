var
   a : array [1..200] of longint;
   i,n,ans,c,k : longint;
begin
   read(n);
   for i:=1 to n do read(a[i]);
   for k:=1 to n do 
      for i:=1 to n-1 do 
         if (a[i] > a[i+1]) then begin
            c:=a[i];
            a[i]:=a[i+1];
            a[i+1]:=c;
         end;
   for i:=1 to (n div 2)+1 do
      ans:=ans+(a[i] div 2)+1;
   write(ans); 
end.
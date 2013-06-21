var
   a : array [1..100] of longint;
   b : array [0..20000] of boolean;
   n,k,i,j : longint;
begin
   read(n,k);
   for i:=1 to k do read(a[i]);

   b[0]:=true;

   for i:=1 to n do begin
      for j:=1 to k do begin
         if (i-a[j] >= 0) then
            if (b[i-a[j]] = false) then b[i]:=true;
      end;
      if (b[i] = false) then b[i]:=false;
   end;

   if (b[n] = false) then
      write(2) else write(1);
end.
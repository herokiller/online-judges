var
   n,i : longint;
   w,r : array [1..100] of int64;
begin
   read(n);
   r[1]:=1;
   w[1]:=1;
   w[2]:=1;
   r[2]:=1;
   if (n =1) then begin
      write(2);
      halt(0);
   end;
   if (n =2) then begin
      write(2);
      halt(0);
   end;
   for i:=3 to n do begin
      r[i]:=w[i-2]+w[i-1];
      w[i]:=r[i-2]+r[i-1];
   end;
   write(w[n]+r[n]);
end.
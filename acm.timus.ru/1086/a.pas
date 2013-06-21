var
   a : array [1..20000] of longint;
   yk,i,j,n,x : longint;
   ok : boolean;
begin
   yk:=0;

   for i:=2 to 200000 do begin
      ok:=false;
      for j:=1 to yk do begin
         if (i mod a[j] = 0) then begin
            ok:=true;
            break;
         end;
         if (a[j] > trunc(sqrt(i))) then break;
      end;
      if not ok then begin
         inc(yk);
         a[yk]:=i;
      end;
   end;
   read(n);
   for i:=1 to n do begin
      read(x);
      writeln(a[x]);
   end;
end.

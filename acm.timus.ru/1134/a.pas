const
   maxn = 2000;
var
   a : array [1..maxn] of longint;
   b : array [1..maxn] of boolean;
   n,m,i,j,k,x : longint;
begin
   read(n,m);
   b[0]:=true;
   b[n+1]:=true;
   for i:=1 to m do begin
      read(x);
      if (x > n) then begin
         write('NO');
         halt(0);
      end;
      inc(a[x]);
   end;
   for i:=0 to n do begin
      if (a[i] >= 3) then begin
         write('NO');
         halt(0);
      end;
      if (a[i] = 2) then begin
         if (b[i] = false) and (b[i+1] = false) then begin
            b[i]:=true;
            b[i+1]:=true;
         end else begin
            write('NO');
            halt(0);
         end;
      end;
   end;
   for i:=0 to n do begin
      if (a[i] = 1) then begin
         if (b[i] = false) then begin
            b[i]:=true;
            continue;
         end;
         if (b[i+1] = false) then begin
            b[i+1]:=true;
            continue;
         end;
         write('NO');
         halt(0);
      end;
   end;
   write('YES');
end.
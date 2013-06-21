const
   maxn = 1100;
type
   q = 0..3;
var
   d : array [-1..maxn,-1..maxn,1..3] of byte;
   pr : array [0..maxn,0..maxn,1..3] of q;
   a1,a2 : array [1..maxn] of char;
   ans : array [1..maxn+maxn] of q;
   i,j,k,n,x,y,z,yk : longint;
begin
   readln(n);
   for i:=n downto 1 do
      read(a1[i]);
   readln;
   for i:=n downto 1 do
      read(a2[i]);
   d[0,0,1]:=1;

   for i:=0 to n do begin
      for j:=0 to n do begin
         if (a1[i] = '1') then begin
            if (d[i-1,j,1] = 1) then begin
               d[i,j,3]:=1;
               pr[i,j,3]:=1;
            end;
            if (d[i-1,j,2] = 1) then begin 
               d[i,j,1]:=1;
               pr[i,j,1]:=1;
            end; 
         end; 
         if (a1[i] = '0') then begin
            if (d[i-1,j,1] = 1) then begin 
               d[i,j,2]:=1;
               pr[i,j,2]:=1;
            end;
            if (d[i-1,j,3] = 1) then begin
               d[i,j,1]:=1;
               pr[i,j,1]:=1;
            end;
         end; 
         if (a2[j] = '1') then begin
            if (d[i,j-1,1] = 1) then begin 
               d[i,j,3]:=1;
               pr[i,j,3]:=2;
            end;  
            if (d[i,j-1,2] = 1) then begin 
               d[i,j,1]:=1;
               pr[i,j,1]:=2;
            end;
         end; 
         if (a2[j] = '0') then begin
            if (d[i,j-1,1] = 1) then begin
               d[i,j,2]:=1;
               pr[i,j,2]:=2;
            end;
            if (d[i,j-1,3] = 1) then begin
               d[i,j,1]:=1; 
               pr[i,j,1]:=2;
            end;
         end;
      end;
   end;
   
   if (d[n,n,1] = 1) then begin
      z:=1; x:=n; y:=n;
      for i:=1 to n+n do begin
         inc(yk);
         ans[yk]:=pr[x,y,z];
         if (pr[x,y,z] = 1) then begin
            if (a1[x] = '1') then begin
               if (z = 1) then z:=2;
               if (z = 3) then z:=1;
            end else begin
               if (z = 1) then z:=3;
               if (z = 2) then z:=1;
            end;
            dec(x);
         end else begin
            if (a2[y] = '1') then begin
               if (z = 1) then z:=2;
               if (z = 3) then z:=1;
            end else begin
               if (z = 1) then z:=3;
               if (z = 2) then z:=1;
            end;
            dec(y);
         end;
      end;
      for i:=1 to yk do
      write(ans[i]);
      halt(0);
   end else write('Impossible');

end.
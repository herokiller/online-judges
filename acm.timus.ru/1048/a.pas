var
   a,b,c : array [1..1000010] of longint;
   n,i,k : longint;
begin
  read(n);
  for i:=n downto 1 do read(a[i],b[i]);
 
  for i:=1 to n do begin
     c[i]:=c[i]+a[i]+b[i];
     if (c[i] >= 10) then begin
        c[i+1]:=c[i+1]+(c[i] div 10);
        c[i]:=c[i] mod 10;
     end;
  end;
  if (c[n+1] > 0) then k:=n+1 else k:=n;
 
  for i:=k downto 1 do write(c[i]);
end.
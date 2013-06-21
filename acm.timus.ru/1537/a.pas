const
        maxn = 10001000;
var
   i,k,p:longint;
   a:array[1..maxn]of longint;
begin
   read(k,p);
   a[2] := 1 mod p;
   for i:=2 to k-1 do begin
      if( i*2<=k ) then begin
         inc(a[i*2],a[i]);
         if( a[i*2]>=p ) then dec(a[i*2],p);
      end;
      inc(a[i+1],a[i]);
      if( a[i+1]>=p ) then dec(a[i+1],p);
   end;
   writeln(a[k]);
end.

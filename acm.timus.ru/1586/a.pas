const
   e = 1000000009;
   maxn = 1000;
var
   b : array [0..1000] of boolean;
   a,c : array [0..100] of longint;
   i,j,k,ans,n,pr : longint;
   ok : boolean;

begin
   for i:=2 to 999 do begin
      ok:=false;
      for j:=2 to i-1 do
         if (i mod j =0) then begin
            ok:=true;
            break;
         end;
      if (ok = false) then
         b[i]:=true;
   end;

   for i:=10 to 99 do
      a[i]:=1;

   read(n);
   for i:=3 to n do begin
      for j:=10 to 99 do
         for k:=0 to 9 do
            if b[j*10+k] then begin
               inc(c[(j*10+k) mod 100],a[j]);
               c[(j*10+k) mod 100]:=c[(j*10+k) mod 100] mod e;
            end;
      a:=c;
      fillchar(c,sizeof(c),0);
   end;

   for i:=0 to 99 do
      ans:=(ans + a[i]) mod e;
   write(ans);
end.
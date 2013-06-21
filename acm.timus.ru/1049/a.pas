var
   a : array [1..10] of longint;
   i,j,yk,n,ans : longint;
   pr,kol : array [1..1000] of longint;
   ok : boolean;
begin
   for i:=1 to 10 do
      read(a[i]);
   for i:=2 to 10000 do begin
      ok:=false;
      for j:=1 to 10 do
         if (a[j] mod i =0) then begin
            if (ok = false) then begin
               inc(yk);
               pr[yk]:=i;
               ok:=true;
            end;
            while true do begin
               inc(kol[yk]);
               a[j]:=a[j] div i;
               if (a[j] mod i <>0) then break;
            end;
         end;
   end;
   ans:=1;
   for i:=1 to yk do
      ans:=(ans*(kol[i]+1) mod 10);
   write(ans);
end.
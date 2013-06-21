var
   n,k,kol,ans,plus : longint;
begin
   read(n,k);
   ans:=0;
   kol:=1;
   plus:=0;
   while true do begin
      if (kol >= n) then begin
         write(ans);
         halt(0);
      end;
      plus:=kol;
      if (plus >= k) then begin
         plus:=k;
         ans:=ans+((n-kol) div plus);
         if ((n-kol) mod plus <> 0) then inc(ans);
         write(ans);
         halt(0);
      end else plus:=plus mod k;
      kol:=kol+plus;
      inc(ans);
   end;
end.

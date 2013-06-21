var
   s : string;
   max,i,n,j,k,ans,yk1,yk2,kol,pos : longint;
begin
   readln(s);
   max:=0;
   n:=length(s);
   for i:=1 to n-1 do begin
       yk1:=i; yk2:=i+1; kol:=0;
       while true do begin
          if (yk1 < 1) or (yk2 > n) then break;
          if (s[yk1] = s[yk2]) then inc(kol) else break;
          dec(yk1); inc(yk2);
       end;
       if (kol+kol > max) then begin
          max:=kol+kol;
          pos:=i-kol+1;
       end;
   end;

   for i:=1 to n do begin
       yk1:=i-1; yk2:=i+1; kol:=0;
       while true do begin
          if (yk1 < 1) or (yk2 > n) then break;
          if (s[yk1] = s[yk2]) then inc(kol) else break;
          dec(yk1); inc(yk2);
       end;
       if (kol+kol+1 > max) then begin
          max:=kol+kol+1;
          pos:=i-kol;
       end;
   end;

   for i:=pos to pos+max-1 do
      write(s[i]);
end.
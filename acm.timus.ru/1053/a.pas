var
   n,i,ans,x : longint;
function gcd(x1,x2 : longint) : longint;
 begin
    if (x1 = 0) then begin
       gcd:=x2;
       exit;
    end;
    if (x2 = 0) then begin
       gcd:=x1;
       exit;
    end;
    if (x1 >= x2) then gcd:=gcd(x1 mod x2,x2) else gcd:=gcd(x2 mod x1,x1);
 end;
begin
   read(n);
   read(ans);
   for i:=2 to n do begin
      read(x);
      ans:=gcd(ans,x);
   end;
   write(ans);
end.
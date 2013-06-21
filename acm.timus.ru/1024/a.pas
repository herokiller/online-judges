const
   maxn = 1010;
var
   a,st : array [1..maxn] of longint;
   b : array [1..maxn] of boolean;
   n,i,yk,kol,ans : longint;
function gcd(x1,x2 : longint) : longint;
 begin
    if (x1 = x2) then begin
       gcd:=x1;
       exit;
    end;
    if (x1 = 0) then begin
       gcd:=x2;
       exit;
    end;
    if (x2 = 0) then begin
       gcd:=x1;
       exit;
    end;
    if (x1 > x2) then gcd:=gcd(x2,x1 mod x2) else gcd:=gcd(x1,x2 mod x1);
 end;
procedure rec(pos : longint);
 begin
    kol:=0;
    while true do begin
       inc(kol);
       b[pos]:=true;
       pos:=a[pos];
       if (b[pos] = true) then break;
    end;
 end;
begin
   read(n);
   for i:=1 to n do
      read(a[i]);
   for i:=1 to n do
      if (b[i] = false) then begin
         rec(i);
         inc(yk);
         st[yk]:=kol;
      end;
   ans:=1;
   for i:=1 to yk do
      ans:=(ans*st[i]) div (gcd(ans,st[i]));
   write(ans);
end.
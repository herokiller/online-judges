var
   n,m : longint;
function gcd(q1,q2:longint):longint;
 begin
    while(q1>0)and(q2>0)do if q1>q2 then q1:=q1 mod q2 else q2:=q2 mod q1;
    gcd:=q1+q2;
 end;

begin
   read(n,m);
   n:=n-1; m:=m-1;
   write(n+m-gcd(n,m));
end.

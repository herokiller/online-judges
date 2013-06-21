const
   maxn = 20000;
var
   a : array [1..maxn] of longint;
   n,i,x,k,ans : longint;
function check(x : longint) : boolean;
var
    x1,x2,x3 : longint;
 begin
    x1:=1; x3:=n;
    check:=false;
    while true do begin
       x2:=(x1+x3) div 2;
       if (x1 = x3) then begin
          if (a[x1] = x) then begin
             check:=true;
             exit;
          end else begin
             check:=false;
             exit;
          end;
       end;
       if (x1+1 = x3) then begin
          if (a[x1] = x) or (a[x3] = x) then begin
             check:=true;
             exit;
          end else begin
             check:=false;
             exit;
          end;
       end;
       if (a[x2] = x) then begin
          check:=true;
          exit;
       end;
       if (a[x2] > x) then
          x3:=x2 else x1:=x2;
    end;
 end;

begin
   read(n);
   for i:=1 to n do read(a[i]);
   ans:=0;
   read(k);
   for i:=1 to k do begin
      read(x);
      if check(x) then inc(ans);
   end;
   write(ans);
end.

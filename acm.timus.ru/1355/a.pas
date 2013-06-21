var
   p1,p2,i,x,t,nt : longint;

function get(x : longint) : longint;
var
        i,kol : longint;
 begin
    i:=1;
    kol:=1;
    while (i <= trunc(sqrt(x))) do begin
       inc(i);
       if (x mod i =0) then
          while true do begin
             inc(kol);
             x:=x div i;
             if (x mod i <> 0) then break;
          end;
    end;
    if (x <> 1) then inc(kol);
    get:=kol;
 end;

begin
   read(nt);
   for t:=1 to nt do begin
      read(p1,p2);
      if (p2 mod p1 <> 0) then begin
         writeln(0);
         continue;
      end else begin
         x:=p2 div p1;
         writeln(get(x));
      end;
   end;
end.
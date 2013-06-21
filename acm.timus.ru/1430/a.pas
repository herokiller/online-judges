var
   d : array [0..2000000] of boolean;
   a,b,c,sum,x,y,ak,min : longint;
begin
   read(a,b,sum);
   if (a < b) then begin
      c:=a;
      a:=b;
      b:=c;
   end;
   x:=(sum mod a) mod b;
   ak:=sum div a;
   min:=maxlongint;

   while (ak >= 0) do begin
      if (x < min) then begin
         min:=x;
         y:=ak;
      end;
      if x<2000000 then begin
         if d[x] then
            break;
         d[x]:=true;
      end;

      x:=(x+a) mod b;
      dec(ak);
   end;

   x:=(sum - a*y) div b;

   if (c = 0) then writeln(y,' ',x) else writeln(x,' ',y);
end.
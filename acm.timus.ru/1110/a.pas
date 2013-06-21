var
   n,m,x,y,i,j : longint;
   ok : boolean;
begin
   read(n,m,y);
   for i:=0 to m-1 do begin
      x:=1;
      for j:=1 to n do
         x:=(x*i) mod m;
      if (x = y) then begin
         write(i,' ');
         ok:=true;
      end;
   end;
   if not ok then write(-1);
end.

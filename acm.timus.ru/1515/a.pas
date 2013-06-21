var
   n,i,last,cur : longint;
begin
   read(n);
   for i:=1 to n do begin
      read(cur);
      if (last + 1 >= cur) then
         inc(last,cur) else break;
   end;
   write(last+1);
end.
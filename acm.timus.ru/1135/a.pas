var
   i,n  : longint;
   l,r  : int64;
   ch : char;
begin
   readln(n);
   while not eof do begin
      read(ch);
      if ch = '>' then inc(r);
      if ch = '<' then inc(l,r);
   end;
   write(l);
end.
var
   ch : char;
   n,i,l,e,m : longint;
begin
   readln(n);
   for i:=1 to n do begin
      readln(ch);
      if (ch = 'L') then inc(l);
      if (ch = 'E') then inc(e);
      if (ch = 'M') then inc(m);
   end;
   if (m > l) and (m > e) then write('Macaroni Penguin'); 
   if (l > m) and (l > e) then write('Little Penguin');
   if (e > l) and (e > m) then write('Emperor Penguin');
end.
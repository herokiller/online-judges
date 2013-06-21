{$H+}
var
   s : array [1..10000] of char;
   ch : char;
   n,i,j,k,len,sum,kol,ans,pos : longint;
begin
   readln(n);
   while not eof do begin
      len:=0;
      while not seekeoln do begin
         inc(len);
         read(s[len]);
      end;
      readln;
      sum:=0;
      for j:=1 to len do
         if (s[j] = '1') then sum:=sum+j;
      if (len = n) then begin
         s[sum mod (n+1)]:='0';
         for j:=1 to len do write(s[j]);
         writeln;
         continue;
      end;
      if (len > n) then begin
         kol:=0;
         pos:=0;
         for j:=len downto 1 do begin
            ans:=sum-kol;
            if (s[j] = '1') then begin
               ans:=ans-j;
               inc(kol);
            end;
            if (ans mod (n+1) = 0) then begin
               pos:=j;
               break;
            end;
         end;
         for j:=1 to len do
            if (j = pos) then continue else write(s[j]);
         writeln;
         continue;
      end;
      if (len < n) then begin
         kol:=0;
         pos:=0;
         for j:=len downto 0 do begin
            ans:=sum;
            ans:=ans+j+1+kol;
            if (ans mod (n+1) = 0) then begin
               pos:=j;
               ch:='1';
               break;
            end;
            ans:=ans-j-1;
            if (ans mod (n+1) = 0) then begin
               pos:=j;
               ch:='0';
               break;
            end;
            if (s[j] = '1') then
               inc(kol);
         end;
         if (pos = 0) then
            write(ch);
         for j:=1 to len do
            if (j = pos) then write(s[j],ch) else write(s[j]);
         writeln;
         continue;
      end;
   end;
end.

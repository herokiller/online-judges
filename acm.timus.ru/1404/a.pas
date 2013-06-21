var
   s : string;
   ans : array [1..20000] of char;
   i,n,x : longint;
begin
   readln(s); n:=length(s);
   for i:=n downto 1 do begin
      x:=ord(s[i])-ord('a');
      x:=x-(ord(s[i-1])-ord('a'));
      if (x < 0) then inc(x,26);
      ans[i]:=chr(x+ord('a'));
   end;
   x:=ord(s[1])-5-ord('a');
   if (x < 0) then inc(x,26);
   ans[1]:=chr(x+ord('a'));
   for i:=1 to n do write(ans[i]);
end.
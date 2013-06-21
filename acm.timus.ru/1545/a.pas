var
   ch : char;
   s1,s2 : array [1..2000] of char;
   n,i : longint;
begin
   readln(n);
   for i:=1 to n do 
      readln(s1[i],s2[i]);
   read(ch);
   for i:=1 to n do
      if (s1[i] = ch) then writeln(s1[i],s2[i]);
end.
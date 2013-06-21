var
   s : array [1..200] of string;
   b : array [1..200] of boolean;
   n,i,j : longint;
begin
   readln(n);
   for i:=1 to n do begin
      readln(s[i]);
      for j:=i-1 downto 1 do begin
         if (s[i] = s[j]) and (not b[j]) then begin
            writeln(s[j]);
            b[i]:=true;
            b[j]:=true;
         end;
         if (s[i] = s[j]) and (b[j]) then 
            b[i]:=true;
      end;
   end; 
end.
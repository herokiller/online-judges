var
   s : array [1..200] of string;
   n,i,j : longint;
begin
   readln(n);
   for i:=1 to n do 
      readln(s[i]);

   if ((n = 2) and (s[1] = s[2])) or (n = 1) then begin
      writeln(0);
      halt(0);
   end;
   if (n = 2) then begin
      writeln(1);
      writeln(s[1],'-',s[2]);
      halt(0);
   end;
   for i:=1 to n do
      for j:=i+1 to n do
         if (s[i] = s[j]) then begin 
            writeln('Impossible');
            halt(0);
         end;
   writeln(n);
   for i:=1 to n do 
      writeln(s[i],'-','htygkemm');
end.
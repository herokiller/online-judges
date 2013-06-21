const
   maxn = 1010;
var 
   b : array [1..maxn] of boolean;
   s : array [1..maxn] of string;
   n,i,j,ans : longint;
begin
   readln(n);
   for i:=1 to n do
      readln(s[i]);
   for i:=1 to n do
      if (b[i] = false) then
         for j:=i+1 to n do 
            if (s[i] = s[j]) then begin
               inc(ans);
               b[j]:=true; 
            end;    
   write(ans);
end.
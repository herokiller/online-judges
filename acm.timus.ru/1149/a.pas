{$H+}
const
   maxn = 500;
var
   ans : string;
   s : array [1..maxn] of string;
   n,i,j,x1,x2,x3 : longint;
begin
   read(n);
   for i:=1 to n do begin
      for j:=1 to i do begin
         s[i]:=s[i]+'sin(';
         x1:=j div 100;
         x2:=(j div 10) mod 10;
         x3:=j mod 10;
         if (x1 <> 0) then s[i]:=s[i]+chr(x1+48);
         if (x1 <> 0) or (x2 <> 0) then s[i]:=s[i]+(chr(x2+48));
         if (x1 <> 0) or (x2 <> 0)
         or (x3 <> 0) then s[i]:=s[i]+(chr(x3+48));
         if (j mod 2 = 1) and (j <> i) then s[i]:=s[i]+'-';
         if (j mod 2 = 0) and (j <> i) then s[i]:=s[i]+'+';
      end;
      for j:=1 to i do
         s[i]:=s[i]+')';
   end;

   for i:=1 to n-1 do
      ans:=ans+'(';
   for i:=1 to n do begin
      ans:=ans+s[i]+'+';
      x1:=(n-i+1) div 100;
      x2:=((n-i+1) div 10) mod 10;
      x3:=(n-i+1) mod 10;
      if (x1 <> 0) then ans:=ans+chr(x1+48);
         if (x1 <> 0) or (x2 <> 0) then ans:=ans+(chr(x2+48));
         if (x1 <> 0) or (x2 <> 0)
         or (x3 <> 0) then ans:=ans+(chr(x3+48));
      if i <> n then
      ans:=ans+')';
   end;
   write(ans);
end.
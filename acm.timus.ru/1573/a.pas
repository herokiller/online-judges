var
   ch : char;
   b,r,y,k,i,ans : longint;
begin
   readln(b,r,y);
   readln(k);
   ans:=1;
   for i:=1 to k do begin
      readln(ch); 
      if (ch = 'B') then ans:=ans*b;
      if (ch = 'R') then ans:=ans*r;
      if (ch = 'Y') then ans:=ans*y;
   end;
   write(ans);
end.
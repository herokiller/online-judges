var
   s : string;
   x,k,ans : longint;
begin
   readln(s);
   x:=ord(s[1])-ord('0');
   k:=length(s)-2;
   if (s[2]='0') then begin
      x:=10;
      k:=k-1;
   end;
   ans:=1;
   if (k >= x) then begin
      write(x);
      halt(0);
   end;
   while true do begin
      ans:=ans*x;
      x:=x-k;
      if (x<=0) then break;
   end;
   write(ans);
end.
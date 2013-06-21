var
   sum,i,n,ans : longint;
   s,s1 : string;
   zn : char;

begin
   s1:='';
   readln(s); n:=length(s);
   for i:=n downto 1 do
      s1:=s1+s[i];
   s1:=s1+'000';
   if (n mod 3 =1) then n:=n+2;
   if (n mod 3 =2) then n:=n+1;

   sum:=0;
   zn:='-';
   i:=1;
   while (i <= (n-2)) do begin
      if (zn = '-') then zn:='+' else zn:='-';
      if (zn = '+') then sum:=sum+(ord(s1[i])-ord('0'))+
      10*(ord(s1[i+1])-ord('0'))+100*(ord(s1[i+2])-ord('0'));
      if (zn = '-') then sum:=sum-(ord(s1[i])-ord('0'))-
      10*(ord(s1[i+1])-ord('0'))-100*(ord(s1[i+2])-ord('0'));
      i:=i+3;
   end;
   if (sum < 0) then begin
      ans:=7-(abs(sum) mod 7);
      if(ans = 7) then ans:=0;
   end else ans:=sum mod 7;
   write(ans);
end.
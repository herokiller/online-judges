var
   n1,n2,n3,c1,c2,t,i,n,min,basic,combined : longint;
   s : string;
begin
   readln(n1,c1);
   readln(n2,t,c2);
   readln(n3);
   readln(n);
   for i:=1 to n do begin
      readln(s);
      if(s[1]='0')and(s[2]='0')and
        (s[4]='0')and(ord(s[5])-ord('0')<=6)then continue;
      min:=min+(10*(ord(s[1])-ord('0'))+(ord(s[2])-ord('0')));
      if (s[4]<>'0') or (s[5]<>'0') then inc(min);   
   end;
   basic:=n1+c1*min;
   combined:=n2;
   if (t < min) then inc(combined,(min-t)*c2);
   writeln('Basic:     ',basic);
   writeln('Combined:  ',combined);
   writeln('Unlimited: ',n3);
end.
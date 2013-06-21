
var
   s,s1 : string;
   ans,n,pos,i,k : longint;
begin
   readln(s);
   n:=length(s);
   for i:=1 to n do
      if (s[i] = '(') then
         inc(k) else dec(k);

   if (k <> 0) then begin
      write(0);
      halt(0);
   end;

   pos:=0;
   k:=0;

   for i:=1 to n do begin
      if (s[i] = ')') then
         dec(k) else inc(k);
      if (k < 0) then begin
         pos:=i;
         k:=0;
      end;
   end;

   s1:='';

   for i:=pos+1 to n do
      s1:=s1+s[i];

   for i:=1 to pos do
      s1:=s1+s[i];

   ans:=0;

   k:=0;
   for i:=1 to n do begin
      if (s1[i] = '(') then
         inc(k) else dec(k);
      if k=0 then inc(ans);
   end;

   write(ans);
end.
{$H+}
var
   s : string;
   s1 : array [1..3000] of longint;
   n,i,x : longint;

procedure exi;
var
        i : longint;
 begin
    for i:=1 to n do write(s1[i]);
    halt(0);
 end;

procedure exi2;
var
        i : longint;
 begin
    x:=(n div 2)+(n mod 2);
    while true do begin
       inc(s1[x]);
       if (s1[x] < 10) then break else begin s1[x]:=0; dec(x); end;
    end;
    for i:=n downto (n div 2)+1 do
      s1[i]:=s1[n-i+1];
    exi;
 end;
begin
   readln(s); n:=length(s);
   for i:=1 to n do
      s1[i]:=ord(s[i])-ord('0');

   for i:=n downto (n div 2)+1 do
      s1[i]:=s1[n-i+1];

   for i:=1 to n do begin
      if (s1[i] > ord(s[i])-ord('0')) then exi;
      if (s1[i] < ord(s[i])-ord('0')) then exi2;
   end;
   exi;
end.

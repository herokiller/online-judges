{$H+}
const
   maxn = 100100;
   let : set of char = ['A'..'z'];
var
   yk,k,i,j,max : longint;
   s : string;
   ch : char;
   st : array [1..maxn] of longint;
   a : array [0..maxn,0..1] of longint;
begin
   s:=' ';
   while not eof do begin
      read(ch);
      s:=s+ch;
      if eoln then begin
         readln;
         s:=s+' ';
      end;
      if eof then break;
   end;

   i:=1;
   while (i < length(s)) do begin
      inc(i);
      if (not (s[i-1] in let)) and (s[i] in let) then
         for j:=i to length(s) do
            if (s[j] in let) then
               inc(k)
            else begin
               inc(yk);
               st[yk]:=k;
               i:=j-1;
               k:=0;
               break;
            end;
   end;

   for i:=1 to yk do begin
      a[i,1]:=a[i-1,0]+st[i];
      if (a[i-1,1] > a[i-1,0]) then
         a[i,0]:=a[i-1,1] else a[i,0]:=a[i-1,0]
   end;

   max:=a[yk,1]; if (a[yk,0] > max) then max:=a[yk,0];

   write(max);
end.

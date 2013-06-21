{$H+}
type
  mass = array [1..20000] of char;
const
   let : set of char = ['a'..'z'];
var
   d : array [1..210] of mass;
   l : array [1..210] of longint;
   s,s1 : string;
   x : mass;
   n,i,j,k,kol,pos,ans : longint;
begin
   while true do begin
      readln(s);
      if (s = '#') then break;
      inc(n);
      for i:=1 to length(s) do
         d[n][i]:=s[i];
      l[n]:=length(s);
   end;

   while not eof do begin
      readln(s);
      s:=s+' ';
      for i:=1 to length(s) do
         x[i]:=s[i];
      if (s='') and eof then
         break;
      i:=0;
      while (i < length(s)) do begin
         inc(i);
         if (s[i] in let) then begin
            s1:='';
            for j:=i to length(s) do
               if (s[j] in let) then
                  s1:=s1+s[j] else begin i:=j; break; end;
            for j:=1 to n do
               if (length(s1) = l[j]) then begin
                  kol:=0;
                  pos:=0;
                  for k:=1 to length(s1) do
                     if (s1[k] <> d[j][k]) then begin
                        inc(kol);
                        pos:=k;
                     end;
                  if kol = 1 then begin
                     x[i-length(s1)+pos-1]:=d[j][pos];
                     inc(ans);
                     dec(i);
                     break;
                  end;
               end;
         end;
      end;
      for i:=1 to length(s)-1 do
         write(x[i]);
      writeln;
   end;
   write(ans);
end.
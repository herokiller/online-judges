const
   maxn = 2000;
var
   s,g,r,h : array [1..maxn] of string;
   y1,y2,y3,y4,n,i : longint;
   s1 : string;
   ch : char;
begin
   readln(n);
   for i:=1 to n do begin
      readln(s1);
      read(ch);
      if (ch = 'S') then begin
         inc(y1);
         s[y1]:=s1;
      end;
      if (ch = 'H') then begin
         inc(y2);
         h[y2]:=s1;
      end;
      if (ch = 'G') then begin
         inc(y3);
         g[y3]:=s1;
      end;
      if (ch = 'R') then begin
         inc(y4);
         r[y4]:=s1;
      end;
      readln;
   end;

   writeln('Slytherin:');
   for i:=1 to y1 do writeln(s[i]);
   writeln;
   writeln('Hufflepuff:');
   for i:=1 to y2 do writeln(h[i]);
   writeln;
   writeln('Gryffindor:');
   for i:=1 to y3 do writeln(g[i]);
   writeln;
   writeln('Ravenclaw:');
   for i:=1 to y4 do writeln(r[i]);
end.
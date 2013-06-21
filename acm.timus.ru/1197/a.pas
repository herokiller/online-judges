var
   ch1,ch2 : char;
   n,i,x,y,ans : longint;
begin
   readln(n);
   for i:=1 to n do begin
      ans:=0;
      read(ch1); read(ch2); readln;
      x:=ord(ch1)-ord('a')+1; y:=ord(ch2)-ord('0');
      if (x+2 <= 8) and (y+1 <= 8) then inc(ans); 
      if (x+1 <= 8) and (y+2 <= 8) then inc(ans); 
      if (x+2 <= 8) and (y-1 >= 1) then inc(ans); 
      if (x+1 <= 8) and (y-2 >= 1) then inc(ans);
      if (x-2 >= 1) and (y+1 <= 8) then inc(ans); 
      if (x-1 >= 1) and (y+2 <= 8) then inc(ans); 
      if (x-2 >= 1) and (y-1 >= 1) then inc(ans); 
      if (x-1 >= 1) and (y-2 >= 1) then inc(ans);
      writeln(ans);
   end;
end.
var
   a : array [0..200000] of longint;
   i,x,max : longint;
begin 
   a[0]:=0;
   a[1]:=1;
   for i:=2 to 200000 do begin
      if (i mod 2 =0) then a[i]:=a[i div 2] 
      else a[i]:=a[i div 2]+a[(i div 2) +1];
   end;
   while not eof do begin
      read(x);
      if (x=0) then break;
      max:=-maxlongint;
      for i:=1 to x do 
         if (a[i] > max) then max:=a[i];
      writeln(max);
   end; 
end.
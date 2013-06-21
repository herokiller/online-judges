var
   s : string;
   scr : array [1..80] of char;
   pos,i,j,n : longint;
begin
   pos:=1;
   fillchar(scr,sizeof(scr),' ');
   while not eof do begin
      readln(s);
      if s='' then break;
      for i:=1 to length(s) do begin
         if (s[i] = '>') then begin
            inc(pos);
            if pos=81 then pos:=1;
            continue;
         end;
         if (s[i] = '<') then begin
            dec(pos);
            if (pos = 0) then pos:=1;
            continue;
         end;
         scr[pos]:=s[i];
         inc(pos);
         if pos=81 then pos:=1;
      end;
   end;
   for i:=1 to 80 do
      write(scr[i]);
end.

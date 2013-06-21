const
   let : set of char = ['A'..'Z'];
   let2 : set of char = ['a'..'z'];
var
   s : string;
   ok : boolean;
   i : longint;
begin
   ok:=true;
   while not eof do begin
      readln(s);
      for i:=1 to length(s) do begin
         if (s[i] in let) then
            if ok then begin
               write(s[i]);
               ok:=false;
            end else write(chr(ord(s[i])+32))
         else write(s[i]);

         if (s[i] = '.') or (s[i] = '!') or (s[i] = '?') then ok:=true;
      end;
      writeln;
   end;
end.
{$H+}
const 
   lit  : set of char = ['a'..'z'];
   big : set of char = ['A'..'Z'];
var  
   s,s1 : string;
   i,ans : longint;
   ok : boolean;
begin
   s1:=' ';
   while not eof do begin
      readln(s);
      s1:=s1+s+' ';
   end;
   ok:=true;
   for i:=1 to length(s1) do begin
      if (ok = true) and (s1[i] in lit) then begin
         inc(ans);
         ok:=false;
      end;
      if (s1[i] in big) and (ok = true) then begin
         ok:=false;
      end;
      if (s1[i] in big) and 
      ((s1[i-1] in lit) or (s1[i-1] in big) ) then begin
         inc(ans);
      end;
      if (s1[i] = '.') or (s1[i] = '!') 
      or (s1[i] = '?') then begin
         ok:=true;
      end;
   end;
   write(ans);
end.
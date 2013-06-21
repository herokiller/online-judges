const
   a:set of char=['a','d','g','j','m','p','s','v','y','.',' '];
   b:set of char=['b','e','h','k','n','q','t','w','z',','];
   c:set of char=['c','f','i','l','o','r','u','x','!'];
var
   s : string;
   ans,i : longint;
begin 
   ans:=0;
   readln(s);
   for i:=1 to length(s) do begin
      if (s[i] in a) then inc(ans); 
      if (s[i] in b) then inc(ans,2);
      if (s[i] in c) then inc(ans,3);
   end;
   write(ans);
end.
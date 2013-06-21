var

   s1,s2,add1,add2,x,y,ans : longint;
begin
   read(s1,add1,s2,add2);
   if (s1 >= s2) then begin
      writeln(s1);
      halt(0);
   end;
   x:=(s2 - s1) div (add1+add2); y:=(s2-s1) mod (add1+add2);
   ans:=s1+x*add1;

   if (y > add1) then inc(ans,add1) else inc(ans,y);

   writeln(ans);
end.
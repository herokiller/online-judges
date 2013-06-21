var
   ans,n,i : longint;
begin
   read(n); 
   ans:=0;
   if (n >= 1) then begin
      for i:=1 to n do ans:=ans+i;
      write(ans);
   end else begin
      for i:=1 downto n do ans:=ans+i;
      write(ans);
   end;
end.
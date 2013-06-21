var
   x,y,i,j,ans,sum,q : longint;
   ok : boolean;
begin
   read(x,y);
   if x = 1 then begin
      write(1);
      halt(0);
   end;
   for i:=y downto x do begin
      ok:=true;
      for j:=2 to trunc(sqrt(i)) do
         if (i mod j = 0) then begin
            ok:=false;
            break;
         end; 
      if ok then begin
         write(i);
         halt(0);
      end;
   end;
   ans:=maxlongint;
   for i:=x to y do begin
      sum:=1;
      for j:=2 to i-1 do
         if (i mod j = 0) then sum:=sum+j;
      if (sum < ans) then begin
         ans:=sum;
         q:=i;
      end;
   end;   
   write(q);
end.
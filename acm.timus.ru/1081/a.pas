var
   a,ans : array [0..45] of longint;
   n,k,i,sum : longint;
begin
   read(n,k);
   a[0]:=1;
   a[1]:=1;
   sum:=2;
   for i:=2 to 44 do begin
      a[i]:=sum-a[i-1];
      inc(sum,a[i]);
   end;

   while (k > 0) do begin
      sum:=0;
      for i:=0 to 44 do begin
         inc(sum,a[i]);
         if (sum >= k) then begin
            ans[i]:=1;
            dec(k,a[i+1]);
            break;
         end;
      end;
   end;

   for i:=n+1 to 44 do
      if (ans[i] = 1) then begin
         write(-1);
         halt(0);
      end;

   for i:=n downto 1 do
      write(ans[i]);
end.
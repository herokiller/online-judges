var
   k1,k2,k3 : extended;
   ans : longint;
begin
   read(k1,k2,k3);
   ans:=round((1000*k2)/(k2/k3+k2/k1+1));
   write(ans);
end.

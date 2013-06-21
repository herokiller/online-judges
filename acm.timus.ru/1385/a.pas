var
   n,ans,x,i,y : longint;
begin
   read(n);
  if (n = 1) then begin
     write(14);
     halt(0);
  end;
  if (n = 2) then begin
     write(155);
     halt(0);
  end;
  if (n >= 3) then begin
     write(1575);
  end;
  for i:=1 to n-3 do
     write(0);
end.

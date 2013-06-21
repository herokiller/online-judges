const
   maxn = 1010;
   b1 : array [1..4] of longint = (0,0,1,-1);
   b2 : array [1..4] of longint = (-1,1,0,0);
var
   a : array [0..maxn,0..maxn] of char;
   ok : boolean;
   i,j,k,n : longint;
begin
   fillchar(a,sizeof(a),'0');
   readln(n);
   for i:=1 to n do begin 
      for j:=1 to n do 
         read(a[i,j]);
      readln;
   end;
  
   for k:=1 to 4 do begin
      ok:=false;
      for i:=1 to n do 
         for j:=1 to n do 
            if (a[i+b1[k],j+b2[k]] = '1') and (a[i,j] = '0') 
            then begin
               ok:=true; 
               break;    
            end; 
      if (ok = false) then begin
         write('Yes');
         halt(0);
      end;
   end;
   write('No');
end.
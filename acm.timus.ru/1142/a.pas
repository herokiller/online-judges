type
   mass = array [1..100] of longint;

const
   maxn = 110;
var
   n,i,j,k : longint;
   x,y,z,ans : mass;
   a : array [-1..maxn,-1..maxn] of mass;

procedure sum;
var
        i : longint;
 begin
    for i:=1 to 100 do begin
       x[i]:=x[i]*k;
       y[i]:=y[i]*k;
       z[i]:=x[i]+y[i];
    end;
    for i:=1 to 100 do begin
       if (z[i] >= 1000) then begin
          z[i+3]:=z[i+3]+(z[i] div 1000);
          z[i]:=z[i] mod 1000;
       end;
       if (z[i] >= 100) then begin
          z[i+2]:=z[i+2]+(z[i] div 100);
          z[i]:=z[i] mod 100;
       end;
       if (z[i] >= 10) then begin
          z[i+1]:=z[i+1]+(z[i] div 10);
          z[i]:=z[i] mod 10;
       end;
    end;
 end;

begin
   a[2,0,1]:=2;
   a[2,1,1]:=1;
   for i:=3 to 100 do
      for j:=0 to i-1 do begin
         k:=i-j;
         x:=a[i-1,j-1];
         y:=a[i-1,j];
         sum;
         a[i,j]:=z;
      end;

   while true do begin
      read(n);
      if n=-1 then break;
      fillchar(ans,sizeof(ans),0);
      for i:=0 to n-1 do
         for j:=1 to 100 do
            ans[j]:=ans[j]+a[n,i,j];
      for i:=1 to 100 do begin
          if (ans[i] >= 1000) then begin
             ans[i+3]:=ans[i+3]+(ans[i] div 1000);
             ans[i]:=ans[i] mod 1000;
          end;
          if (ans[i] >= 100) then begin
             ans[i+2]:=ans[i+2]+(ans[i] div 100);
             ans[i]:=ans[i] mod 100;
          end;
          if (ans[i] >= 10) then begin
             ans[i+1]:=ans[i+1]+(ans[i] div 10);
             ans[i]:=ans[i] mod 10;
          end;
      end;
      for i:=100 downto 1 do
         if (ans[i] <> 0) then begin
            for j:=i downto 1 do
               write(ans[j]);
            writeln;
            break;
         end;
   end;
   close(output);
end.
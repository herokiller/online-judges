type
   mass = array [0..5,0..5] of char;
const
   eps = 65536;
   d1 : array [1..5] of longint = (0,0,0,1,-1);
   d2 : array [1..5] of longint = (0,-1,1,0,0);
var
   ans : array [1..eps] of longint;
   st : array [1..eps] of mass;
   b : array [0..eps] of boolean;
   a  : mass;
   n,i,j,k,num,yk : longint;
procedure turn(a : mass);
var
        i,j,st : longint;
 begin
    st:=eps;
    num:=0;
    for i:=1 to 4 do
       for j:=1 to 4 do begin
          st:= st div 2;
          if (a[i,j] = 'w') then num:=num+st;
       end;
 end;

procedure make(x,y : longint);
var
        i,j : longint;
 begin
    for i:=1 to 5 do
       if (a[x+d1[i],y+d2[i]] = 'w') then a[x+d1[i],y+d2[i]]:='b'
       else a[x+d1[i],y+d2[i]]:='w';
 end;

begin
   for i:=1 to 4 do begin
      for j:=1 to 4 do
         read(a[i,j]);
      readln;
   end;
   turn(a);
   if (num = 0) or (num = eps-1) then begin
      write(0);
      halt(0);
   end;
   b[num]:=true;
   k:=0;
   inc(yk); st[yk]:=a;
   while (k < yk) do begin
      inc(k);
      for i:=1 to 4 do
         for j:=1 to 4 do begin
            a:=st[k];
            make(i,j);
            turn(a);
            if (b[num] = false) then begin
               inc(yk);
               st[yk]:=a;
               ans[yk]:=ans[k]+1;
               b[num]:=true;
               if (num = 0) then begin
                  write(ans[yk]);
                  halt(0);
               end;
               if (num = eps -1) then begin
                  write(ans[yk]);
                  halt(0);
               end;
            end;
         end;
   end;

   write('Impossible');
end.

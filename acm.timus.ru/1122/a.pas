type
   board1 = array [0..5,0..5] of char;
const
   s = 32768;
var
   board : board1;
   patt : array [1..3,1..3] of char;
   st : array [0..66000] of board1;
   b : array [0..66000] of boolean;
   kol : array [0..66000] of longint;
   i,yk,j,num : longint;

procedure check;
var
	i : longint;
 begin
    if (b[0] = true) or (b[65535] = true) then begin
       write(kol[yk]);
       close(output);
       halt(0);
    end;
 end;

procedure turn(x,y : longint);
 begin
    if (board[x,y] = 'W') then board[x,y]:='B' else board[x,y]:='W';
 end;

procedure get_num;
var
	i,j,x : longint;
 begin
    num:=0;
    x:=s;
    for i:=1 to 4 do
       for j:=1 to 4 do begin
          if (board[i,j] = 'W') then num:=num+x;
          if (x <> 0) then x:=x div 2;
       end;
 end;


procedure change(x : longint);
var
	q1,q2,i,j : longint;
 begin
    for q1:=-1 to 2 do begin
    for q2:=-1 to 2 do begin
       board:=st[x];
       for i:=1 to 3 do
         for j:=1 to 3 do
             if (patt[i,j] = '1') then
                turn(i+q1,j+q2);
       get_num;
       if (b[num] = false) then begin
          inc(yk);
          st[yk]:=board;
          b[num]:=true;
          kol[yk]:=kol[x]+1;
          check;
       end;
    end;
    end;
 end;

begin
   for i:=1 to 4 do begin
      for j:=1 to 4 do
         read(board[i,j]);
      readln;
   end;

   get_num;
   b[num]:=true;
   yk:=1;
   st[1]:=board;
   check;

   for i:=1 to 3 do begin
      for j:=1 to 3 do
         read(patt[i,j]);
      readln;
   end;

   i:=0;
   while (i < yk) do begin
      inc(i);
      change(i);
   end;
   write('Impossible');
   close(output);
end.

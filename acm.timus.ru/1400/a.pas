type
   mass = array [1..100000] of longint;
const
   maxn = 500;
   di : array [1..4] of longint = (-1,1,0,0);
   dj : array [1..4] of longint = (0,0,-1,1);
var
   res : array [0..maxn,0..maxn] of longint;
   a : array [0..maxn,0..maxn] of longint;
   n,m,i,j,x,y,yk,k,sum,min,x1,y1 : longint;
   way,ans,st1,st2,ans1,ans2 : mass;
   b : array [0..maxn,0..maxn] of boolean;
   q : extended;
begin
   read(x,y);
   x1:=x; y1:=y;
   min:=maxlongint;
   fillchar(a,sizeof(a),1);
   for i:=1 to (x div y) do
      for j:=1 to y do
         a[i,j]:=0;

   for i:=1 to (x mod y) do
      a[((x div y)+1),i]:=0;;

   n:=(x div y);
   if x mod y <>0 then inc(n);
   m:=y;

   for x:=1 to n do begin
      for y:=1 to m do begin
      if (a[x,y] = 0) then begin
         i:=0;
         yk:=1;
         st1[yk]:=x; st2[yk]:=y;
         fillchar(b,sizeof(b),false);
         fillchar(way,sizeof(way),0);
         b[x,y]:=true;
         while (i < yk) do begin
            inc(i);
            for k:=1 to 4 do
               if (a[st1[i]+di[k],st2[i]+dj[k]] = 0)
               and(b[st1[i]+di[k],st2[i]+dj[k]] = false) then begin
                  inc(yk);
                  st1[yk]:=st1[i]+di[k];
                  st2[yk]:=st2[i]+dj[k];
                  b[st1[i]+di[k],st2[i]+dj[k]]:=true;
                  way[yk]:=way[i]+1;
               end;
            if (a[st1[i],st2[i]+1] <> 0) then begin
               if (st1[i] = n) then begin
                  if (b[1,1] = false) then begin
                     inc(yk);
                     st1[yk]:=1;
                     st2[yk]:=1;
                     b[1,1]:=true;
                     way[yk]:=way[i]+1;
                  end;
               end else begin
                  if (b[st1[i]+1,1] = false) then begin
                     inc(yk);
                     st1[yk]:=st1[i]+1;
                     st2[yk]:=1;
                     b[st1[i]+1,1]:=true;
                     way[yk]:=way[i]+1;
                  end;
               end;
            end;
            if (a[st1[i],st2[i]-1] <> 0) then begin
               if (a[st1[i]-1,m] = 0) then
                  if (b[st1[i]-1,m] = false) then begin
                     inc(yk);
                     st1[yk]:=st1[i]-1;
                     st2[yk]:=m;
                     b[st1[i]-1,m]:=true;
                     way[yk]:=way[i]+1;
                  end;
               if (st1[i] = 1) and (a[n,m] = 0) then
                  if (b[n,m] = false) then begin
                     inc(yk);
                     st1[yk]:=n;
                     st2[yk]:=m;
                     b[n,m]:=true;
                     way[yk]:=way[i]+1;
                  end;
               if (st1[i] = 1) and (a[n,(x1 mod y1)] = 0) then
                  if (b[n,(x1 mod y1)] = false) then begin
                     inc(yk);
                     st1[yk]:=n;
                     st2[yk]:=x1 mod y1;
                     b[n,(x1 mod y1)]:=true;
                     way[yk]:=way[i]+1;
                  end;
            end;
         end;

         sum:=0;
         for i:=1 to yk do
            sum:=sum+way[i];
         if sum < min then begin
            min:=sum;
            ans:=way;
            ans1:=st1;
            ans2:=st2;
         end;
      end;
      end;
    end;
    q:=min/x1;
    writeln('Mean = ',q:0:2);
    for i:=1 to x1 do
       res[ans1[i],ans2[i]]:=ans[i];
    for i:=1 to n do begin
       for j:=1 to m do begin
          write(res[i,j],' ');
          if (j=(x1 mod y1)) and (i = n) then halt(0);
       end;
       writeln;
    end;
end.
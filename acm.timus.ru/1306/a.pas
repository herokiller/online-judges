const
   maxn = 125005;
var
   heap : array [1..maxn] of longint;
   n,i,x,ndel,heapn : longint;
   y : extended;

procedure heapfy_up(v : longint);
var
        i,c : longint;
 begin
    i:=v;
    while (i > 1) do begin
       if (heap[i] < heap[i div 2]) then begin
          c:=heap[i];
          heap[i]:=heap[i div 2];
          heap[i div 2]:=c;
       end;
       i:=i div 2;
    end;
 end;

procedure heapfy_down(v : longint);
var
        i,c,min,p : longint;
 begin
    i:=v;
    while (i > 0) do begin
       p:=0; min:=heap[i];
       if (i*2 <= heapn) and (heap[i*2] < min) then begin
          min:=heap[i*2];
          p:=i*2;
       end;
       if (i*2+1 <= heapn) and (heap[i*2+1] < min) then begin
          min:=heap[i*2+1];
          p:=i*2+1;
       end;
       if p=0 then break;
       c:=heap[i];
       heap[i]:=min;
       heap[p]:=c;
       i:=p;
    end;
 end;

begin
   {heap[1] - min}
   read(n);
   ndel:=(n-1) div 2;

   for i:=1 to n-ndel do begin
      read(heap[i]);
      heapfy_up(i);
   end;

   heapn:=n-ndel;

   for i:=1 to ndel do begin
      read(x);
      if (x > heap[1]) then begin
         heap[1]:=x;
         heapfy_down(1);
      end else continue;
   end;

   if (n mod 2 =1) then begin
      writeln(heap[1]);
      close(output);
   end else begin
      y:=heap[1];
      if (3<=heapn)and(heap[3]<heap[2]) then y:=y+heap[3] else y:=y+heap[2];
      y:=y/2;
      writeln(y:0:1);
      close(output);
   end;
end.
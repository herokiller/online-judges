{$H+}
const
   maxn = 50002;
   x0 : set of char = ['o','q','z'];
   x1 : set of char = ['i','j'];
   x2 : set of char = ['a','b','c'];
   x3 : set of char = ['d','e','f'];
   x4 : set of char = ['g','h'];
   x5 : set of char = ['k','l'];
   x6 : set of char = ['m','n'];
   x7 : set of char = ['p','r','s'];
   x8 : set of char = ['t','u','v'];
   x9 : set of char = ['w','x','y'];
var
   s : string;
   pr,num,kol : array [0..maxn] of longint;
   b : array [0..maxn] of boolean;
   i,j,k,n,pos,res : longint;
   ok : boolean;
   ans : array [0..maxn] of longint;
   a : array [0..maxn] of string;
begin
   while not eof do begin
      readln(s);
      if (s[1] = '-') then break;
      readln(n);
      for i:=1 to n do
         readln(a[i]);
      fillchar(b,sizeof(b),false);
      for i:=1 to 50000 do
         kol[i]:=maxlongint;
      b[0]:=true;
      kol[0]:=0;
      for i:=1 to length(s) do
         for j:=1 to n do
            if (length(a[j]) <= i) then begin
               ok:=false;
               for k:=length(a[j]) downto 1 do begin
                  if(s[i+k-length(a[j])]='0')and not(a[j][k] in x0)then begin
                     ok:=true;
                     break;
                  end;
                  if(s[i+k-length(a[j])]='1')and not(a[j][k] in x1)then begin
                     ok:=true;
                     break;
                  end;
                  if(s[i+k-length(a[j])]='2')and not(a[j][k] in x2)then begin
                     ok:=true;
                     break;
                  end;
                  if(s[i+k-length(a[j])]='3')and not(a[j][k] in x3)then begin
                     ok:=true;
                     break;
                  end;
                  if(s[i+k-length(a[j])]='4')and not(a[j][k] in x4)then begin
                     ok:=true;
                     break;
                  end;
                  if(s[i+k-length(a[j])]='5')and not(a[j][k] in x5)then begin
                     ok:=true;
                     break;
                  end;
                  if(s[i+k-length(a[j])]='6')and not(a[j][k] in x6)then begin
                     ok:=true;
                     break;
                  end;
                  if(s[i+k-length(a[j])]='7')and not(a[j][k] in x7)then begin
                     ok:=true;
                     break;
                  end;
                  if(s[i+k-length(a[j])]='8')and not(a[j][k] in x8)then begin
                     ok:=true;
                     break;
                  end;
                  if(s[i+k-length(a[j])]='9')and not(a[j][k] in x9)then begin
                     ok:=true;
                     break;
                  end;
               end;
               if (ok = false) then
                  if (b[i-length(a[j])] = true) then begin
                     if (kol[i] > kol[i-length(a[j])]+1) then begin
                       b[i]:=true;
                        pr[i]:=i-length(a[j]);
                        num[i]:=j;
                        kol[i]:=kol[i-length(a[j])]+1;
                     end;
                  end;
            end;

      if (b[length(s)] = true) then begin
         pos:=length(s);
         res:=0;
         while true do begin
            inc(res);
            ans[res]:=num[pos];
            pos:=pr[pos];
            if pos = 0 then break;
          end;
          for i:=res downto 1 do
             write(a[ans[i]],' ');
          writeln;
      end else writeln('No solution.');
   end;
end.
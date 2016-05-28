program Matatabi;
const maxn=300007;

var
   n,i,j:longint;
   h,id,hh:array [1..maxn] of longint;
   ans,s,t:int64;
   fwk,l,r:array [1..maxn] of longint;

procedure qsort(l,r:longint);
var i,j,m,t:longint;
begin
   i:=l; j:=r; m:=h[(l+r) div 2];
   repeat
      while h[i]<m do inc(i);
      while h[j]>m do dec(j);
      if i<=j then begin
         t:=h[i]; h[i]:=h[j]; h[j]:=t;
         t:=id[i]; id[i]:=id[j]; id[j]:=t;
         inc(i); dec(j);
      end;
   until i>j;
   if j>l then qsort(l,j);
   if i<r then qsort(i,r);
end;

procedure fwk_add(pos,val:longint);
begin
   while pos<=maxn do begin
      inc(fwk[pos],val);
      inc(pos,pos and -pos);
   end;
end;
function fwk_rsum(right:longint):longint;
var ans:longint;
begin
   ans:=0;
   while right>0 do begin
      inc(ans,fwk[right]);
      dec(right,right and -right);
   end;
   exit(ans);
end;
function fwk_sum(l,r:longint):longint;
begin
   exit(fwk_rsum(r)-fwk_rsum(l-1));
end;

begin
   assign(input,'matatabi.in'); reset(input);
   assign(output,'matatabi.out'); rewrite(output);

   readln(n);
   for i:=1 to n do readln(h[i]);
   // Discretize h into hh
   for i:=1 to n do id[i]:=i;
   qsort(1,n);
   j:=1;    // Current rank
   for i:=1 to n do begin
      if (i>1) and (h[i]<>h[i-1]) then inc(j);
      hh[id[i]]:=j;
   end;

   // L->R
   fillchar(fwk,sizeof(fwk),0);
   for i:=1 to n do begin
      l[i]:=fwk_sum(hh[i]+1,maxn);
      fwk_add(hh[i],1);
   end;
   // R->L
   fillchar(fwk,sizeof(fwk),0);
   for i:=n downto 1 do begin
      r[i]:=fwk_sum(hh[i]+1,maxn);
      fwk_add(hh[i],1);
   end;
   // Sum up
   ans:=0;
   for i:=1 to n do
      if l[i]<r[i] then inc(ans,l[i])
      else inc(ans,r[i]);

   writeln(ans);
   close(input); close(output);
end.

program Nekojyarashi;
const
    maxn=100006;
    maxm=200006;

var
   n,m,i,u,v:longint;
   t,w:int64;
   // List of edges
   tot_edges:longint;
   dest,next:array [1..maxm] of longint;
   head,size:array [1..maxn] of longint;

procedure add_edge(u,v:longint);
begin
   inc(tot_edges);
   dest[tot_edges]:=v;
   next[tot_edges]:=head[u];
   head[u]:=tot_edges;
   inc(size[u]);
end;

procedure work;
var
   i,j:longint;
   visited:array [1..maxn] of boolean;
   colour_ct:array [0..1] of int64;
   d:array [1..maxn] of longint;
   cc:longint;

   procedure dfs(u,parent,depth:longint);
   var v:longint;
   begin
      //writeln('DFS: ',u,' | Depth=',depth,', Parent=',parent,', CC=',cc);
      visited[u]:=true;
      d[u]:=depth;
      inc(colour_ct[depth mod 2]);
      v:=head[u];
      while v<>-1 do begin
         if dest[v]<>parent then begin
            //writeln('    ',u,' -> ',dest[v]);
            if visited[dest[v]] and ((depth-d[dest[v]]) mod 2=0) then begin
               t:=0;    // Found an odd cycle!
               exit;
            end
            else if not visited[dest[v]] then begin
               dfs(dest[v],u,depth+1);
               if t<>-1 then exit;
            end;
         end;
         v:=next[v];
      end;
   end;

begin
   t:=-1;   // Not decided yet
   // Check if T = 3
   if m=0 then begin
      t:=3;
      w:=n; w:=w*(n-1)*(n-2) div 6;
      exit;
   end;
   // Check if T = 2
   // size[i] <= 1 should hold for all i,
   // i.e. everything should be H2 or He
   // [H]--[H]  (He)  [H]--[H]  [H]--[H]  (He)
   t:=2;
   for i:=1 to n do
      if size[i]>=2 then begin t:=-1; break; end;
   if t=2 then begin
      w:=0;
      for i:=1 to n do
         if size[i]>0 then inc(w);
      w:=(w div 2)*(n-2);
      exit;
   end;
   // Check if T = 0
   fillchar(visited,sizeof(visited),0);
   w:=0;
   cc:=0;
   for i:=1 to n do if not visited[i] then begin
      colour_ct[0]:=0;
      colour_ct[1]:=0;
      inc(cc);
      dfs(i,-1,0);
      if t=0 then begin
         w:=1; exit;
      end else begin
         inc(w,colour_ct[0]*(colour_ct[0]-1) div 2);
         inc(w,colour_ct[1]*(colour_ct[1]-1) div 2);
      end;
   end;
   // Nope. T = 1
   t:=1;
   // And W is already calculated in the loop.
   exit;
end;

begin
{$IFDEF EVAL}
   assign(input,'nekojyarashi.in'); reset(input);
   assign(output,'nekojyarashi.out'); rewrite(output);
{$ENDIF}

   fillchar(head,sizeof(head),-1);
   fillchar(size,sizeof(size),0);
   tot_edges:=0;

   readln(n,m);
   for i:=1 to m do begin
      readln(u,v);
      add_edge(u,v);
      add_edge(v,u);
   end;

   work;
   writeln(t);
   writeln(w);

   close(input); close(output);
end.


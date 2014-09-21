// maxflow algorithm
// V: graph, s:source, e:sink, returns:maximal flow from source to sink
int do_flow(vector<vector<PII> > &V, int s, int e) {
  vector<bool> visit;

  function<int(int,int,int)> try_flow = [&V, &visit, &try_flow](int s, int e, int maxflow) -> int {
    if(s == e) {
      return maxflow;
    }
    if(visit[s]) return 0;
    visit[s] = true;
    for(auto &it : V[s]) {
      if(it.second > 0) {
        int tmp = try_flow(it.first, e, min(maxflow, it.second));
        if(tmp == 0) continue;

        add_edge(s, it.first, -tmp);
        add_edge(it.first, s, tmp);
        return tmp;
      }
    }
    return 0;
  };

  int tot = 0;
  while(true) {
    visit = vector<bool>(size(V), false);
    int tmp = try_flow(s, e, 500000);
    if(tmp == 0) break;
    tot += tmp;
  }
  return tot;
}

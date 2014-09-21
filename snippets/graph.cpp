vector<vector<PII> > V;

void init_graph(int sz) {
  V.clear();
  V.resize(sz);
}

int add_edge(int s, int e, int flow) {
  vector<PII> &vv = V[s];
  for(int i=0;i<size(vv);i++) {
    if(vv[i].first == e) {
      return vv[i].second += flow;
    }
  }
  if(flow != 0) vv.pb(mp(e, flow));
  return flow;
}

int get_edge(int s, int e) { return add_edge(s, e, 0); }

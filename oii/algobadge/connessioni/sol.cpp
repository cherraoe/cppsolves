#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<int> g;
vector<int> gv;
vector<bool> av;
int counter;

void inizia(int n) {
  c.assign(n, {});
  for (int i = 0; i < n; i++) {
    g.push_back(i);
    gv.push_back(1);
  }
  counter = n;
  av.assign(n, true);
}

int collega(int x, int y) {
  c[x].push_back(y);
  c[y].push_back(x);
  
  if (av[x] && av[y]) {
    g[y] = g[x];
    gv[x]++;
    gv[y]--;
    av[x] = 0;
    av[y] = 0;
    counter--;
  } else if (av[x]) {
    g[x] = g[y];
    gv[y]++;
    gv[x]--;
    av[x] = 0;
    counter--;
  } else if (av[y]) {
    g[y] = g[x];
    gv[x]++;
    gv[y]--;
    av[y] = 0;
    counter--;
  } else if (g[x] != g[y]) {
    int rooto;
    int group;
    int low;
    if (gv[x] > gv[y]) {
      rooto = y;
      group = g[y];
      low = g[x];
    } else {
      rooto = x;
      group = g[x];
      low = g[y];
    }
    queue<int> q;
    q.push(rooto);
    g[rooto] = group;
    while (!q.empty()) {
      int root = q.front(); q.pop();
      for (int next : c[root]) {
        if (g[next] != group) {
          g[next] = group;
          gv[low]--;
          gv[group]++;
          q.push(next);
        }
      }
    }
    counter--;
  }
  return counter;
}

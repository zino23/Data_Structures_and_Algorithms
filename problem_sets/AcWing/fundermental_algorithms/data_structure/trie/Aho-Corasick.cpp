#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10, REDIX = 26;
int son[N][REDIX], idx;  // the trie tree and idx of each node
char chara[N];           // the edge which links to the current vertex
bool is_leaf[N];

// for aho-corasick algorithm
int parent[N], suffix_link[N];
int transition[N][REDIX];

int go( int v, char ch );

void insert( string s ) {
  int p = 0;
  for ( int i = 0; i < s.size(); i++ ) {
    int c = s[i] - 'a';
    if ( son[p][c] == 0 ) {
      son[p][c] = ++idx;
      parent[idx] = p;
      chara[idx] = s[i];
    }
    p = son[p][c];
  }
  is_leaf[p] = true;
}

// @true if the queried string is in the trie
bool query( string s ) {
  int p = 0;
  for ( int i = 0; i < s.size(); i++ ) {
    int c = s[i] - 'a';
    if ( son[p][c] == 0 ) {
      return false;
    }
    p = son[p][c];
  }
  return true;
}

// @return the node following suffix link
int get_link( int v ) {
  if ( suffix_link[v] == -1 ) {
    if ( v == 0 || parent[v] == 0 ) {
      // base case: root and its immediate children, link to root
      suffix_link[v] = 0;
    } else {
      // follow parent's suffix link, and transitions according to the current
      // character edge
      suffix_link[v] = go( parent[v], chara[v] );
    }
  }
  return suffix_link[v];
}

//
int go( int v, char ch ) {
  int c = ch - 'a';
  // has not transitioned from state v
  if ( transition[v][c] == -1 ) {
    if ( son[v][c] != 0 ) {
      // the character edge exists, transition to the state, i.e. the next node
      transition[v][c] = son[v][c];
    } else {
      // recursive happens here
      // no available character edge for current node, transitions to another
      // state the transition have two steps
      // 1. follow the parent's suffix link to another node
      // 2. transition from the node with current character edge ch
      transition[v][c] = ( v == 0 ? 0 : go( get_link( v ), ch ) );
    }
  }
  return transition[v][c];
}

void init() {
  memset( suffix_link, -1, sizeof suffix_link );
  memset( transition, -1, sizeof transition );
}

int main() {
  init();
  int n;
  cin >> n;
  string s;
  for ( int i = 0; i < n; i++ ) {
    cin >> s;
    insert( s );
  }
  return 0;
}

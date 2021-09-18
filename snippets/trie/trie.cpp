#include <bits/stdc++.h>

struct Node {
  char data;
  std::unordered_map<char, Node*> m;
  bool is_terminal;
  Node(char data);
};

Node::Node(char data) {
  this->data = data;
  this->is_terminal = false;
}

class Trie {
  Node *root;
  
  public:
  Trie();
  void insert(std::string word);
  bool search(std::string word);
};

Trie::Trie() {
  root = new Node('\0');
}

void Trie::insert(std::string word) {
  Node *temp = this->root;
  for (char c : word) {
    if (temp->m.count(c) == 0) {
      Node *n = new Node(c);
      temp->m[c] = n;
    }
    temp = temp->m[c];
  }
  temp->is_terminal = true;
}

bool Trie::search(std::string word) {
  Node *temp = this->root;
  for (char c : word) {
    if (temp->m.count(c) == 0) {
      return false;
    }
    temp = temp->m[c];
  }
  return temp->is_terminal;
}

int main() {
  std::string words[]{"hello", "he", "apple", "aple", "news"};
  Trie t;
  for (std::string w : words) {
    t.insert(w);
  }

  std::string key; std::cin >> key;

  if (t.search(key)) {
    std::cout << "Key is Present \n";
  } else {
    std::cout << "Key is NOT Present \n";
  }
}

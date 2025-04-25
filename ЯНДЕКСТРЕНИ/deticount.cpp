#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int countDescendants(const std::string& node,
                     const std::map<std::string, std::vector<std::string>>& tree,
                     std::map<std::string, int>& descendantCount) {
    if (tree.find(node) == tree.end()) {
        descendantCount[node] = 0;
        return 1;
    }
    
    int total = 0;
    for (const auto& child : tree.at(node)) {
        total += countDescendants(child, tree, descendantCount);
    }
    descendantCount[node] = total;
    return total + 1;
}

int main() {
    int N;
    std::cin >> N;
    
    std::map<std::string, std::vector<std::string>> tree;
    std::set<std::string> allNodes;
    std::set<std::string> children;
    
    for (int i = 0; i < N - 1; ++i) {
        std::string child, parent;
        std::cin >> child >> parent;
        tree[parent].push_back(child);
        allNodes.insert(child);
        allNodes.insert(parent);
        children.insert(child);
    }
    
    std::string root;
    for (const auto& node : allNodes) {
        if (children.find(node) == children.end()) {
            root = node;
            break;
        }
    }
    
    std::map<std::string, int> descendantCount;
    countDescendants(root, tree, descendantCount);
    
    std::vector<std::string> nodes;
    for (const auto& node : allNodes) {
        nodes.push_back(node);
    }
    
    std::sort(nodes.begin(), nodes.end());
    
    for (const auto& node : nodes) {
        std::cout << node << " " << descendantCount[node] << "\n";
    }
    
    return 0;
}
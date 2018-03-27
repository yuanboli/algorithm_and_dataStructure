#include <iostream>
#include <vector>
#include <set>

using namespace std;
class Node {
public:
    vector<Node*> children;
    Node* parent;
    int index;
    int harvest;

    Node(Node* p, int i): parent(p), index(i), harvest(0){}
    void addChild(Node* child){
        children.push_back(child);
    }

    void clean_harvest(){
        harvest = 0;
    }
} ;
class Tree {
public:
    vector<Node*> nodes; // root is nodes[0]

    Tree(vector<int> &input){
        nodes.push_back(new Node(NULL, 0));
        for(int i = 0; i < input.size(); i++){
            // create nodes
            int parent_index = input[i];
            nodes.push_back(new Node(nodes[parent_index], i+1));

            // construct edges
            int new_node = i + 1;
            nodes[parent_index]->addChild(nodes[new_node]);
        }
    }
    
    set<int>* getNextLayer(set<int>* layer){
        set<int>* nextLayer = new set<int>();
        
        for(set<int>::iterator itr = layer->begin(); itr != layer->end(); itr++)
            for(int i = 0; i < nodes[*itr]->children.size(); i++){
                int index = nodes[*itr]->children[i]->index;
                nextLayer->insert(index);        
            }
        return nextLayer;
    }

    set<int>* get_prev_layer(set<int>* layer){
        set<int>* prevLayer = new set<int>();

        for(set<int>::iterator itr = layer->begin(); itr != layer->end(); itr++){
            if (nodes[*itr]->parent != NULL){
                int index = nodes[*itr]->parent->index;
                prevLayer->insert(index);
            }
        }
        return prevLayer;
    }

    void cleanLayer(set<int>* layer){
        for(set<int>::iterator itr = layer->begin(); itr != layer->end(); itr++){
            nodes[*itr]->harvest = 0;
        }
        return;
    }

    void setLayer(set<int>* layer){
        for(set<int>::iterator itr = layer->begin(); itr != layer->end(); itr++){
            nodes[*itr]->harvest = 1;
        }
        return;
    }

    int harvestLayer(set<int> *layer){
        while(layer->empty() != true){
            set<int>* prevLayer = get_prev_layer(layer);
            cleanLayer(prevLayer);
            
            for(set<int>::iterator itr = layer->begin(); itr != layer->end(); itr++){
                Node* node = nodes[*itr];
                if(node->harvest == 1)
                    if(node->parent != NULL)
                        node->parent->harvest = (node->parent->harvest + 1) % 2;
            }
            layer = prevLayer;
        }
        return nodes[0]->harvest;
    }

    int harvest(){
        set<int> *layer;
        layer = new set<int>();
        layer->insert(0);
        int sum = 0;
        while(layer->empty() != true){
            setLayer(layer);
            sum += harvestLayer(layer);
            layer = getNextLayer(layer);
        }

        return sum;
    }
} ;


int main(){
    int n;
    std::cin >> n;

    vector<int> input;
    for(int i = 1; i < n; i++){
        int tmp;
        std::cin >> tmp;
        tmp -= 1; // now tmp means that the index of the node point the this node
        input.push_back(tmp);
    }

    Tree* tree = new Tree(input);

    int result = tree->harvest();
    cout << result << endl;
    return 0;
}

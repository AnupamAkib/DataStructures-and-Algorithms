#include <bits/stdc++.h>

using namespace std;

class Node{ // A BST node contains a value, left node pointer and right node pointer
public:
	int value;
	Node *right;
	Node *left;
};

class BST{ //Binary Search Tree
private:
	Node* root = nullptr; //initially root is null

	Node* createNode(int key){ //this method is used to create a new BST node
		Node* obj = new Node();
		obj->value = key; //set value by 'key'
		obj->left = nullptr; //right and left node is null as it is a newly created node
		obj->right = nullptr;
		return obj; //return the object
	}

	Node* insert_recursive(Node* node, int key){
		if(node == nullptr){
			//node is null so here will insert.
			return createNode(key); //create a new BST node with insertion key and return it
		}
		if(key < node->value){ //key is smaller so, go left and find the correct place to insert
			node->left = insert_recursive(node->left, key);
		}
		else{ //key is larger so, go right and find the correct place to insert
			node->right = insert_recursive(node->right, key);
		}
		//return the updated node
		return node;
	}

	Node* get_inorderSuccessor(Node* node){ //this method finds the inorder successor of a node
		Node* tmp = node;
		while(tmp->left != nullptr){ //go left until leaf node found
			tmp = tmp->left;
		}
		//leaf node is the node we are looking, return it
		return tmp;
	}

	Node* delete_recursive(Node* node, int key){
		if(node == nullptr){
			cout << key << " not found!" << endl;
			return nullptr; //base case
		}

		if(node->value == key){ //the key we gonna delete is found
			if(node->left != nullptr && node->right != nullptr){ //current node has two child
				//get the inorder successor (min value in right sub-tree)
				Node* min_successor = get_inorderSuccessor(node->right); //we go to right as we are searching minimum value in the right sub-tree
				node->value = min_successor->value; //to delete a node, assign the value of the node by the minimum value in it's right sub-tree (inorder successor)
				node->right = delete_recursive(node->right, min_successor->value); //now traverse the right sub-tree with key=minimum_value and delete the node with minimum value. It will always have 0 child
			}
			else if(node->left != nullptr){ //only one child (left)
				return node->left; //left node will be replaced with current node to delete current node
			}
			else if(node->right != nullptr){ //only one child (right)
				return node->right; //right node will be replaced with current node to delete current node
			}
			else{ //no child, leaf node
				return nullptr; //if we are deleting leaf node, just return a null node.
			}
		}
		else{ //current node doesn't contain the value we are searching
			if(key < node->value){ //traverse left as smaller key required
				node->left = delete_recursive(node->left, key);
			}
			else{ //traverse right as greater key required
				node->right = delete_recursive(node->right, key);
			}
		}
		return node; //return the updated node
	}

	void inorder_recurive(Node* node){ //print the BST by inorder traversal
		if(node==nullptr) return;
		inorder_recurive(node->left);
		cout << node->value << " ";
		inorder_recurive(node->right);
	}


public:
	//driver code for insertion
	void Insert(int key){ //Time Complexity = O(N) (in worst case)
		root = insert_recursive(root, key); //always pass the root as we start traversing from root node
	}

	//driver code for deletion
	void Delete(int key){ //Time Complexity = O(N) (in worst case)
		root = delete_recursive(root, key);
	}

	//driver code for printing tree inorder
	void inorder(){ //Time Complexity = O(N)
		inorder_recurive(root);
		cout << endl;
	}
};


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	BST bst;

	bst.Insert(11);
	bst.Insert(6);
	bst.Insert(19);
	bst.Insert(4);
	bst.Insert(8);
	bst.Insert(17);
	bst.Insert(43);
	bst.Insert(5);
	bst.Insert(10);
	bst.Insert(31);
	bst.Insert(49);

	bst.inorder();

	bst.Delete(11);
	bst.Delete(43);
	bst.Delete(31);
	bst.Delete(4);

	bst.inorder();

	bst.Insert(50);
	bst.Insert(12);

	bst.inorder();

	bst.Delete(100);

	//We can implement TreeSort algorithm using BST. The idea is just insert all the array element in a BST and traverse them in inorder. We know inorder always provide sorted form.
	//Average Time Complexity for a TreeSort is O(NlogN)
	return 0;
}

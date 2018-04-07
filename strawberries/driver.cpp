// prog 5 multiway trees
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

template<class T>
// visual studio didn't like this form of inheritance, but removing <T> works - MRP 10/28/14
class Stack : public stack<T> {
// class Stack : public stack {  // change back to this to run on MS VS?
public:
	T pop() {
		// T tmp = top(); // change back to this to run on MS VS?
        T tmp = queue<T>::top();
		stack<T>::pop();
		return tmp;
	}
};

template<class T>
// same as above.  Aren't templates fun?
class Queue : public queue<T> {
// class Queue : public queue { // change back to this to run on MS VS?
public:
	T dequeue() {
		// T tmp = front(); // change back to this to run on MS VS?
		T tmp = queue<T>::front();
		queue<T>::pop();
		return tmp;
	}
	void enqueue(const T& el) {
		push(el);
	}
};
template<class T> class QuadTree;

template<class T>
class QuadTreeNode {
public:
	QuadTreeNode() {
		// left = right = 0;
        ne = nw = sw = se = 0;
	}
	// QuadTreeNode(const T& e, QuadTreeNode<T> *l = 0, QuadTreeNode<T> *r = 0) {
	// 	el = e; left = l; right = r;
	// }
	QuadTreeNode(
        const T& e,
        QuadTreeNode<T> *quad1 = 0,
        QuadTreeNode<T> *quad2 = 0,
        QuadTreeNode<T> *quad3 = 0,
        QuadTreeNode<T> *quad4 = 0
    ) {
		el = e;
        ne = quad1;
        nw = quad2;
        sw = quad3;
        se = quad4;
	}
	T el;
	// QuadTreeNode<T> *left, *right;
	QuadTreeNode<T> *ne, *nw, *sw, *se;
};

template<class T>
class QuadTree {
public:
	QuadTree() {
		root = 0;
	}
	~QuadTree() {
		clear();
	}
	void clear() {
		clear(root);
		root = 0;
	}
	bool isEmpty() const {
		return root == 0;
	}
	void preorder() {
		preorder(root);
	}
	void inorder() {
		inorder(root);
	}
	void postorder() {
		postorder(root);
	}
	// void insert(const T&);
	void recursiveInsert(const T& el) {
		recursiveInsert(root, el);
	}
	// T* search(const T& el) const {
	// 	return search(root, el);
	// }
	vector<T*> radiusSearch(const T& el, int radius) {
        vector<T*> cities;
		return radiusSearch(root, el, radius, cities);
	}
	T* recursiveNearestSearch(const T& el) const {
		return recursiveNearestSearch(root, el);
	}
	void deleteByCopying(QuadTreeNode<T>*&);
	void findAndDeleteByCopying(const T&);
	void deleteByMerging(QuadTreeNode<T>*&);
	void findAndDeleteByMerging(const T&);
	void iterativePreorder();
	void iterativeInorder();
	void iterativePostorder();
	void breadthFirst();
	void MorrisPreorder();
	void MorrisInorder();
	void MorrisPostorder();
	void balance(T*, int, int);
protected:
	QuadTreeNode<T>* root;
	void clear(QuadTreeNode<T>*);
	void recursiveInsert(QuadTreeNode<T>*&, const T&);
	// T* search(QuadTreeNode<T>*, const T&) const;
	vector<T*> radiusSearch(
        QuadTreeNode<T>*,
        const T&,
        int radius,
        vector<T*> cities
    );// const;
	T* recursiveNearestSearch(QuadTreeNode<T>*, const T&) const;
	void preorder(QuadTreeNode<T>*);
	void inorder(QuadTreeNode<T>*);
	void postorder(QuadTreeNode<T>*);
	virtual void visit(QuadTreeNode<T>* p) {
		cout << p->el;// << ' ';
	}
};

template<class T>
void QuadTree<T>::clear(QuadTreeNode<T> *p) {
	if (p != 0) {
		// clear(p->left);
		// clear(p->right);
        clear(p->ne);
        clear(p->nw);
        clear(p->sw);
        clear(p->se);
		delete p;
	}
}

// template<class T>
// void QuadTree<T>::insert(const T& el) {
// 	QuadTreeNode<T> *p = root, *prev = 0;
// 	while (p != 0) {  // find a place for inserting new node;
// 		prev = p;
// 		if (el < p->el)
// 			p = p->left;
// 		else p = p->right;
// 	}
// 	if (root == 0)    // tree is empty;
// 		root = new QuadTreeNode<T>(el);
// 	else if (el < prev->el)
// 		prev->left = new QuadTreeNode<T>(el);
// 	else prev->right = new QuadTreeNode<T>(el);
// }

// template<class T>
// void QuadTree<T>::recursiveInsert(QuadTreeNode<T>*& p, const T& el) {
// 	if (p == 0)
// 		p = new QuadTreeNode<T>(el);
// 	else if (el < p->el)
//     {
// 		recursiveInsert(p->left, el);
//     }
// 	else recursiveInsert(p->right, el);
// }
template<class T>
void QuadTree<T>::recursiveInsert(QuadTreeNode<T>*& p, const T& el) {
    cout << "Don't forget to implement some comparison functions as the template element's members!\n";
	if (p == 0)
		p = new QuadTreeNode<T>(el);
	else if (el.isNEof(p->el))
    {
		recursiveInsert(p->ne, el);
    }
	else if (el.isNWof(p->el))
    {
		recursiveInsert(p->nw, el);
    }
	else if (el.isSWof(p->el))
    {
		recursiveInsert(p->sw, el);
    }
	else recursiveInsert(p->se, el);
}

// template<class T>
// T* QuadTree<T>::search(QuadTreeNode<T>* p, const T& el) const {
// 	while (p != 0)
// 	if (el == p->el)
// 		return &p->el;
// 	else if (el < p->el)
// 		p = p->left;
// 	else p = p->right;
// 	return 0;
// }

// template<class T>
// T* QuadTree<T>::recursiveSearch(QuadTreeNode<T>* p, const T& el) const {
// 	if (p != 0)
// 	if (el == p->el)
// 		return &p->el;
// 	else if (el < p->el)
// 		return recursiveSearch(p->left, el);
// 	else return recursiveSearch(p->right, el);
// 	else return 0;
// }
template<class T>
vector<T*> QuadTree<T>::radiusSearch(
    QuadTreeNode<T>* p,
    const T& el,
    int radius,
    vector <T*> cities
)// const
{
	if (p != 0)
    {
        // eliminate dead quadrants
            // find distance between cities
            // if radius is exceeded by longitudinal difference
                // if focal city is west of original
                    // don't search any quadrant further west
                    // search ne & se
                // if focal city is east of original
                    // don't search any quadrant furhter east
                    // search  nw & sw
            // if radius is exceeded by latitudinal difference
                // if focal city is north of original
                    // don't search any quadrant further north
                    // search sw & se
                // if focal city is south of original
                    // don't search any quadrant further south
                    // search ne & nw
            // otherwise search ne, nw, se, & sw
    	if (el.distanceFrom(p->el) <= radius)
        {
    		// return &p->el;
            cities.push_back(&p->el);
            // keep searching
        }
    	else if (el < p->el)
    		return radiusSearch(p->left, el);
    	else return radiusSearch(p->right, el);
    }
	else return 0; //root = new QuadTreeNode<T>(el);
}

template<class T>
T* QuadTree<T>::recursiveNearestSearch(QuadTreeNode<T>* p, const T& el) const {
	if (p != 0)
	if (el == p->el)
		return &p->el;
	else if (el < p->el)
		return recursiveNearestSearch(p->left, el);
	else return recursiveNearestSearch(p->right, el);
	else return 0;
}

template<class T>
void QuadTree<T>::inorder(QuadTreeNode<T> *p) {
	if (p != 0) {
		inorder(p->left);
		visit(p);
		inorder(p->right);
	}
}

template<class T>
void QuadTree<T>::preorder(QuadTreeNode<T> *p) {
	if (p != 0) {
		visit(p);
		preorder(p->left);
		preorder(p->right);
	}
}

template<class T>
void QuadTree<T>::postorder(QuadTreeNode<T>* p) {
	if (p != 0) {
		postorder(p->left);
		postorder(p->right);
		visit(p);
	}
}

template<class T>
void QuadTree<T>::deleteByCopying(QuadTreeNode<T>*& node) {
	QuadTreeNode<T> *previous, *tmp = node;
	if (node->right == 0)                  // node has no right child;
		node = node->left;
	else if (node->left == 0 )              // node has no left child;
		node = node->right;
	else {
		tmp = node->left;                  // node has both children;
		previous = node;                  // 1.
		while (tmp->right != 0) {         // 2.
			previous = tmp;
			tmp = tmp->right;
		}
		node->el = tmp->el;               // 3.
		if (previous == node)
			previous->left = tmp->left;
		else previous->right = tmp->left; // 4.
	}
	delete tmp;                            // 5.
}

// findAndDeleteByCopying() searches the tree to locate the node containing
// el. If the node is located, the function DeleteByCopying() is called.

template<class T>
void QuadTree<T>::findAndDeleteByCopying(const T& el) {
	QuadTreeNode<T> *p = root, *prev = 0;
	while (p != 0 && !(p->el == el)) {
		prev = p;
		if (el < p->el)
			p = p->left;
		else p = p->right;
	}
	if (p != 0 && p->el == el)
	if (p == root)
		deleteByCopying(root);
	else if (prev->left == p)
		deleteByCopying(prev->left);
	else deleteByCopying(prev->right);
	else if (root != 0)
		cout << "el " << el << " is not in the tree\n";
	else cout << "the tree is empty\n";
}

template<class T>
void QuadTree<T>::deleteByMerging(QuadTreeNode<T>*& node) {
	QuadTreeNode<T> *tmp = node;
	if (node != 0) {
		if (!node->right)           // node has no right child: its left
			node = node->left;     // child (if any) is attached to its parent;
		else if (node->left == 0)   // node has no left child: its right
			node = node->right;    // child is attached to its parent;
		else {                      // be ready for merging subtrees;
			tmp = node->left;      // 1. move left
			while (tmp->right != 0)// 2. and then right as far as possible;
				tmp = tmp->right;
			tmp->right =           // 3. establish the link between the
				node->right;        //    the rightmost node of the left
			//    subtree and the right subtree;
			tmp = node;            // 4.
			node = node->left;     // 5.
		}
		delete tmp;                 // 6.
	}
}

template<class T>
void QuadTree<T>::findAndDeleteByMerging(const T& el) {
	QuadTreeNode<T> *node = root, *prev = 0;
	while (node != 0) {
		if (node->el == el)
			break;
		prev = node;
		if (el < node->el)
			node = node->left;
		else node = node->right;
	}
	if (node != 0 && node->el == el)
	if (node == root)
		deleteByMerging(root);
	else if (prev->left == node)
		deleteByMerging(prev->left);
	else deleteByMerging(prev->right);
	else if (root != 0)
		cout << "el " << el << " is not in the tree\n";
	else cout << "the tree is empty\n";
}

template<class T>
void QuadTree<T>::iterativePreorder() {
	Stack<QuadTreeNode<T>*> travStack;
	QuadTreeNode<T> *p = root;
	if (p != 0) {
		travStack.push(p);
		while (!travStack.empty()) {
			p = travStack.pop();
			visit(p);
			if (p->right != 0)
				travStack.push(p->right);
			if (p->left != 0)             // left child pushed after right
				travStack.push(p->left); // to be on the top of the stack;
		}
	}
}

template<class T>
void QuadTree<T>::iterativeInorder() {
	Stack<QuadTreeNode<T>*> travStack;
	QuadTreeNode<T> *p = root;
	while (p != 0) {
		while (p != 0) {                 // stack the right child (if any)
			if (p->right)                // and the node itself when going
				travStack.push(p->right); // to the left;
			travStack.push(p);
			p = p->left;
		}
		p = travStack.pop();             // pop a node with no left child
		while (!travStack.empty() && p->right == 0) { // visit it and all nodes
			visit(p);                                 // with no right child;
			p = travStack.pop();
		}
		visit(p);                        // visit also the first node with
		if (!travStack.empty())          // a right child (if any);
			p = travStack.pop();
		else p = 0;
	}
}

template<class T>
void QuadTree<T>::iterativePostorder() {
	Stack<QuadTreeNode<T>*> travStack;
	QuadTreeNode<T>* p = root, *q = root;
	while (p != 0) {
		for (; p->left != 0; p = p->left)
			travStack.push(p);
		while (p->right == 0 || p->right == q) {
			visit(p);
			q = p;
			if (travStack.empty())
				return;
			p = travStack.pop();
		}
		travStack.push(p);
		p = p->right;
	}
}

template<class T>
void QuadTree<T>::breadthFirst() {
	Queue<QuadTreeNode<T>*> queue;
	QuadTreeNode<T> *p = root;
	if (p != 0) {
		queue.enqueue(p);
		while (!queue.empty()) {
			p = queue.dequeue();
			visit(p);
			if (p->left != 0)
				queue.enqueue(p->left);
			if (p->right != 0)
				queue.enqueue(p->right);
		}
	}
}

template<class T>
void QuadTree<T>::MorrisInorder() {
	QuadTreeNode<T> *p = root, *tmp;
	while (p != 0)
	if (p->left == 0) {
		visit(p);
		p = p->right;
	}
	else {
		tmp = p->left;
		while (tmp->right != 0 &&// go to the rightmost node of
			tmp->right != p)  // the left subtree or
			tmp = tmp->right;   // to the temporary parent of p;
		if (tmp->right == 0) {   // if 'true' rightmost node was
			tmp->right = p;     // reached, make it a temporary
			p = p->left;        // parent of the current root,
		}
		else {                   // else a temporary parent has been
			visit(p);           // found; visit node p and then cut
			tmp->right = 0;     // the right pointer of the current
			p = p->right;       // parent, whereby it ceases to be
		}                        // a parent;
	}
}

template<class T>
void QuadTree<T>::MorrisPreorder() {
	QuadTreeNode<T> *p = root, *tmp;
	while (p != 0) {
		if (p->left == 0) {
			visit(p);
			p = p->right;
		}
		else {
			tmp = p->left;
			while (tmp->right != 0 &&// go to the rightmost node of
				tmp->right != p)  // the left subtree or
				tmp = tmp->right;   // to the temporary parent of p;
			if (tmp->right == 0) {   // if 'true' rightmost node was
				visit(p);           // reached, visit the root and
				tmp->right = p;     // make the rightmost node a temporary
				p = p->left;        // parent of the current root,
			}
			else {                   // else a temporary parent has been
				tmp->right = 0;     // found; cut the right pointer of
				p = p->right;       // the current parent, whereby it ceases
			}                        // to be a parent;
		}
	}
}

template<class T>
void QuadTree<T>::MorrisPostorder() {
	QuadTreeNode<T> *p = new QuadTreeNode<T>(), *tmp, *q, *r, *s;
	p->left = root;
	while (p != 0)
	if (p->left == 0)
		p = p->right;
	else {
		tmp = p->left;
		while (tmp->right != 0 &&// go to the rightmost node of
			tmp->right != p)  // the left subtree or
			tmp = tmp->right;   // to the temporary parent of p;
		if (tmp->right == 0) {   // if 'true' rightmost node was
			tmp->right = p;     // reached, make it a temporary
			p = p->left;        // parent of the current root,
		}
		else {             // else a temporary parent has been found;
			// process nodes between p->left (included) and p (excluded)
			// extended to the right in modified tree in reverse order;
			// the first loop descends this chain of nodes and reverses
			// right pointers; the second loop goes back, visits nodes,
			// and reverses right pointers again to restore the pointers
			// to their original setting;
			for (q = p->left, r = q->right, s = r->right;
				r != p; q = r, r = s, s = s->right)
				r->right = q;
			for (s = q->right; q != p->left;
				q->right = r, r = q, q = s, s = s->right)
				visit(q);
			visit(p->left);     // visit node p->left and then cut
			tmp->right = 0;     // the right pointer of the current
			p = p->right;       // parent, whereby it ceases to be
		}                        // a parent;
	}
}

template<class T>
void QuadTree<T>::balance(T data[], int first, int last) {
	if (first <= last) {
		int middle = (first + last) / 2;
		insert(data[middle]);
		balance(data, first, middle - 1);
		balance(data, middle + 1, last);
	}
}

double findDistance()
{
    return 0;
}
void nearestCity()
{
    return 0;
}
void addCity()
{
    return 0;
}

int main()
{
    bool keepGoing = true;
    while (keepGoing)
    {
        cout << "\nChoose an option:\n"
             << "1. Compute the distance between two sets of coordinates.\n"
             << "2. Find the nearest city to a set of coordinates.\n"
             << "3. Add a city to the data set.\n"
             << "4. Quit.\n";
        int response;
        cin >> response;
        cout << "\n";

        switch(response)
        {
            case 1:
                // 1. Compute the distance between two sets of coordinates.
                cout << "Input the first latitude: ";
                cout << "\n...\n";
                break;
            case 2:
                // 2. Find the nearest city to a set of coordinates.
                cout << "Input the latitude: ";
                cout << "Input the longitude: ";
                break;
            case 3:
                // 3. Add a city to the data set.
                // • Otherwise, prompt the user for a city name and its coordinates (lat, lon).
                // • Once you have the city’s information:
                //     o Insert the city into the tree if it is not there already.
                //     o Give the user two options:
                //         § Find  the  nearest  (other)  state  capitol  and  report  its  distance  from  the
                //         given city.
                //         § Find and list the names and distances of all cities within a user-provided
                //         distance r in miles from the given city.
                cout << "Input the name of the city: ";
                break;
            case 4:
                keepGoing = false;
                break;
            default:
                cout << "Please choose 1, 2, 3, or 4.\n\n";
        }
    }

    return 0;
}

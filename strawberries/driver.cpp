// prog 5 multiway trees
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class City
{
public:
	City()
	{
		name = "City";
		lat = lon = 0.0;
	}
	City (string newName, double latitude, double longitude)
	{
		name = newName;
		lat = latitude;
		lon = longitude;
	}
	string getName() const { return name; }
	double getLat()  const { return lat;  }
	double getLon()  const { return lon;  }
	double distanceFrom(City city)
	{
		double pi = 3.1415926535897932384626433832795;
		double r = 3956.0;
		double distance = r * acos(
			sin(lat * pi / 180.0) * sin(city.getLat() * pi / 180.0) +
			cos(lat * pi / 180.0) * cos(city.getLat() * pi / 180.0) *
			cos(abs(city.getLon() * pi / 180.0 - lon * pi / 180.0))
		);
		return distance;
	}
	friend ostream & operator << (ostream& out, City& city)
	{
		out << city.name << endl;
		out << "latitude:  " << city.lat << endl;
		out << "longitude: " << city.lon << endl;
		return out;
	}
private:
	string name;
	double lat;
	double lon;
};

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
		this->push(el);
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
	void breadthFirst();
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
    cout << "check1\n";
	double lat1 = el.getLat();
	cout << "check2\n";
	double lat2 = p->el.getLat();
	cout << "check3\n";
	double lon1 = el.getLon();
	double lon2 = p->el.getLon();
	if (p == 0)
	{
		p = new QuadTreeNode<T>(el);
	}
	// else if (el.isNEof(p->el))
	else if (lat1 >= lat2 && lon1 <= lon2)
    {
		recursiveInsert(p->ne, el);
    }
	// else if (el.isNWof(p->el))
	else if (lat1 >= lat2 && lon1 >= lon2)
    {
		recursiveInsert(p->nw, el);
    }
	// else if (el.isSWof(p->el))
	else if (lat1 <= lat2 && lon1 >= lon2)
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
	cout << "Now seeing if " << p->el.getName() << " is within " << radius
	     << " miles of " << el.getName() << endl;
	if (p != 0)
    {
		double distance = el.distanceFrom(p->el);
		cout << p->el.getName() << " is " << distance << " miles from "
		     << el.getName() << endl;
		if (distance <= radius)
		{
			// return &p->el;
			cities.push_back(&p->el);
		}
		bool NE, NW, SW, SE;
		NE = NW = SW = SE = true;
        // eliminate dead quadrants
        // find distance between cities
		// double lonDiff = abs(p->el.getLon() - el.getLon());
		double lonDiff = p->el.getLon() - el.getLon();
		double latDiff = p->el.getLat() - el.getLat();
		// if radius is exceeded by longitudinal difference
		if (lonDiff > radius)
		{
            // if focal city is west of or even with original
			if (lonDiff >= 0)
			{
				// don't search any quadrant further west
				// search ne & se
				NW = SW = false;
				// cout << "searching NE\n";
				// return radiusSearch(p->ne, el, radius, cities);
				// cout << "searching SE\n";
				// return radiusSearch(p->se, el, radius, cities);
			}
			// if focal city is east of original
			else //if (lonDiff < 0)
			{
				// don't search any quadrant further east
				// search  nw & sw
				NE = SE = false;
				// cout << "searching NW\n";
				// return radiusSearch(p->nw, el, radius, cities);
				// cout << "searching SW\n";
				// return radiusSearch(p->sw, el, radius, cities);
			}
		}
		// if radius is exceeded by latitudinal difference
		if (latDiff > radius)
		{
            // if focal city is north of or even with original
			if (latDiff >= 0)
			{
                // don't search any quadrant further north
                // search sw & se
				NE = NW = false;
				// cout << "searching SW\n";
				// return radiusSearch(p->sw, el, radius, cities);
				// cout << "searching SE\n";
				// return radiusSearch(p->se, el, radius, cities);
			}
            // if focal city is south of original
			else
			{
                // don't search any quadrant further south
                // search ne & nw
				SW = SE = false;
				// cout << "searching NE\n";
				// return radiusSearch(p->ne, el, radius, cities);
				// cout << "searching NW\n";
				// return radiusSearch(p->nw, el, radius, cities);
			}
		}
		// otherwise search ne, nw, se, & sw
		if (NE)
		{
			cout << "searching NE\n";
			return radiusSearch(p->ne, el, radius, cities);
		}
		if (NW)
		{
			cout << "searching NW\n";
			return radiusSearch(p->nw, el, radius, cities);
		}
		if (SW)
		{
			cout << "searching SW\n";
			return radiusSearch(p->sw, el, radius, cities);
		}
		if (SE)
		{
			cout << "searching SE\n";
			return radiusSearch(p->se, el, radius, cities);
		}
    }
	else return cities;
}

// template<class T>
// T* QuadTree<T>::recursiveNearestSearch(QuadTreeNode<T>* p, const T& el) const {
// 	if (p != 0)
// 	if (el == p->el)
// 		return &p->el;
// 	else if (el < p->el)
// 		return recursiveNearestSearch(p->left, el);
// 	else return recursiveNearestSearch(p->right, el);
// 	else return 0;
// }

template<class T>
void QuadTree<T>::breadthFirst() {
	Queue<QuadTreeNode<T>*> queue;
	QuadTreeNode<T> *p = root;
	if (p != 0) {
		queue.enqueue(p);
		while (!queue.empty()) {
			p = queue.dequeue();
			visit(p);
			if (p->ne != 0)
				queue.enqueue(p->ne);
			if (p->nw != 0)
				queue.enqueue(p->nw);
			if (p->sw != 0)
				queue.enqueue(p->sw);
			if (p->se != 0)
				queue.enqueue(p->se);
		}
	}
}

int main()
{
	QuadTree<City> cities;
	// populate tree
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
			{
                // 1. Compute the distance between two sets of coordinates.
				double lat1, lon1, lat2, lon2;
                cout << "Input the first latitude: ";
				cin >> lat1;
                cout << "Input the first longitude: ";
				cin >> lon1;
                cout << "Input the second latitude: ";
				cin >> lat2;
				cout << "Input the second longitude: ";
				cin >> lon2;
				City city1 = City("here",  lat1, lon1);
				City city2 = City("there", lat2, lon2);
				cout << "The distance is " << city1.distanceFrom(city2)
				     << " miles.\n";
			}
                break;
            case 2:
			{
                // 2. Find the nearest city to a set of coordinates.
                cout << "Input the latitude: ";
                cout << "Input the longitude: ";
			}
                break;
            case 3:
			{
                // 3. Add a city to the data set.
                // • Otherwise, prompt the user for a city name and its coordinates (lat, lon).
                // • Once you have the city’s information:
                //     o Insert the city into the tree if it is not there already.
                //     o Give the user two options:
                //         § Find  the  nearest  (other)  state  capitol  and  report  its  distance  from  the
                //         given city.
                //         § Find and list the names and distances of all cities within a user-provided
                //         distance r in miles from the given city.
				string name;
				double lat, lon;
                cout << "Input the name of the city: ";
				cin >> name;
				cout << "Input the latitude: ";
				cin >> lat;
				cout << "Input the longitude: ";
				cin >> lon;
				City city = City(name, lat, lon);
				cities.recursiveInsert(city);
				cities.breadthFirst();
			}
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

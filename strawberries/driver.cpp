// prog 5 multiway trees
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
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
	double distanceFrom(City city) const
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
	bool operator == (const City& city) const
	{
		// return whether they have the same coords
		return (lat == city.getLat() && lon == city.getLon());
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
	bool recursiveInsert(const T& el) {
		return recursiveInsert(root, el);
	}
	// T* search(const T& el) const {
	// 	return search(root, el);
	// }
	vector<T*> radiusSearch(const T& el, int radius) {
        vector<T*> cities;
		return radiusSearch(root, el, radius, cities);
	}
	T* nearestSearch(const T& el, bool exceptHere = false) const {
		return nearestSearch(root, root, el, exceptHere);
	}
	void breadthFirst();
protected:
	QuadTreeNode<T>* root;
	void clear(QuadTreeNode<T>*);
	bool recursiveInsert(QuadTreeNode<T>*& p, const T& el);
	// T* search(QuadTreeNode<T>*, const T&) const;
	vector<T*> radiusSearch(
        QuadTreeNode<T>*,
        const T&,
        int radius,
        vector<T*> cities
    );// const;
	// T* nearestSearch(QuadTreeNode<T>*, const T&, double min = 0) const;
	// T* nearestSearch(QuadTreeNode<T>*, const T& el) const;
	// T* nearestSearch(QuadTreeNode<T>* contender, const T& champ) const;
	T* nearestSearch(
		QuadTreeNode<T>* contender,
		QuadTreeNode<T>* runnerUp,
		const T& champ,
		bool exceptHere
	) const;
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

template<class T>
bool QuadTree<T>::recursiveInsert(QuadTreeNode<T>*& p, const T& el) {
	bool neInsertionResult = false,
	     nwInsertionResult = false,
	     swInsertionResult = false,
	     seInsertionResult = false;
	if (p == 0)
	{
		p = new QuadTreeNode<T>(el);
		// cout << "quack\n";
	}
	else if (p->el == el)
	{
		cout << "\nThat city is already in the data set.\n";
		cout << "Most people call it " << p->el.getName() << ".\n";
		return true;
	}
	else {
		double lat1 = el.getLat();
		double lat2 = p->el.getLat();
		double lon1 = el.getLon();
		double lon2 = p->el.getLon();

		// else if (el.isNEof(p->el))
		if (lat1 >= lat2 && lon1 <= lon2)
	    {
			neInsertionResult = recursiveInsert(p->ne, el);
	    }
		// else if (el.isNWof(p->el))
		else if (lat1 >= lat2 && lon1 >= lon2)
	    {
			nwInsertionResult = recursiveInsert(p->nw, el);
	    }
		// else if (el.isSWof(p->el))
		else if (lat1 <= lat2 && lon1 >= lon2)
	    {
			swInsertionResult = recursiveInsert(p->sw, el);
	    }
		else
			seInsertionResult = recursiveInsert(p->se, el);
	}
	if (
		neInsertionResult == false &&
		nwInsertionResult == false &&
		swInsertionResult == false &&
		seInsertionResult == false
	)
		return false;
	else
		return true;
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

		// a degree of latitude at the equator is 68.703 miles
		double lonDiff = (p->el.getLon() - el.getLon()) * 68.703;
		// a degree of longitude at the equator is 69.172 miles
		double latDiff = (p->el.getLat() - el.getLat()) * 69.172;
		// if radius is exceeded by longitudinal difference
		if (abs(lonDiff) > radius)
		{
			cout << "radius is exceeded by longitudinal difference\n";
            // if focal city is west of or even with original
			if (lonDiff >= 0)
			{
				cout << p->el.getName() << " is not east of " << el.getName() << endl;
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
				cout << p->el.getName() << " is not west of " << el.getName() << endl;
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
		// pickup here: ensure this works. convert lat&lon dists to miles
		if (abs(latDiff) > radius)
		{
			cout << "radius is exceeded by latitudinal difference\n";
            // if focal city is north of or even with original
			if (latDiff >= 0)
			{
				cout << p->el.getName() << " is not south of " << el.getName() << endl;
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
				cout << p->el.getName() << " is not north of " << el.getName() << endl;
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
		if (NE && p->ne != 0)
		{
			cout << "searching NE\n";
			cities = radiusSearch(p->ne, el, radius, cities);
		}
		if (NW && p->nw != 0)
		{
			cout << "searching NW\n";
			cities = radiusSearch(p->nw, el, radius, cities);
		}
		if (SW && p->sw != 0)
		{
			cout << "searching SW\n";
			cities = radiusSearch(p->sw, el, radius, cities);
		}
		if (SE && p->se != 0)
		{
			cout << "searching SE\n";
			cities = radiusSearch(p->se, el, radius, cities);
		}
	}
	return cities;
}

/*
This function recursivley determines the nearest City to a given City.
It takes 3 arguments:
	1. QuadTreeNode<T>* contender, the City that is contending for nearest city.
	   The template class, T, will probably have to be City.
	2. QuadTreeNode<T>* runnerUp, the nearest known city.
	   The template class, T, will probably have to be City.
	3. const T& champ, the City for which we seek the nearest other city.
It returns a pointer of class T, the nearest City.
*/
template<class T>
T* QuadTree<T>::nearestSearch(
	QuadTreeNode<T>* contender,
	QuadTreeNode<T>* runnerUp,
	const T& champ,
	bool exceptHere
) const {
	if (contender != 0)
	{
		double contenderDist = contender->el.distanceFrom(champ);
		double runnerUpDist = runnerUp->el.distanceFrom(champ);

		if (contenderDist < runnerUpDist)
		{
			if ( !(contender->el == champ && exceptHere) )
			{
				runnerUp = contender;
				cout << endl;
			}
		}
		// return nearest town of a search conducted in all directions.
		T* ne = nearestSearch(contender->ne, runnerUp, champ, exceptHere);
		T* nw = nearestSearch(contender->nw, runnerUp, champ, exceptHere);
		T* se = nearestSearch(contender->se, runnerUp, champ, exceptHere);
		T* sw = nearestSearch(contender->sw, runnerUp, champ, exceptHere);

		double neDist = ne->distanceFrom(champ);
		double nwDist = nw->distanceFrom(champ);
		double seDist = se->distanceFrom(champ);
		double swDist = sw->distanceFrom(champ);

		double shortest = std::min({ neDist, nwDist, seDist, swDist });

		if (shortest == neDist)
			return ne;
		else if (shortest == nwDist)
			return nw;
		else if (shortest == seDist)
			return se;
		else // (shortest == swDist)
			return sw;

	}
	else
	{
		return &runnerUp->el;
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
			if (p->nw != 0)
				queue.enqueue(p->nw);
			if (p->ne != 0)
				queue.enqueue(p->ne);
			if (p->sw != 0)
				queue.enqueue(p->sw);
			if (p->se != 0)
				queue.enqueue(p->se);
		}
	}
}

void populateTree(QuadTree<City> &cities)
{
	// read line by line, adding city to tree
	ifstream capitals;
	// capitals.open("capitals.txt");
	capitals.open("otherCapitals.txt");
	string line;
	while (getline(capitals, line))
	{
		stringstream lineStream(line);
		string word, name = "";
		double lat = 0, lon = 0;
		while (lineStream >> word)
		{
			// if the first char of the workd is a letter, it's still the name
			if (isalpha(word[0]))
				if (name == "")
					name = word;
				else
					name += " " + word;
			else
				if (lat == 0)
					lat = stod(word);
				else
					lon = stod(word);
		}
		City city = City(name, lat, lon);
		cities.recursiveInsert(city);
	}
	// cities.breadthFirst();
}

void findDistance()
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

City* findNearest(QuadTree<City> cities, City city)
{
	City defaultArg = City();
	if (city == defaultArg)
	{
		// 2. Find the nearest city to a set of coordinates.
		double lat, lon;
		cout << "Input the latitude: ";
		cin >> lat;
		cout << "Input the longitude: ";
		cin >> lon;
		// *defaultArg = City("name", lat, lon);
		const City beginning = City("name", lat, lon);
		City* nearest = cities.nearestSearch(beginning);
		cout << "The nearest city is " << nearest->getName() << endl;
		return nearest;


		// T* nearestSearch(const T& el) const {
		// 	return nearestSearch(root, el);
		// }

	}
	else
	{
		// find nearest city to city
		bool exceptHere = true;
		City* nearest = cities.nearestSearch(city, exceptHere);
		cout << "The nearest city is " << nearest->getName() << endl;
		return nearest;
	}
}

void findAllWithinR(QuadTree<City> cities, City city)
{
	// cities.radiusSearch(const City &el, int radius)
	cout << "Within what radius, in miles, do you wish to search for cities? ";
	int radius;
	cin >> radius;
	vector<City*> closeCities = cities.radiusSearch(city, radius);
	cout << "These cities are within " << radius << " miles of "
	     << city.getName() << ":\n";
	for (int i = 0; i < closeCities.size(); i++)
		cout << closeCities[i]->getName() << endl;
}

void addCity(QuadTree<City> &cities)
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
	cin.ignore(); // leading whitespace throws off getline()
	getline(cin, name); // in case the city name is multiple words
	cout << "Input the latitude: ";
	cin >> lat;
	cout << "Input the longitude: ";
	cin >> lon;
	City city = City(name, lat, lon);
	bool alreadyInTree = cities.recursiveInsert(city);
	// cities.breadthFirst();
	if (!alreadyInTree)
	{
		bool keepGoing = true;
		while (keepGoing)
		{
			cout << "\nChoose an option:\n";
			cout << "1. Find the nearest state capital to " << name << "\n";
			cout << "2. Find all the capitals within a given radius\n";
			cout << "3. Main menu\n";
			int response;
			cin >> response;
			switch(response)
			{
				case 1: findNearest(cities, city); break;
				case 2: findAllWithinR(cities, city); break;
				case 3: keepGoing = false; break;
				default: cout << "Please choose 1, 2, or 3\n\n";
			}
		}
	}
}

int main()
{
	QuadTree<City> cities;
	populateTree(cities);
	City city = City();
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
            case 1: findDistance(); break;
            case 2: findNearest(cities, city); break;
			// account for 2 decimals fo precision
            case 3: addCity(cities); break;
            case 4: keepGoing = false; break;
            default: cout << "Please choose 1, 2, 3, or 4.\n\n";
        }
    }

    return 0;
}

// TODO: fix bug: malloc: *** error for object 0x7fed22402920: pointer being
// freed was not allocated *** set a breakpoint in malloc_error_break to debug
// Abort trap: 6

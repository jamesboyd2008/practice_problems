# This script prints dogs' parents' names.

from db import parent

def main():
    # Get the dogs' names from another file.
    # dogo = input("Please input the dog's name: ")
    dogs = []
    with open('dognames.txt', 'r') as dogfile:
        for dog in dogfile:
            dogs.append(dog.strip())

    for dog in dogs:
        # Determine the dog's grandparents.
        maternalGrandmother = parent(parent(dog, 'dam'), 'dam')
        maternalGrandfather = parent(parent(dog, 'dam'), 'sire')
        paternalGrandmother = parent(parent(dog, 'sire'), 'dam')
        paternalGrandfather = parent(parent(dog, 'sire'), 'sire')

        # Print the dog's grandparents.
        print("These are %s's grandparents:\n" % dog)
        print("Maternal grandmother: %s" % maternalGrandmother)
        print("Maternal grandfather: %s" % maternalGrandfather)
        print()
        print("Paternal grandmother: %s" % paternalGrandmother)
        print("Paternal grandfather: %s" % paternalGrandfather)
        print()

if __name__ == '__main__':
    main()


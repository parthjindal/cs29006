# In this python file, only the definations for the magic functions and the basic operations
# for the question segments are provided. There may be the need to add new functions or overload
# existing ones as per the question requirements.

class Vector:

    def __init__(self, *args):
        # if arg is an int(dimension)
        if isinstance(args[0], int):
            self._coords = [0]*args[0]
            return
        try:
            self._coords = [x for x in args[0]]
        except TypeError:
            print(args[0], 'is not iterable')

    def __len__(self):
        return len(self._coords)

    def __getitem__(self, j):
        return self._coords[j]

    def __setitem__(self, j, val):
        self._coords[j] = val

    def __add__(self, other):
        return Vector(x+y for x, y in zip(self._coords, other._coords))

    def __eq__(self, other) -> bool:
        # return True if vector has same coordinates as other
        return all(x == y for x, y in zip(self._coords, other._coords))

    def __ne__(self, other):
        # return True if vector differs from other
        return any(x != y for x, y in zip(self._coords, other._coords))

    def __str__(self):
        s = "<"
        for i in self._coords[:-1]:
            s += "{},".format(i)
        s += "{}>".format(self._coords[-1])
        return s

    def __sub__(self, other):
        return Vector(x-y for x, y in zip(self._coords, other._coords))

    def __neg__(self):
        # Soln for Qs. 3
        return Vector(-x for x in self._coords)

    def __rmul__(self, value):
        return (self * value)

    def __mul__(self, other):
        if isinstance(other, int):
            return Vector(x*other for x in self._coords)

        if isinstance(other, Vector):
            return sum(x*y for x, y in zip(self._coords, other._coords))
    #     #Soln for Qs. 4, 5 and 6


def main():
    v1 = Vector(5)
    v2 = Vector (7)
    v3 = Vector([1, 2, 3, 4, 5])
    v4 = Vector(v3)
    print(v1,v2,v3,v4)
    # Add suitable print statements to display the results
    # of the different question segments


if __name__ == '__main__':
    main()

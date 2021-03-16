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
        if len(self) != len(other):
            raise Exception("dim must be same")
        return Vector(x+y for x, y in zip(self._coords, other._coords))

    def __eq__(self, other) -> bool:
        return (self._coords == other._coords)

    def __ne__(self, other):
        return (self._coords != other._coords)

    def __str__(self):
        s = "<"
        for i in self._coords[:-1]:
            s += "{},".format(i)
        s += "{}>".format(self._coords[-1])
        return s

    def __sub__(self, other):
        if len(self) != len(other):
            raise Exception("dim must be same")

        return Vector(x-y for x, y in zip(self._coords, other._coords))

    def __neg__(self):
        return Vector(-x for x in self._coords)

    def __rmul__(self, value):
        return (self * value)

    def __mul__(self, other):
        if isinstance(other, int):
            return Vector(x*other for x in self._coords)

        elif isinstance(other, float):
            return Vector(x*other for x in self._coords)

        elif isinstance(other, Vector):
            if len(self) != len(other):
                raise Exception("dim must be same")
            return sum(x*y for x, y in zip(self._coords, other._coords))

        else:
            raise TypeError("[", type(other).__name__,
                            "] cant be multiplied with a vector.")


def main():
    v1 = Vector(5)
    v2 = Vector(7)
    v3 = Vector([1, 2, 3, 4, 5])
    v4 = Vector(v3)
    v5 = Vector([7, 8, 9, 10, 11])
    print(f"v1: {v1}\nv2: {v2}\nv3: {v3}\nv4: {v4}\nv5: {v5}")

    print(f"v3 + v5: {v3+v5}")
    print(f"v3==v4: {v3 == v4}")
    print(f"v4==v5: {v4 == v5}")
    print(f"v3!=v4: {v3!=v4}")
    print(f"v5 - v4: {v5-v4}")
    print(f"-v4: {-v4}")
    print(f"v3 * v5: {v3*v5}")
    print(f"v3 * v4 * v5: {v3*v4*v5}")
    print(f"v3 * (-5): {v3*(-5)}")
    print(f"(-5) * v3: {(-5)*v3}")


if __name__ == '__main__':
    main()

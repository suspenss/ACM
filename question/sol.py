class Square:
    def __init__(self):
        pass

    @property
    def side(self):
        return self._side

    @side.setter
    def side(self, x: int):
        assert x >= 0, "invalid"
        self._side = x

    @side.deleter
    def side(self):
        self._side = 0

    @property
    def area(self):
        return self._side ** 2

a: Square = Square()
a.side = 2
print(a.area)

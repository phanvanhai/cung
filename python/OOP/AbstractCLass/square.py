from polygon import Polygon


class Rectangle(Polygon):
    def __init__(self, side1, side2):
        self.side1 = side1
        self.side2 = side2

    def draw(self):
        print("Rectangle with width and height")

    def getAria(self):
        return self.side1 * self.side2

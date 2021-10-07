from polygon import Polygon


class Rectangle(Polygon):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def draw(self):
        print("Rectangle with width and height")

    def getAria(self, item1, item2):
        self.width = item1
        self.height = item2
        return self.width * self.height

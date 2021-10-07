from polygon import Polygon


class Hinh:
    # test: Polygon

    def __init__(self, demo: Polygon):
        self.test = demo

    def handler(self):
        item1 = 100
        item2 = 200
        self.test.getAria(item1, item2)


hinh1 = Polygon()
hinhmh = Hinh(hinh1)
print(hinhmh.handler())

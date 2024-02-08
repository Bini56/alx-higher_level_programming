#!/usr/bin/python3
"""
class rectangle
"""


from models.base import Base


class Rectangle(Base):
    """this represents a rectangle and inherits som attrs from base"""

    def __init__(self, width, height, x=0, y=0, id=None):
        """test"""
        self.width = width
        self.height = height
        self.x = x
        self.y = y
        super().__init__(id)

    @property
    def width(self):
        """width getter"""
        return self.__width
     @width.setter
    def width(self, value):
        """width setter"""
        if type(value) is not int:
            raise TypeError("width must be an integer")
        if value <= 0:
            raise ValueError("width must be > 0")
        self.__width = value


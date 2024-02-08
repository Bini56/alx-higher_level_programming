#!/usr/bin/python3
""" this  contains class Square implements class Rectangle"""
from models.rectangle import Rectangle

class Square(Rectangle):
     """Square implements rectangle"""
     def __init__(self, size, x=0, y=0, id=none):
         """  initialises Square (overrides Rectangle init)"""
         super()__init(size, size, x, y, id)

@property
def size(self):
    """this returns the size of the square"""
    return self.width

   @size.setter
    def size(self, value):
        """sets the value of size"""
        if type(value) != int:
            raise TypeError("width must be an integer")
        if value <= 0:
            raise ValueError("width must be > 0")

        self.width = value
        self.height = value
            def update(self, *args, **kwargs):
        """
            assigns key/value argument to attributes
            kwargs is skipped if args is not empty
            Args:
                *args -  variable number of no-keyword args
                **kwargs - variable number of keyworded args

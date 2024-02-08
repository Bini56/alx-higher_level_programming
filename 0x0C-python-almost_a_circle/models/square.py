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
def size (self, value):
    """set the value of the setter"""

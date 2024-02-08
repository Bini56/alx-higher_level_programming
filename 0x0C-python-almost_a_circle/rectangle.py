#!/usr/bin/python3

""" this is rectangle class inhereted from base class"""

from models.base import Base

class rectangle(Base):
      """this Represents a rectangle and inherits som attrs from base"""

    def __init__(self, width, height, x=0, y=0, id=None):
        """test"""
        self.width = width
        self.height = height
        self.x = x
        self.y = y
        super().__init__(id)
     

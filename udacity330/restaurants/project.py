#!/usr/bin/python27

from flask import Flask

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

from database_setup import Base, Restaurant, MenuItem

import cgi
import sys
import re

# handler ...
app = Flask(__name__)

@app.route('/')
@app.route('/hello')
def Restaurants():
  session = connectDb()
  restaurants = session.query(Restaurant).order_by('name')

  output = ""
  output += "<A HREF=new>Create New Restaurant</A><P>"
  for restaurant in restaurants:
    output += "%s<BR>" % ( restaurant.name )
    output += "<A HREF=%s/edit>Edit</A> * " % restaurant.id
    output += "<A HREF=%s/delete>Delete</A>" % restaurant.id
    output += "<P>"
  return output

@app.route('/menu/<int:restaurant_id>/')
def Menu(restaurant_id):
  session = connectDb()
  menuItems = session.query(MenuItem).filter_by(restaurant_id = restaurant_id ).order_by('name')
  output = "%d" % restaurant_id
  for menuItem in menuItems:
    output += "<li>%s: %s, %d<BR>" % ( menuItem.name, menuItem.price, menuItem.restaurant_id )
  return output


def connectDb():
  engine = create_engine( 'sqlite:///restaurantmenu.db' )
  Base.metadata.bind = engine
  DBSession = sessionmaker(bind = engine)
  session = DBSession()
  return session


if __name__ == '__main__':
  app.debug = True
  app.run(host = '0.0.0.0', port = 8000)


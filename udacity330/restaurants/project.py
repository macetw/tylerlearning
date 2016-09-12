#!/usr/bin/python27

from flask import Flask, render_template

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
  restaurant = session.query(Restaurant).filter_by(id = restaurant_id).one()
  menuItems = session.query(MenuItem).filter_by(restaurant_id = restaurant_id ).order_by('name')
  return render_template('menu.html', restaurant=restaurant, items = menuItems)

@app.route('/menu/newitem/<int:restaurant_id>/')
def NewMenuItem(restaurant_id):
  return "page to create a new menu item, Task 1 complete!"

@app.route('/menu/edititem/<int:restaurant_id>/<int:menu_id>')
def EditMenuItem(restaurant_id, menu_id):
  return "page to edit a new item, Task 2 complete!"

@app.route('/menu/deleteitem/<int:restaurant_id>/<int:menu_id>')
def DeleteMenuItem(restaurant_id, menu_id):
  return "page to delete a menu item, Task 3 complete!"




def connectDb():
  engine = create_engine( 'sqlite:///restaurantmenu.db' )
  Base.metadata.bind = engine
  DBSession = sessionmaker(bind = engine)
  session = DBSession()
  return session


if __name__ == '__main__':
  app.debug = True
  app.run(host = '0.0.0.0', port = 8000)


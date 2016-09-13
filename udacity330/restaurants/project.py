#!/usr/bin/python27

from flask import Flask, render_template, request, redirect, url_for, flash, jsonify

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

from database_setup import Base, Restaurant, MenuItem

import cgi
import sys
import re

# handler ...
app = Flask(__name__)

@app.route('/')
def Restaurants():
  session = connectDb()
  restaurants = session.query(Restaurant).order_by('name')

  output = ""
  # output += "<A HREF=new>Create New Restaurant</A><P>"
  for restaurant in restaurants:
    url = url_for('Menu', restaurant_id = restaurant.id)
    output += "<A HREF=%s>%s</A><BR>" % ( url, restaurant.name )
    # output += "<A HREF=%s/edit>Edit</A> * " % restaurant.id
    # output += "<A HREF=%s/delete>Delete</A>" % restaurant.id
    output += "<P>"
  return output

@app.route('/menu/<int:restaurant_id>/')
def Menu(restaurant_id):
  session = connectDb()
  restaurant = session.query(Restaurant).filter_by(id = restaurant_id).one()
  menuItems = session.query(MenuItem).filter_by(restaurant_id = restaurant_id ).order_by('name')
  return render_template('menu.html', restaurant=restaurant, items = menuItems)

@app.route('/menu/newitem/<int:restaurant_id>/', methods=['GET','POST'])
def NewMenuItem(restaurant_id):
## This function removes a menu item. A GET request gives a blank form
  session = connectDb()
  if request.method == 'POST':
    restaurant = session.query(Restaurant).filter_by(id = restaurant_id).one()
    newItem = MenuItem(name=request.form['name'],restaurant_id = restaurant_id)
    newItem.description = request.form['description']
    newItem.price       = request.form['price']
    newItem.course      = request.form['course']
    session.add(newItem)
    session.commit()
    flash("%s created to %s." % ( newItem.name, restaurant.name ))
    return redirect(url_for('Menu', restaurant_id = restaurant_id))
  else:
    return render_template('menuitem-new.html', restaurant_id=restaurant_id )

@app.route('/menu/edititem/<int:restaurant_id>/<int:menu_id>', methods=['GET','POST'])
def EditMenuItem(restaurant_id, menu_id):
  session = connectDb()
  if request.method == 'POST':
    editItem = session.query(MenuItem).filter_by( restaurant_id = restaurant_id).filter_by( id = menu_id ).one()
    editItem.description = request.form['description']
    editItem.price       = request.form['price']
    editItem.course      = request.form['course']
    session.add(editItem)
    session.commit()
    flash("%s edited." % ( editItem.name ))
    return redirect(url_for('Menu', restaurant_id = restaurant_id))
  else:
    editItem = session.query(MenuItem).filter_by( restaurant_id = restaurant_id).filter_by( id = menu_id ).one()
    restaurant = session.query(Restaurant).filter_by(id = restaurant_id).one()
    return render_template('menuitem-edit.html', restaurant=restaurant, editItem = editItem )


@app.route('/menu/deleteitem/<int:restaurant_id>/<int:menu_id>', methods=['GET','POST'])
def DeleteMenuItem(restaurant_id, menu_id):
## This function removes a menu item. A GET request prompts for confirmation
  session = connectDb()
  if request.method == 'POST':
    deleteItem = session.query(MenuItem).filter_by(restaurant_id = restaurant_id).filter_by(id = menu_id ).one()
    session.delete(deleteItem)
    session.commit()
    flash("%s deleted." % ( deleteItem.name ))
    return redirect(url_for('Menu', restaurant_id = restaurant_id))
  else:
    deleteItem = session.query(MenuItem).filter_by( restaurant_id = restaurant_id).filter_by( id = menu_id ).one()
    restaurant = session.query(Restaurant).filter_by(id = restaurant_id).one()
    return render_template('menuitem-delete.html', restaurant=restaurant, deleteItem = deleteItem )

@app.route('/menu/rest/<int:restaurant_id>')
def Rest(restaurant_id):
## This function provides the REST api for us.
  session = connectDb()
  restaurant = session.query(Restaurant).filter_by(id = restaurant_id).one()
  items = session.query(MenuItem).filter_by(restaurant_id = restaurant_id)
  return jsonify(MenuItems=[i.serialize for i in items])

@app.route('/menu/rest/<int:restaurant_id>/<int:menu_id>')
def RestItem(restaurant_id, menu_id):
## This function provides the REST api for us on a single item.
  session = connectDb()
  restaurant = session.query(Restaurant).filter_by(id = restaurant_id).one()
  item = session.query(MenuItem).filter_by(restaurant_id = restaurant_id).filter_by(id = menu_id).one()
  return jsonify(MenuItem=item.serialize)

def connectDb():
## This little function does the work to connect to the database.
  engine = create_engine( 'sqlite:///restaurantmenu.db' )
  Base.metadata.bind = engine
  DBSession = sessionmaker(bind = engine)
  session = DBSession()
  return session


if __name__ == '__main__':
  app.debug = True
  app.secret_key = 'super_secret_key'
  app.run(host = '0.0.0.0', port = 8000)
  # To use port 80, I did the following:
  #   sudo iptables -t nat -A PREROUTING -p tcp --dport 80 -j REDIRECT --to-port 8000


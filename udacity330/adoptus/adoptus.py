#!/usr/bin/python27

from flask import Flask, render_template, request, redirect, url_for, flash, jsonify

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

from database_setup import Base, Child, Photo, engine

import cgi
import sys
import re

# handler ...
app = Flask(__name__)



@app.route('/')
def Welcome():
  output = "<A HREF=boys>Boys</A><BR><A HREF=girls>Girls</A>"
  return output

@app.route('/boys')
def Boys():
  session = connectDb()
  boys = session.query(Child).filter_by(gender="m").order_by('firstName')
    # customer: consider, order by listing date, age in system
  return ListAllChildren( boys )

# @app.route('/girls')
# def Boys():
  # session = connectDb()
  # boys = session.query(Child).filter_by(gender="f").order_by('firstName')
    # TODO: customer: consider, order by listing date, age in system
  # return ListAllChildren( boys )

def ListAllChildren(children):
  # TODO:if (not logged in as admin):
  # children = children.filter_by(!unlisted)
  # TODO: remove children that are too old. Or automatically "unlist"
  #   children whose age is too much.
  output = ""
  for child in children:
    output += "%s<BR>" % ( child.name )
    #if logged in as admin:
    # output += "<A HREF=%s/edit>Edit</A> * " % restaurant.id
    # output += "<A HREF=%s/unlist>Unlist</A> * " % restaurant.id
    # output += "<A HREF=%s/delete>AddPictures</A>" % restaurant.id
    output += "<P>"
  return output

def connectDb():
## This little function does the work to connect to the database.
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


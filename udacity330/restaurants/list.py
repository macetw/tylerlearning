#!/usr/bin/python26

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from database_setup import Base, Restaurant, MenuItem

from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
import cgi
import sys
import re

# handler ...
class webserverHandler(BaseHTTPRequestHandler):
  def connectDb(self):
    engine = create_engine( 'sqlite:///restaurantmenu.db' )
    Base.metadata.bind = engine
    DBSession = sessionmaker(bind = engine)
    session = DBSession()
    return session

  def do_GET(self):
    try:
      session = self.connectDb()

      self.send_response(200);
      self.send_header('Content-type', 'text/html');
      self.end_headers()
      output = ""

      if self.path.endswith("new"):
        output += "<form method='POST' enctype='multipart/form-data' action='new'><h2>What the new name of it?</h2><input name='name' type='text'><input type='submit' value='Create'></form>"

      elif self.path.endswith("restaurants"):
        restaurants = session.query(Restaurant).order_by('name')

        output += "<A HREF=new>Create New Restaurant</A><P>"
        for restaurant in restaurants:
          output += "%s<BR>" % ( restaurant.name )
          output += "<A HREF=%s/edit>Edit</A> * " % restaurant.id
          output += "<A HREF=delete?id=%s>Delete</A>" % restaurant.id
          output += "<P>"

      elif self.path.endswith("edit"):
        idnum = re.match(r".*/(\d+)/edit", self.path).group(1)
        newNameRestaurant = session.query(Restaurant).filter_by(id=idnum).first()
        output += "<form method='POST' enctype='multipart/form-data' action='edit'><h2>What is the new name of it?</h2><input name='name' type='text' value='%s'><input type='submit' value='Edit'></form>" % (newNameRestaurant.name)

      else:
        self.send_error(404, "Command not found %s" % self.path)

      self.wfile.write("<html><body>%s</body><html>" % output)
      print(output)
      return

    except:
      self.send_error(404, "Some exception happened during GET: %s" % sys.exc_info()[0] )

  def do_POST(self):
    try:
      session = self.connectDb()

      output = ""
      pass
      if self.path.endswith("new"):
        ctype, pdict = cgi.parse_header(self.headers.getheader('content-type'))
        if ctype == 'multipart/form-data':
          fields=cgi.parse_multipart(self.rfile,pdict)
          namecontent = fields.get('name')

        newRestaurant = Restaurant(name = namecontent[0])
        session.add(newRestaurant)
        session.commit()

        self.send_response(301)
        self.send_header('Location', 'restaurants')
        self.send_header('Content-type', 'text/html');
        self.end_headers()

      elif self.path.endswith("edit"):
        ctype, pdict = cgi.parse_header(self.headers.getheader('content-type'))
        if ctype == 'multipart/form-data':
          fields=cgi.parse_multipart(self.rfile,pdict)
          namecontent = fields.get('name')

        idnum = re.match(r".*/(\d+)/edit", self.path).group(1)
        newNameRestaurant = session.query(Restaurant).filter_by(id=idnum).first()
        newNameRestaurant.name = namecontent[0]
        session.add(newNameRestaurant)
        session.commit()

        self.send_response(301)
        self.send_header('Location', '../restaurants')
        self.send_header('Content-type', 'text/html');
        self.end_headers()

      else:
        output += "unknown command. :("
        self.wfile.write(output)

      print output

    except:
      self.send_error(404, "Some exception happened during POST: %s" % sys.exc_info()[0] )


#main ...


def main():
  try:
    port = 8000
    server = HTTPServer(('',port), webserverHandler)
    print "Web Server running on port %s" % port
    server.serve_forever()

  except KeyboardInterrupt:
    print "^C entered, stopping web server..."
    server.socket.close()


if __name__ == '__main__':
   main()

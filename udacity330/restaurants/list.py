#!/usr/bin/python26

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from database_setup import Base, Restaurant, MenuItem

from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
import cgi

# handler ...
class webserverHandler(BaseHTTPRequestHandler):
  def do_GET(self):
    try:
      engine = create_engine( 'sqlite:///restaurantmenu.db' )
      Base.metadata.bind = engine
      DBSession = sessionmaker(bind = engine)
      session = DBSession()

      restaurants = session.query(Restaurant).order_by('name')

      self.send_response(200);
      self.send_header('Content-type', 'text/html');
      self.end_headers()
      output = ""
      for restaurant in restaurants:
         output += "%s<BR>" % ( restaurant.name )
         output += "<A HREF=edit?id=%s>Edit</A> * " % restaurant.id
         output += "<A HREF=delete?id=%s>Delete</A>" % restaurant.id
         output += "<P>"

      self.wfile.write("<html><body>%s</body><html>" % output)
      print(output)
      return

    except:
      self.send_error(404, "File not found %s" % self.path)

  def do_POST(self):
    try:
      self.send_response(301)
      self.send_header('Content-type', 'text/html');
      self.end_headers()

      ctype, pdict = cgi.parse_header(self.headers.getheader('content-type'))
      if ctype == 'multipart/form-data':
        fields=cgi.parse_multipart(self.rfile,pdict)
        idcontent = fields.get('id')

      output = ""
      output += "<html><body>"
      output += "<h1> ID: %s </h1>" % idcontent[0]
 
      output += "<form method='POST' enctype='multipart/form-data' action='hello'><h2>What would you like me to say?</h2><input name='message' type='text'><input type='submit' value='Submit'></form>"
      output += "</html><body>"

      self.wfile.write(output)
      print output

    except:
      pass


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

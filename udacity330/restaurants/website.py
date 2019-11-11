#!/usr/bin/python26

from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
import cgi

# handler ...
class webserverHandler(BaseHTTPRequestHandler):
  def do_GET(self):
    try:
      self.send_response(200);
      self.send_header('Content-type', 'text/html');
      self.end_headers()
      output = ""
      defaultLink = "hello"

      if self.path.endswith("hello"):
        output += "Hello."
        defaultLink = "hola"

      if self.path.endswith("hola"):
        output += "&#161Hola!"

      output += "<form method='POST' enctype='multipart/form-data' action='hello'><h2>What would you like me to say?</h2><input name='message' type='text'><input type='submit' value='Submit'></form>"

      self.wfile.write("<html><body>%s <A HREF=%s>link</A></body><html>" % (output, defaultLink))
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
        messagecontent = fields.get('message')

      output = ""
      output += "<html><body>"
      output += "<h2>Okay, how about this?</h2>"
      output += "<h1> %s </h1>" % messagecontent[0]
 
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

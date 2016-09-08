from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer

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

      self.wfile.write("<html><body>%s <A HREF=%s>link</A></body><html>" % (output, defaultLink))
      print(output)
      return

    except:
      self.send_error(404, "File not found %s" % self.path)


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

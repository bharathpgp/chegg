from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
import SocketServer
import urlparse


class webServer(BaseHTTPRequestHandler):
    def setHeaders(self, response_code=200):
        self.send_response(response_code)
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_GET(self):
        name = urlparse.parse_qs(urlparse.urlparse(
            self.path).query).get('name', None)

        try:
            if "chung" in name:
                self.setHeaders()
                self.wfile.write(
                    "<html><body><h2>Name: Goopeel Chung<br>Title: Associate Professor<br>Phone: (413) 572-714<br>Room: Wilson 325C</h2></body></html>")
            else:
                self.setHeaders(404)
                self.wfile.write(
                    '<html><body><h2>HTTP "404 Not Found"</h2></body></html>')

        except TypeError:
            self.setHeaders(404)
            self.wfile.write(
                '<html><body><h2>HTTP "404 Not Found"</h2></body></html>')

    def do_HEAD(self):
        self.setHeaders()

    def do_POST(self):
        self.setHeaders()


def start(server_class=HTTPServer, class_handler=webServer, port=8080):
    web_server_address = ('', port)
    simple_server = server_class(web_server_address, class_handler)
    print('Web server started...')
    simple_server.serve_forever()


if __name__ == "__main__":
    start()
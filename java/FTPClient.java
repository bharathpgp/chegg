import java.io.*;
import java.net.*;

class FTPClient {
    public static void main(String[] args) throws Exception {

        String ipAddress, data;
        int portNumber;
        Socket clientSocket;
        BufferedReader inFromServer;

        if (args.length != 2) {
            System.out.println("java number of server>");
            System.exit(1);
        }

        ipAddress = args[0];
        portNumber = Integer.parseInt(args[1]);
        clientSocket = new Socket(ipAddress, portNumber);

        inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

        while (null != (data = inFromServer.readLine())) {

            if (data.equals("ZZZZ"))
                break;
            else
                System.out.println(data);
        }
        clientSocket.close();
    }
}

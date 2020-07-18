import java.io.*;
import java.net.*;
import java.util.Scanner;

class FTPServer {
    public static void main(String[] args) throws Exception {

        int portNumber;
        String clientSentence, data;
        ServerSocket welcomeSocket;
        Socket connectionSocket;
        BufferedReader inFromClient;
        DataOutputStream outToClient;
        Scanner sc;

        if (args.length != 1) {
            System.out.println("java ");
            System.exit(1);
        }

        portNumber = Integer.parseInt(args[0]);
        welcomeSocket = new ServerSocket(portNumber);

        while (true) {

            connectionSocket = welcomeSocket.accept();
            sc = new Scanner(System.in);
            outToClient = new DataOutputStream(connectionSocket.getOutputStream());

            while (sc.hasNext()) {
                data = sc.nextLine() + '\n';
                outToClient.writeBytes(data);
            }

            outToClient.writeBytes("ZZZZ" + '\n');
            sc.close();

            inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
            clientSentence = inFromClient.readLine();

            if (null == clientSentence)
                break;
        }
        welcomeSocket.close();
    }
}

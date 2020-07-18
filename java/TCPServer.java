import java.io.*;
import java.net.*;

class TCPServer {

    public static void main(String[] args) throws Exception {

        int portNumber;
        String clientSentence;
        String capitalizedSentence;
        ServerSocket welcomeSocket;
        Socket connectionSocket;
        BufferedReader inFromClient;
        DataOutputStream outToClient;

        if (args.length != 1) {
            System.out.println("java ");
            System.exit(1);
        }

        portNumber = Integer.parseInt(args[0]);

        welcomeSocket = new ServerSocket(portNumber);

        while (true) {
            connectionSocket = welcomeSocket.accept();

            inFromClient = new BufferedReader(

                    new InputStreamReader(

                            connectionSocket.getInputStream()));

            outToClient = new DataOutputStream(

                    connectionSocket.getOutputStream());

            clientSentence = inFromClient.readLine();

            System.out.println();

            System.out.println("RECEIVED FROM CLIENT: " + clientSentence);

            System.out.println();

            capitalizedSentence = clientSentence.toUpperCase() + '\n';

            outToClient.writeBytes(capitalizedSentence);

            System.out.println("SENT TO CLIENT: " + capitalizedSentence);

            if (clientSentence.equals("SHUTDOWN"))
                break;
        }
    }
}

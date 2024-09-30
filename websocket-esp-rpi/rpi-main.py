import socket

HOST = '0.0.0.0'
PORT = 8081

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.bind((HOST, PORT))
        server_socket.listen()
        print('Listening for connections...')

        while True:
            client_socket, client_address = server_socket.accept()
            with client_socket:
                print(f'Connection from {client_address}')
                message = client_socket.recv(1024).decode('utf-8')
                if message == "New device 1001 Joined":
                    print("New device 1001 Joined")
                elif message == "Device 1001 exited from the network":
                    print("Device 1001 exited from the network")
                elif message == "777":
                    print("Data received: 777")

if __name__ == "__main__":
    main()
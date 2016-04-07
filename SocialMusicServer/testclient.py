import socket


def main():

	input("Enter to start")

	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

	try:

		s.connect(('localhost', 7778))

	except ConnectionRefusedError as e:

		print("ConnectionRefusedError")
		s.close()

		return

	input("Enter to send")

	msg = bytes("Client hello\n", "UTF-8")

	s.send(msg)

	while True:
		r = s.recv(5)
		print(r)
		break

	s.shutdown(socket.SHUT_RDWR)

	s.close()


if __name__ == '__main__':
	main()

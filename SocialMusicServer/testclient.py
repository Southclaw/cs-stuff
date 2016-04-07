import socket
import struct


def main():

	input("Enter to start")

	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

	try:

		s.connect(('localhost', 7778))

	except ConnectionRefusedError as e:

		print("ConnectionRefusedError")
		s.close()

		return

	while True:
		msg = input("Enter to send:\n")

		if msg == "":
			break

		if not msg.endswith("\n"):
			msg = msg + "\n"

		print("Sending:\n'%s'\n"%(msg))

		s.send(bytes(msg, "UTF-8"))

		print("waiting for response...\n")

		size = ord(bytes(s.recv(1)))

		print("Receiving", size)

		response = s.recv(size + 1)
		
		print(str(response, "UTF-8"))

	s.shutdown(socket.SHUT_RDWR)

	s.close()


if __name__ == '__main__':
	main()

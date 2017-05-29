// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Networking.h"
#include "UDPListener.h"


uint8* UUDPListener::UDPConnect(void){
	uint8 *ReceivedData;
	uint32 Size;
	int32 bytesRead;

	FSocket *Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), true);
	FString address = TEXT("127.0.0.1");
	int32 port = 3333;
	FIPv4Address ip;
	FIPv4Address::Parse(address, ip);

	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(port);
	bool receiced = Socket->RecvFrom(ReceivedData, 1024, bytesRead, *addr);
	return ReceivedData;
}

FString UUDPListener::UDPReceive(uint8* data){
	
}







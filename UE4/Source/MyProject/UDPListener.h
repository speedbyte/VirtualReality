// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UDPListener.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UUDPListener : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:
	static uint8* UDPConnect(void);
	static FString UDPReceive(uint8* dataString );

};
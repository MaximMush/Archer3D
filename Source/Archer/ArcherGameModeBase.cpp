// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArcherGameModeBase.h"
#include "Player/ArcherBaseCharacter.h"
#include "Player/ArcherPlayerController.h"

 AArcherGameModeBase ::  AArcherGameModeBase()
 {
	DefaultPawnClass = AArcherBaseCharacter :: StaticClass();
	PlayerControllerClass = AArcherPlayerController :: StaticClass();
 }
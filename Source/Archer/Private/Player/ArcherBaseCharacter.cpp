// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ArcherBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

AArcherBaseCharacter::AArcherBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(GetRootComponent());
}

void AArcherBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AArcherBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AArcherBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AArcherBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AArcherBaseCharacter::MoveRight);
}

void AArcherBaseCharacter::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount);
}

void AArcherBaseCharacter::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}



// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ArcherBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BaseWeaponComponent.h"


AArcherBaseCharacter::AArcherBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	WeaponComponent = CreateDefaultSubobject<UBaseWeaponComponent>("WeaponComponent");

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

	check(PlayerInputComponent);
	check(WeaponComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AArcherBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AArcherBaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AArcherBaseCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnAround", this, &AArcherBaseCharacter::AddControllerYawInput);
	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AArcherBaseCharacter::Jump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, WeaponComponent, &UBaseWeaponComponent::Fire);
}

void AArcherBaseCharacter::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount);
}

void AArcherBaseCharacter::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}



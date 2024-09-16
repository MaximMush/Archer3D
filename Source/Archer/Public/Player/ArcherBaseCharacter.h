// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ArcherBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UBaseWeaponComponent;


UCLASS()
class ARCHER_API AArcherBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AArcherBaseCharacter();

protected:
 #pragma region Component UProperties
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UBaseWeaponComponent* WeaponComponent;
#pragma endregion


	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Amount);
	
	void MoveRight(float Amount);

};

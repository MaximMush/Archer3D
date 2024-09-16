// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class ARCHER_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseWeapon();

	virtual void Fire();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* WeaponMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	FName ArrowSpawnSocketName = "ArrowSpawnSocket";
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	float TraceMaxDistance = 1500.0f; 

	virtual void BeginPlay() override;

	void MakeShot();
};

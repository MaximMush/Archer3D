// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponComponent.generated.h"

class ABaseWeapon;

UCLASS()
class ARCHER_API AWeaponComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeaponComponent();

	void Fire();

protected:
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<ABaseWeapon> WeaponClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName WeaponAttachPointName = "WeaponSocket";

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	ABaseWeapon* CurrentWeapon = nullptr;
	
	void SpawnWeapon();


};

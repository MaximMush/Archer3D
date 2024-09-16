// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseWeaponComponent.generated.h"

class ABaseWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCHER_API UBaseWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UBaseWeaponComponent();

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
// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/BaseWeaponComponent.h"
#include "Weapon/BaseWeapon.h"
#include "GameFramework/Character.h"

UBaseWeaponComponent::UBaseWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UBaseWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapon();
	
}

void UBaseWeaponComponent::SpawnWeapon()
{
	if (!GetWorld()) return;
	
	ACharacter* Character = Cast<ACharacter>(GetOwner());
		
	if(!Character) return;

	CurrentWeapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass);

	if (!CurrentWeapon) return;
		
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
		
	CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRules, WeaponAttachPointName);
	
	CurrentWeapon->SetOwner(Character);
}

void UBaseWeaponComponent::Fire()
{
	if(!CurrentWeapon) return;

	CurrentWeapon->Fire();
}


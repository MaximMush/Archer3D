// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WeaponComponent.h"
#include "Weapon/BaseWeapon.h"
#include "GameFramework/Character.h"


AWeaponComponent::AWeaponComponent()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
	
}
void AWeaponComponent::SpawnWeapon()
{
	if (!GetWorld()) return;
	
	ACharacter* Character = Cast<ACharacter>(GetOwner());
		
	if(!Character) return;

	CurrentWeapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass);

	if (!CurrentWeapon) return;
		
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
		
	CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRules, WeaponAttachPointName);
	
}

void AWeaponComponent::Fire()
{
	if(!CurrentWeapon) return;

	CurrentWeapon->Fire();
}